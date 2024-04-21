import tkinter as tk
from tkinter import ttk
import mygameengine

## @var DEFAULT_GAME_NAME
#  @brief Default name for the game
DEFAULT_GAME_NAME = "GAME NAME!"

## @var DEFAULT_WINDOW_WIDTH
#  @brief Default width for the game window
DEFAULT_WINDOW_WIDTH =  "600"

## @var DEFAULT_WINDOW_HEIGHT
#  @brief Default height for the game window
DEFAULT_WINDOW_HEIGHT = "1000"

## @var DEFAULT_PROJECTILE_SPEED
#  @brief Default speed for the game projectiles
DEFAULT_PROJECTILE_SPEED = "200"

## @var DEFAULT_RED
#  @brief Default red color value
DEFAULT_RED = "0"

## @var DEFAULT_GREEN
#  @brief Default green color value
DEFAULT_GREEN = "0"

## @var DEFAULT_BLUE
#  @brief Default blue color value
DEFAULT_BLUE = "0"

## @fn run_game()
#  @brief Runs the game with the specified parameters.
#  @details Retrieves values from the GUI, validates them, and creates an instance of the Application class.
#  Then calls the Loop method of the Application instance.
#  @return None
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
    speed_of_projectile_str = speed_of_projectile_entry.get()
    red_str = red_entry.get()
    green_str = green_entry.get()
    blue_str = blue_entry.get()

    # Validate and convert values
    speed_of_projectile = int(speed_of_projectile_str) if speed_of_projectile_str else DEFAULT_PROJECTILE_SPEED
    red = int(red_str) if red_str else DEFAULT_RED
    green = int(green_str) if green_str else DEFAULT_GREEN
    blue = int(blue_str) if blue_str else DEFAULT_BLUE


    # Validate red, green, and blue values
    if not (0 <= red <= 255) or not (0 <= green <= 255) or not (0 <= blue <= 255):
        error_label.config(text="Red, green, and blue values must be between 0 and 255")
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
        "window_width": DEFAULT_WINDOW_WIDTH,
        "window_height": DEFAULT_WINDOW_HEIGHT,
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
