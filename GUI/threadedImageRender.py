import tkinter as tk
import threading
from pynq import Overlay
from pynq import allocate

def map_to_plane(image_size, region, top_left, bottom_right):
    width, height = image_size
    x_min, x_max, y_min, y_max = region

    def map_coordinate(coord, axis_min, axis_max, axis_length):
        return axis_min + (axis_max - axis_min) * coord / axis_length

    top_left_x, top_left_y = top_left
    bottom_right_x, bottom_right_y = bottom_right

    mapped_top_left_x = map_coordinate(top_left_x, x_min, x_max, width)
    mapped_top_left_y = map_coordinate(top_left_y, y_min, y_max, height)
    mapped_bottom_right_x = map_coordinate(bottom_right_x, x_min, x_max, width)
    mapped_bottom_right_y = map_coordinate(bottom_right_y, y_min, y_max, height)

    return (mapped_top_left_x, mapped_bottom_right_x, mapped_top_left_y, mapped_bottom_right_y)

class Frame:
    def __init__(self, width, height, x1=0, y1=0):
        self.width = width
        self.height = height
        self.x1 = x1
        self.y1 = y1
        self.x2 = x1 + width
        self.y2 = y1 + height  

    def render(self):
        print(self.x1, self.y1, self.x2, self.y2)

class Display:
    def __init__(self, width, height, s=10, t=15):
        self.frame = Frame(width, height)
        self.bound = Frame(width - s * t, height - s * t)
        self.s = 10
        self.t = t

