import tkinter as tk
from tkinter import ttk, filedialog
from tkinter import messagebox
from pong import Pong
import mygameengine
from game import Game

def load_custom_game(values_dict):
    print("In load custom game")
    game_engine = mygameengine.SDLGraphicsProgram(int(values_dict["Width"]), int(values_dict["Height"]), values_dict["Game Name"])    
    custom_game = Game(game_engine, values_dict)
    custom_game.run_game()

def create_game():
    global values_dict
    # Default values
    default_values = {
        "Game Name": "Game",
        "Creator": "You!",
        "Width": "800",  # Default width
        "Height": "600",  # Default height
        "Number of Players": "2",  # Default number of players
        "BackgroundRedValue": "255",  # Default background color values
        "BackgroundGreenValue": "255",
        "BackgroundBlueValue": "255",
        "BackgroundAlphaValue": "255",
    }

    # Get values from entry fields
    game_name = game_name_entry.get() if game_name_entry.get() else default_values["Game Name"]
    creator = creator_entry.get() if creator_entry.get() else default_values["Creator"]
    width = width_entry.get() if width_entry.get() else default_values["Width"]
    height = height_entry.get() if height_entry.get() else default_values["Height"]
    num_players = num_players_entry.get() if num_players_entry.get() else default_values["Number of Players"]
    bg_red = bg_red_entry.get() if bg_red_entry.get() else default_values["BackgroundRedValue"]
    bg_green = bg_green_entry.get() if bg_green_entry.get() else default_values["BackgroundGreenValue"]
    bg_blue = bg_blue_entry.get() if bg_blue_entry.get() else default_values["BackgroundBlueValue"]
    bg_alpha = bg_alpha_entry.get() if bg_alpha_entry.get() else default_values["BackgroundAlphaValue"]

    # Convert data types
    width = int(width)
    height = int(height)
    num_players = int(num_players)
    bg_red = int(bg_red)
    bg_green = int(bg_green)
    bg_blue = int(bg_blue)
    bg_alpha = int(bg_alpha)

    # Construct values_dict
    values_dict = {
        "Game Name": game_name,
        "Creator": creator,
        "Width": width,
        "Height": height,
        "Number of Players": num_players,
        "BackgroundRedValue": bg_red,
        "BackgroundGreenValue": bg_green,
        "BackgroundBlueValue": bg_blue,
        "BackgroundAlphaValue": bg_alpha,
    }

    # Call the function with the values_dict
    load_custom_game(values_dict)
    root.destroy()

def load_preset(game_name):
    if game_name == "Pong":
        pong_game = Pong()
        pong_game.run_game()

 
root = tk.Tk()
root.title("Game Creator!")

# Labels
tk.Label(root, text="Game Name:").grid(row=0, column=0)
tk.Label(root, text="Creator:").grid(row=1, column=0)
tk.Label(root, text="Width:").grid(row=2, column=0)
tk.Label(root, text="Height:").grid(row=3, column=0)
tk.Label(root, text="Number of Players:").grid(row=4, column=0)
tk.Label(root, text="Background Red Value:").grid(row=5, column=0)
tk.Label(root, text="Background Green Value:").grid(row=6, column=0)
tk.Label(root, text="Background Blue Value:").grid(row=7, column=0)
tk.Label(root, text="Background Alpha Value:").grid(row=8, column=0)

# Entry fields
game_name_entry = tk.Entry(root)
creator_entry = tk.Entry(root)
width_entry = tk.Entry(root)
height_entry = tk.Entry(root)
num_players_entry = tk.Entry(root)
bg_red_entry = tk.Entry(root)
bg_green_entry = tk.Entry(root)
bg_blue_entry = tk.Entry(root)
bg_alpha_entry = tk.Entry(root)

game_name_entry.grid(row=0, column=1)
creator_entry.grid(row=1, column=1)
width_entry.grid(row=2, column=1)
height_entry.grid(row=3, column=1)
num_players_entry.grid(row=4, column=1)
bg_red_entry.grid(row=5, column=1)
bg_green_entry.grid(row=6, column=1)
bg_blue_entry.grid(row=7, column=1)
bg_alpha_entry.grid(row=8, column=1)

# Load Preset Button
load_preset_button = tk.Button(root, text="Load Preset: Pong", command=lambda: load_preset("Pong"))
load_preset_button.grid(row=9, column=0, columnspan=2)

# Create Game Button
create_button = tk.Button(root, text="Create Game!", command=create_game)
create_button.grid(row=10, column=0, columnspan=2)

root.mainloop()
