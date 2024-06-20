import numpy as np
from PIL import Image

class MandelbrotImage:
    def __init__(self, width, height, max_iter):
        self.width = width
        self.height = height
        self.max_iter = max_iter
        self.image = np.zeros((height, width), dtype=int)

    def mandelbrot(self, x, y):
        c = complex(x, y)
        z = 0
        n = 0
        while abs(z) <= 2 and n < self.max_iter:
            z = z*z + c
            n += 1
        return n

    def generate(self, x1, x2, y1, y2):
        for y in range(self.height):
            for x in range(self.width):
                self.image[y, x] = self.mandelbrot(
                    x1 + (x2 - x1) * x / self.width,
                    y1 + (y2 - y1) * y / self.height
                )

    def map_to_color(self):
        colors = np.zeros((self.height, self.width, 3), dtype=np.uint8)
        for y in range(self.height):
            for x in range(self.width):
                iter_count = self.image[y, x]
                color_value = 255 - int(iter_count * 255 / self.max_iter)
                colors[y, x] = (color_value, color_value, color_value)
        return colors

    def save_image(self, filename):
        colors = self.map_to_color()
        img = Image.fromarray(colors, 'RGB')
        img.save(filename)

# Parameters for the Mandelbrot set
#width, height = 800, 800
#max_iter = 255
#
#x1, x2 = -2.0, 1.0
#y1, y2 = -1.5, 1.5
#
## Generate and save the Mandelbrot image
#mandelbrot_image = MandelbrotImage(width, height, max_iter)
#mandelbrot_image.generate(x1, x2, y1, y2)
#mandelbrot_image.save_image("mandelbrot.png")

# Display the image
#import matplotlib.pyplot as plt
#img = plt.imread("mandelbrot.png")
#plt.imshow(img)
#plt.axis('off')
#plt.show()
