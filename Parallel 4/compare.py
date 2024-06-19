def compare_files(file1_path, file2_path, output_path):
    with open(file1_path, 'r') as file1, open(file2_path, 'r') as file2:
        file1_lines = file1.readlines()
        file2_lines = file2.readlines()
        
    max_lines = max(len(file1_lines), len(file2_lines))
    
    with open(output_path, 'w') as output_file:
        for i in range(max_lines):
            try:
                line1 = file1_lines[i].strip()
            except IndexError:
                line1 = "EOF"
            
            try:
                line2 = file2_lines[i].strip()
            except IndexError:
                line2 = "EOF"
            
            if line1 != line2:
                output_file.write(f"Row {i+1} doesn't match:\n")
                output_file.write(f"File 1: {line1}\n")
                output_file.write(f"File 2: {line2}\n")
                output_file.write("\n")

# Example usage
file1_path = 'f1.txt'
file2_path = 'pixel_data.txt'
output_path = 'differences.txt'
compare_files(file1_path, file2_path, output_path)
