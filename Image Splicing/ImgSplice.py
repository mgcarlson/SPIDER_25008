from PIL import Image

def split_image(image_path, output_folder):
    # Open the image
    img = Image.open(image_path)
    
    # Get dimensions
    img_width, img_height = img.size
    grid_size = 3  # 4x4 grid
    
    # Calculate the width and height of each piece
    tile_width = img_width // grid_size
    tile_height = img_height // grid_size

    # Loop through grid and save each section
    for row in range(grid_size):
        for col in range(grid_size):
            left = col * tile_width
            upper = row * tile_height
            right = left + tile_width
            lower = upper + tile_height

            # Crop image
            cropped_img = img.crop((left, upper, right, lower))
            
            # Save the cropped image
            output_filename = f"{output_folder}/tile_{row}_{col}.jpg"
            cropped_img.save(output_filename, "JPEG")

    print(f"Image successfully split into {grid_size * grid_size} pieces.")

# Example usage
split_image("Grass.jpeg", "Output")
