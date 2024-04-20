import tkinter as tk
from tkinter import ttk
import mygameengine

def run_game():
    # Extract values from the GUI
    game_name = game_name_entry.get()
    window_width = int(window_width_entry.get())
    window_height = int(window_height_entry.get())
    speed_of_projectile = int(speed_of_projectile_entry.get())
    
    # Validate window size constraints
    if window_width < 600 or window_width > 2000 or window_height < 600 or window_height > 2000:
        error_label.config(text="Window size must be between 600 and 2000")
        return
    
    # Validate game name length constraints
    if len(game_name) < 3 or len(game_name) > 20:
        error_label.config(text="Game name must be between 3 and 20 characters")
        return
    
    # Validate projectile speed constraints
    if speed_of_projectile < 20 or speed_of_projectile > 700:
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
    app.Loop(loop_duration)

# Create the main GUI window
root = tk.Tk()
root.title("Game Configuration")

# Define GUI elements
tk.Label(root, text="Game Name").grid(row=0, column=0)
game_name_entry = tk.Entry(root)
game_name_entry.grid(row=0, column=1)

tk.Label(root, text="Window Width").grid(row=1, column=0)
window_width_entry = tk.Entry(root)
window_width_entry.grid(row=1, column=1)

tk.Label(root, text="Window Height").grid(row=2, column=0)
window_height_entry = tk.Entry(root)
window_height_entry.grid(row=2, column=1)

tk.Label(root, text="Projectile Speed").grid(row=3, column=0)
speed_of_projectile_entry = tk.Entry(root)
speed_of_projectile_entry.grid(row=3, column=1)

# Error label for displaying validation errors
error_label = tk.Label(root, fg="red")
error_label.grid(row=4, column=0, columnspan=2)

# Add a button to start the game
start_button = ttk.Button(root, text="Start Game", command=run_game)
start_button.grid(row=5, column=0, columnspan=2)

# Set loop duration
loop_duration = 120.0

# Run the GUI
root.mainloop()
