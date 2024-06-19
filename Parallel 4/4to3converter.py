import re

def decode_packed_data(input_file, output_file):
    with open(input_file, 'r') as infile:
        lines = infile.readlines()

    output_data = []
    state = 0
    last_r, last_g, last_b = 0, 0, 0

    for line in lines:
        # Split the line into binary and integer parts using regular expressions
        binary_data, int_part = re.split(r'\s{2,}', line.strip(), maxsplit=1)
        # Convert binary data to integer
        packed_data = int(binary_data, 2)
        b3, b2, b1, b0 = (packed_data >> 24) & 0xFF, (packed_data >> 16) & 0xFF, (packed_data >> 8) & 0xFF, packed_data & 0xFF

        if state == 0:
            last_g = b3
            output_data.append((b2, b1, b0)) 
        elif state == 1:
            output_data.append((b1, b0, last_g))
            last_b = b3
            last_g = b2
        elif state == 2:
            output_data.append((b0, last_b, last_g))
            output_data.append((b3, b2, b1))

        state = (state + 1) % 3

    with open(output_file, 'w') as outfile:
        for r, b, g in output_data:
            outfile.write(f'{r:02X} {b:02X} {g:02X}\n')

# Usage
input_file = 'pixel_data.txt' #'frame2.txt'
output_file = 'pics.txt'
decode_packed_data(input_file, output_file)
