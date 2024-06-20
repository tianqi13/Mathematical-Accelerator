import tkinter as tk
from tkinter import PhotoImage
from mandelbrot import MandelbrotImage


class ImageCanvas:
    def __init__(self, root, canvas, canvas_width, canvas_height):
        self.canvas = canvas
        self.image_id = None
        self.image = None

    def generate_image_on_canvas(self, colors, x, y):
        height = len(colors)
        width = len(colors[0]) if height > 0 else 0

        # Create a PhotoImage object with the given width and height
        self.image = PhotoImage(width=width, height=height)

        # Assign the colors from the array to the PhotoImage pixels
        for y_coord in range(height):
            for x_coord in range(width):
                color = colors[y_coord][x_coord]
                # Convert color tuple (R, G, B) to hex string
                color_hex = f'#{color[0]:02x}{color[1]:02x}{color[2]:02x}'
                self.image.put(color_hex, (x_coord, y_coord))

        # Add the PhotoImage to the canvas at the specified coordinates
        self.image_id = self.canvas.create_image(x, y, anchor=tk.NW, image=self.image)
    
    def remove_image_from_canvas(self):
        if self.image_id:
            self.canvas.delete(self.image_id)
            self.image_id = None