class Render:
    def __init__(self, display=Display(1280, 960), image=Frame(640, 480), x=0, y=0):
        self.display = display
        self.image = image
        self.new_display = None
        self.transitioning = False
        self.timer = 0
        self.image_x = x
        self.image_y = y
        self.in_collision = False
        self.overlay = Overlay("path/to/your/overlay.bit")

    def render(self):
        self.root = tk.Tk()
        self.root.title("Render Display")
        window_width = self.display.frame.width * 2
        window_height = self.display.frame.height * 2
        self.canvas = tk.Canvas(self.root, width=window_width, height=window_height)
        self.canvas.pack()
        self.display.frame.x1 = (window_width - self.display.frame.width) // 2
        self.display.frame.y1 = (window_height - self.display.frame.height) // 2
        self.display.frame.x2 = self.display.frame.x1 + self.display.frame.width
        self.display.frame.y2 = self.display.frame.y1 + self.display.frame.height
        self.display_rect = self.canvas.create_rectangle(
            self.display.frame.x1, self.display.frame.y1,
            self.display.frame.x2, self.display.frame.y2,
            outline="black",
            tags="rect"
        )
        self.image_canvas = ImageCanvas(self.root, self.canvas, self.display.frame.width, self.display.frame.height)
        coords = map_to_plane((1280, 960), (-2.0, 1.0, -1.5, 1.5), (self.display.frame.x1, self.display.frame.y1), (self.display.frame.x2, self.display.frame.y2))
        colors = self.calculate_mandelbrot_on_fpga(self.display.frame.width, self.display.frame.height, coords)
        self.image_canvas.generate_image_on_canvas(colors, self.display.frame.x1, self.display.frame.y1)
        selfvivavi.image.x1 = self.display.frame.x1 + (self.display.frame.width - self.image.width) // 2
        self.image.y1 = self.display.frame.y1 + (self.display.frame.height - self.image.height) // 2
        self.image.x2 = self.image.x1 + self.image.width
        self.image.y2 = self.image.y1 + self.image.height
        self.image_rect = self.canvas.create_rectangle(
            self.image.x1, self.image.y1,
            self.image.x2, self.image.y2,
            outline="red",
            tags="rect"
        )
        self.display.bound.x1 = self.display.frame.x1 + (self.display.frame.width - self.display.bound.width) // 2
        self.display.bound.y1 = self.display.frame.y1 + (self.display.frame.height - self.display.bound.height) // 2
        self.display.bound.x2 = self.display.bound.x1 + self.display.bound.width
        self.display.bound.y2 = self.display.bound.y1 + self.display.bound.height
        self.bound_rect = self.canvas.create_rectangle(
            self.display.bound.x1, self.display.bound.y1,
            self.display.bound.x2, self.display.bound.y2,
            outline="blue",
            tags="rect"
        )
        self.root.bind("<Up>", self.move_up)
        self.root.bind("<Down>", self.move_down)
        self.root.bind("<Left>", self.move_left)
        self.root.bind("<Right>", self.move_right)
        self.root.bind("<Shift_L>", self.enlarge_image)
        self.root.bind("<Return>", self.shrink_image)
        self.update_timer()
        self.root.mainloop()

    def move_up(self, event):
        if self.image.y1 > self.display.frame.y1:
            self.image.y1 -= 10
            self.update_image()
            self.check_collision()

    def move_down(self, event):
        if self.image.y2 < self.display.frame.y2:
            self.image.y1 += 10
            self.update_image()
            self.check_collision()

    def move_left(self, event):
        if self.image.x1 > self.display.frame.x1:
            self.image.x1 -= 10
            self.update_image()
            self.check_collision()

    def move_right(self, event):
        if self.image.x2 < self.display.frame.x2:
            self.image.x1 += 10
            self.update_image()
            self.check_collision()

    def enlarge_image(self, event):
        self.image.width += 20
        self.image.height += 15
        self.image.x1 -= 10
        self.image.y1 -= 7.5
        self.update_image()
        self.check_collision()

    def shrink_image(self, event):
        if self.image.width > 20 and self.image.height > 20:
            self.image.width -= 20
            self.image.height -= 15
            self.image.x1 += 10
            self.image.y1 += 7.5
            self.update_image()
            self.create_new_display()

    def update_image(self):
        self.image.x2 = self.image.x1 + self.image.width
        self.image.y2 = self.image.y1 + self.image.height
        self.canvas.tag_raise("rect")
        self.canvas.coords(
            self.image_rect,
            self.image.x1, self.image.y1,
            self.image.x2, self.image.y2
        )

    def check_collision(self):
        if (self.image.x1 > self.display.bound.x1 and 
            self.image.x2 < self.display.bound.x2 and 
            self.image.y1 > self.display.bound.y1 and 
            self.image.y2 < self.display.bound.y2):
            if self.in_collision:
                print("Collision resolved!")
            self.in_collision = False
        else:
            if not self.in_collision:
                print("Collision detected!")
                self.in_collision = True
                self.create_new_display()

    def create_new_display(self):
        if self.transitioning:
            return
        image_center_x = self.image.x1 + self.image.width // 2
        image_center_y = self.image.y1 + self.image.height // 2
        self.new_display_width = self.image.width * 2
        self.new_display_height = self.image.height * 2
        self.new_display_x = image_center_x - self.new_display_width // 2
        self.new_display_y = image_center_y - self.new_display_height // 2
        self.new_display_rect = self.canvas.create_rectangle(
            self.new_display_x, self.new_display_y,
            self.new_display_x + self.new_display_width, self.new_display_y + self.new_display_height,
            outline="black",
            tags="rect"
        )
        self.new_bound_width = self.new_display_width - self.display.s * self.display.t
        self.new_bound_height = self.new_display_height - self.display.s * self.display.t
        self.new_bound_x = self.new_display_x + (self.new_display_width - self.new_bound_width) // 2
        self.new_bound_y = self.new_display_y + (self.new_display_height - self.new_bound_height) // 2
        self.new_bound_rect = self.canvas.create_rectangle(
            self.new_bound_x, self.new_bound_y,
            self.new_bound_x + self.new_bound_width, self.new_bound_y + self.new_bound_height,
            outline="blue",
            tags="rect"
        )
        self.transitioning = True
        self.image_canvas.remove_image_from_canvas()
        threading.Thread(target=self.compute_new_mandelbrot_image).start()

    def compute_new_mandelbrot_image(self):
        new_image_canvas = ImageCanvas(self.root, self.canvas, self.new_display_width, self.new_display_height)
        coords = map_to_plane((1280, 960), (-2.0, 1.0, -1.5, 1.5), (self.new_display_x, self.new_display_y), (self.new_display_x + self.new_display_width, self.new_display_y + self.new_display_height))
        colors = self.calculate_mandelbrot_on_fpga(self.new_display_width, self.new_display_height, coords)
        self.root.after(0, lambda: self.update_display_with_new_image(new_image_canvas, colors))

    def calculate_mandelbrot_on_fpga(self, width, height, coords):
        # This is a placeholder for the actual FPGA computation.
        # You will need to interact with the FPGA using the PYNQ library.
        x_min, x_max, y_min, y_max = coords

        # Allocate memory for input and output buffers
        input_buffer = allocate(shape=(width, height), dtype='float32')
        output_buffer = allocate(shape=(width, height), dtype='uint32')

        # Fill the input buffer with necessary data
        # This will vary depending on your FPGA design
        # input_buffer[:] = ...

        # Load the overlay and start the computation
        self.overlay = Overlay("path/to/your/overlay.bit")
        mandelbrot_ip = self.overlay.mandelbrot
        mandelbrot_ip.write(0x10, x_min)
        mandelbrot_ip.write(0x18, x_max)
        mandelbrot_ip.write(0x20, y_min)
        mandelbrot_ip.write(0x28, y_max)
        mandelbrot_ip.write(0x30, input_buffer.device_address)
        mandelbrot_ip.write(0x38, output_buffer.device_address)
        mandelbrot_ip.write(0x00, 0x01)  # Start the IP

        # Wait for the computation to complete
        while mandelbrot_ip.read(0x00) & 0x4 == 0:
            continue

        # Retrieve the output data
        colors = output_buffer.copy()

        return colors

    def update_display_with_new_image(self, new_image_canvas, colors):
        self.canvas.delete(self.display_rect)
        self.canvas.delete(self.bound_rect)
        self.image_canvas.remove_image_from_canvas()
        self.image_canvas = new_image_canvas
        self.display.frame.x1 = self.new_display_x
        self.display.frame.y1 = self.new_display_y
        self.display.frame.width = self.new_display_width
        self.display.frame.height = self.new_display_height
        self.image_canvas.generate_image_on_canvas
        self.image_canvas.generate_image_on_canvas(colors, self.display.frame.x1, self.display.frame.y1)
        self.display.bound.x1 = self.new_bound_x
        self.display.bound.y1 = self.new_bound_y
        self.display.bound.width = self.new_bound_width
        self.display.bound.height = self.new_bound_height
        self.display_rect = self.new_display_rect
        self.bound_rect = self.new_bound_rect
        self.update_image()
        self.in_collision = False
        self.transitioning = False

    def update_timer(self):
        if self.in_collision:
            self.timer += 1
        else:
            self.timer = 0
        self.canvas.after(1, self.update_timer)

# Create Frame instances for display and image
myDisplay = Display(640, 480)
myImage = Frame(320, 240)

# Create a Render instance and render the display
myRender = Render(display=myDisplay, image=myImage, x=0, y=0)
myRender.render()
