from PIL import Image

# Function to read RGB values from a text file
def read_rgb_values(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    # Convert the hex values to tuples of integers
    rgb_values = [tuple(int(val, 16) for val in line.strip().split()) for line in lines if line.strip()]
    return rgb_values

# Read the RGB values from the text file
rgb_values = read_rgb_values('pics.txt')

# Define the width of the image
width = 1024
# Calculate the height based on the number of pixels and the defined width
height = (len(rgb_values) + width - 1) // width  # Ceiling division

# Create a new image with the appropriate size and mode
img = Image.new('RGB', (width, height))

# Pad rgb_values with black pixels if needed to fill the image dimensions
while len(rgb_values) < width * height:
    rgb_values.append((0, 0, 0))

# Set the pixel data for the image
img.putdata(rgb_values)

# Save the image to a file
img.save('output_image1.png')
