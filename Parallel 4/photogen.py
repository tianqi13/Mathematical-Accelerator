from PIL import Image

def swap_msb_lsb(b):
    # Extract the 4 MSBs (bits 4 to 7)
    msb = (b & 0xF0) >> 4
    # Extract the 4 LSBs (bits 0 to 3)
    lsb = b & 0x0F
    # Swap and combine them
    swapped_b = (lsb << 4) | msb
    return swapped_b

def read_exported_data(filename):
    data = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.split()
            if len(parts) == 3:
                RGB = parts[0]
                r = int(RGB[0:8], 2)  # 8 bits for red
                g = int(RGB[8:16], 2) # 8 bits for green
                b = int(RGB[16:24], 2) # 8 bits for blue
                #b = swap_msb_lsb(b)
                x = int(parts[1])
                y = int(parts[2])

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
data = read_exported_data('rgbtop_data.txt')

# Define image resolution based on the known maximum X and Y positions
image_width = 1028  # Max X position is 1027, so width should be 1028
image_height = 768  # Max Y position is 767, so height should be 768

# Generate and save the image
image = generate_image(data, image_width, image_height)
image.save('output_image.png')