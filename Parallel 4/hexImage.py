from PIL import Image

def hex_to_rgb(hex_str):
    """Convert a hex string in the format 'xx xx xx' to an RGB tuple."""
    hex_values = hex_str.split()
    if len(hex_values) != 3:
        raise ValueError(f"Invalid hex string: {hex_str}")
    return tuple(int(h, 16) for h in hex_values)

def generate_image_from_file(file_path, image_width, image_height):
    """Generate an image from a text file containing RGB hex values."""
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Create a new image with the specified width and height
    image = Image.new('RGB', (image_width, image_height))
    pixels = image.load()

    # Make sure we have enough lines to fill the image
    if len(lines) < image_width * image_height:
        raise ValueError("Not enough data to fill the image")

    # Populate the image with the RGB values from the file
    for y in range(image_height):
        for x in range(image_width):
            line_index = y * image_width + x
            rgb = hex_to_rgb(lines[line_index].strip())
            pixels[x, y] = (rgb[0], rgb[1], rgb[2])  # Ensure it is a tuple of three elements

    return image

# Configuration
file_path = 'unpacked_data.txt'  # Replace with the path to your text file
image_width = 1024
image_height = 768

# Generate the image
image = generate_image_from_file(file_path, image_width, image_height)

# Save the image
image.save('output_image.png')
print("Image saved as output_image.png")
