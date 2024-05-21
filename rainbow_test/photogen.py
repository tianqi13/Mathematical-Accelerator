from PIL import Image

def read_exported_data(filename):
    data = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.split()
            if len(parts) == 5:
                r = int(parts[0])
                g = int(parts[1])
                b = int(parts[2])
                x = int(parts[3])
                y = int(parts[4])
                data.append((r, g, b, x, y))
    return data

def generate_image(data, image_width, image_height):
    # Create a blank image with white background
    image = Image.new('RGB', (image_width, image_height), color='white')
    pixels = image.load()

    # Map RGB values to image positions
    for r, g, b, x, y in data:
        if 0 <= x < image_width and 0 <= y < image_height:
            pixels[x, y] = (r, g, b)

    return image

# Read exported data
data = read_exported_data('rgbxy_data.txt')

# Define image resolution based on the maximum X and Y positions in your data
image_width = max([x for _, _, _, x, _ in data]) + 1
image_height = max([y for _, _, _, _, y in data]) + 1

# Generate and save the image
image = generate_image(data, image_width, image_height)
image.save('output_image.png')