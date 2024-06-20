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

    return (mapped_top_left_x, mapped_top_left_y), (mapped_bottom_right_x, mapped_bottom_right_y)

# Example usage:
image_size = (1280, 960)
region = (-2.0, 1.0, -1.5, 1.5)
top_left = (100, 150)
bottom_right = (400, 300)
print(map_to_plane(image_size, region, top_left, bottom_right)) # Expected output: ((0.0, 0.0), (800.0, 800.0))