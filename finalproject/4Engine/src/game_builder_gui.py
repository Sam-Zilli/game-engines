import tkinter as tk
from tkinter import ttk
import mygameengine

# Define default values for empty inputs
DEFAULT_GAME_NAME = "GAME NAME!"
DEFAULT_WINDOW_WIDTH = 600
DEFAULT_WINDOW_HEIGHT = 480
DEFAULT_PROJECTILE_SPEED = 200
DEFAULT_RED = 0
DEFAULT_GREEN = 0
DEFAULT_BLUE = 0

def run_game():
    """
    Runs the game with the specified parameters.

    Retrieves values from the GUI, validates them, and creates an instance of the Application class.
    Then calls the Loop method of the Application instance.

    Returns:
        None
    """
    # Extract values from the GUI and handle empty inputs
    game_name = game_name_entry.get()
    window_width_str = window_width_entry.get()
    window_height_str = window_height_entry.get()
    speed_of_projectile_str = speed_of_projectile_entry.get()
    red_str = red_entry.get()
    green_str = green_entry.get()
    blue_str = blue_entry.get()

    # Validate and convert values
    window_width = int(window_width_str) if window_width_str else DEFAULT_WINDOW_WIDTH
    window_height = int(window_height_str) if window_height_str else DEFAULT_WINDOW_HEIGHT
    speed_of_projectile = int(speed_of_projectile_str) if speed_of_projectile_str else DEFAULT_PROJECTILE_SPEED
    red = int(red_str) if red_str else DEFAULT_RED
    green = int(green_str) if green_str else DEFAULT_GREEN
    blue = int(blue_str) if blue_str else DEFAULT_BLUE


    # Validate red, green, and blue values
    if not (0 <= red <= 255) or not (0 <= green <= 255) or not (0 <= blue <= 255):
        error_label.config(text="Red, green, and blue values must be between 0 and 255")
        return

    # Validate window size constraints
    if not (480 <= window_width <= 2000) or not (480 <= window_height <= 2000):
        error_label.config(text="Window size must be between 600 and 2000")
        return

    # Validate game name length constraints
    if len(game_name) < 3 or len(game_name) > 20:
        error_label.config(text="Game name must be between 3 and 20 characters")
        return

    # Validate projectile speed constraints
    if not (20 <= speed_of_projectile <= 700):
        error_label.config(text="Projectile speed must be between 20 and 700")
        return


    values_dict = {
        "game_name": game_name,
        "window_width": str(window_width),
        "window_height": str(window_height),
        "speed_of_projectile": str(speed_of_projectile),
    }

    # Create an instance of Application
    app = mygameengine.Application(values_dict)

    # Call the Loop method
    app.Loop(loop_duration, red, green, blue)
    root.destroy()

# Create the main GUI window
root = tk.Tk()
root.title("Game Configuration")

# Define GUI elements
tk.Label(root, text="Game Name").grid(row=0, column=0)
game_name_entry = tk.Entry(root)
game_name_entry.grid(row=0, column=1)
game_name_entry.insert(0, str(DEFAULT_GAME_NAME))  # Insert default value

tk.Label(root, text="Window Width").grid(row=1, column=0)
window_width_entry = tk.Entry(root)
window_width_entry.grid(row=1, column=1)
window_width_entry.insert(0, str(DEFAULT_WINDOW_WIDTH))  # Insert default value

tk.Label(root, text="Window Height").grid(row=2, column=0)
window_height_entry = tk.Entry(root)
window_height_entry.grid(row=2, column=1)
window_height_entry.insert(0, str(DEFAULT_WINDOW_HEIGHT))  # Insert default value

tk.Label(root, text="Projectile Speed").grid(row=3, column=0)
speed_of_projectile_entry = tk.Entry(root)
speed_of_projectile_entry.grid(row=3, column=1)
speed_of_projectile_entry.insert(0, str(DEFAULT_PROJECTILE_SPEED))  # Insert default value

# Entry fields for red, green, and blue values
tk.Label(root, text="Red").grid(row=4, column=0)
red_entry = tk.Entry(root)
red_entry.grid(row=4, column=1)
red_entry.insert(0, str(DEFAULT_RED))  # Insert default value

tk.Label(root, text="Green").grid(row=5, column=0)
green_entry = tk.Entry(root)
green_entry.grid(row=5, column=1)
green_entry.insert(0, str(DEFAULT_GREEN))  # Insert default value

tk.Label(root, text="Blue").grid(row=6, column=0)
blue_entry = tk.Entry(root)
blue_entry.grid(row=6, column=1)
blue_entry.insert(0, str(DEFAULT_BLUE))  # Insert default value

# Error label for displaying validation errors
error_label = tk.Label(root, fg="red")
error_label.grid(row=8, column=0, columnspan=2)

# Add a button to start the game
start_button = ttk.Button(root, text="Start Game", command=run_game)
start_button.grid(row=9, column=0, columnspan=2)

# Set loop duration
loop_duration = 120.0

# Run the GUI
root.mainloop()
