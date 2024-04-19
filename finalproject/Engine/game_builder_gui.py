import tkinter as tk
from tkinter import ttk, filedialog
from tkinter import messagebox
from pong import Pong
import mygameengine
from game import Game

PONG_PRESET = {
        "Game Name": "Pong!",
        "Creator": "Pong!",
        "Width": 800, 
        "Height": 800,  
        "Number of Players": 2,  
        "BackgroundRedValue": 0,  
        "BackgroundGreenValue": 0,
        "BackgroundBlueValue": 255,
        "BackgroundAlphaValue": 255,
        "Protagonist Height": 20, 
        "Protagonist Width": 20,  
        "Protagonist Speed": 40,  
        "Projectile Height": 10,  
        "Projectile Width": 10, 
        "Number of Projectiles": 5,  
        "Projectile Speed": 10      
}


def on_closing():
    print("Closing window!")
    # if messagebox.askokcancel("Quit", "Do you want to quit?"):
    root.destroy()

def load_game(values_dict):
    print("In load custom game")
    game_engine = mygameengine.SDLGraphicsProgram(int(values_dict["Width"]), int(values_dict["Height"]), values_dict["Game Name"])    
    custom_game = Game(game_engine, values_dict)
    custom_game.run_game()
    on_closing()


def create_game():
    global values_dict
    # Default values
    default_values = {
        "Game Name": "Game",
        "Creator": "You!",
        "Width": 800,  # Default width
        "Height": 800,  # Default height
        "Number of Players": 2,  # Default number of players
        "BackgroundRedValue": 255,  # Default background color values
        "BackgroundGreenValue": 255,
        "BackgroundBlueValue": 255,
        "BackgroundAlphaValue": 255,
        "Protagonist Height": 20,  # Default protagonist height
        "Protagonist Width": 20,  # Default protagonist width
        "Protagonist Speed": 5,  # Default protagonist speed
        "Projectile Height": 10,  # Default projectile height
        "Projectile Width": 10,  # Default projectile width
        "Number of Projectiles": 5,  # Default number of projectiles
        "Projectile Speed": 10  # Default projectile speed
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
    protagonist_height = protagonist_height_entry.get() if protagonist_height_entry.get() else default_values["Protagonist Height"]
    protagonist_width = protagonist_width_entry.get() if protagonist_width_entry.get() else default_values["Protagonist Width"]
    protagonist_speed = protagonist_speed_entry.get() if protagonist_speed_entry.get() else default_values["Protagonist Speed"]
    projectile_height = projectile_height_entry.get() if projectile_height_entry.get() else default_values["Projectile Height"]
    projectile_width = projectile_width_entry.get() if projectile_width_entry.get() else default_values["Projectile Width"]
    num_projectiles = num_projectiles_entry.get() if num_projectiles_entry.get() else default_values["Number of Projectiles"]
    projectile_speed = projectile_speed_entry.get() if projectile_speed_entry.get() else default_values["Projectile Speed"]

    # Convert data types
    width = int(width)
    height = int(height)
    num_players = int(num_players)
    bg_red = int(bg_red)
    bg_green = int(bg_green)
    bg_blue = int(bg_blue)
    bg_alpha = int(bg_alpha)
    protagonist_height = int(protagonist_height)
    protagonist_width = int(protagonist_width)
    protagonist_speed = int(protagonist_speed)
    projectile_height = int(projectile_height)
    projectile_width = int(projectile_width)
    num_projectiles = int(num_projectiles)
    projectile_speed = int(projectile_speed)

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
        "Protagonist Height": protagonist_height,
        "Protagonist Width": protagonist_width,
        "Protagonist Speed": protagonist_speed,
        "Projectile Height": projectile_height,
        "Projectile Width": projectile_width,
        "Number of Projectiles": num_projectiles,
        "Projectile Speed": projectile_speed
    }

    # Call the function with the values_dict
    load_game(values_dict)
    root.destroy()

def load_preset(game_name):
    if game_name == "Pong":
        # pong = Game(game_name, PONG_PRESET)
        # pong.run_game()
        load_game(PONG_PRESET)

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
tk.Label(root, text="Protagonist Height:").grid(row=9, column=0)
tk.Label(root, text="Protagonist Width:").grid(row=10, column=0)
tk.Label(root, text="Protagonist Speed:").grid(row=11, column=0)
tk.Label(root, text="Projectile Height:").grid(row=12, column=0)
tk.Label(root, text="Projectile Width:").grid(row=13, column=0)
tk.Label(root, text="Number of Projectiles:").grid(row=14, column=0)
tk.Label(root, text="Projectile Speed:").grid(row=15, column=0)

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
protagonist_height_entry = tk.Entry(root)
protagonist_width_entry = tk.Entry(root)
protagonist_speed_entry = tk.Entry(root)
projectile_height_entry = tk.Entry(root)
projectile_width_entry = tk.Entry(root)
num_projectiles_entry = tk.Entry(root)
projectile_speed_entry = tk.Entry(root)

game_name_entry.grid(row=0, column=1)
creator_entry.grid(row=1, column=1)
width_entry.grid(row=2, column=1)
height_entry.grid(row=3, column=1)
num_players_entry.grid(row=4, column=1)
bg_red_entry.grid(row=5, column=1)
bg_green_entry.grid(row=6, column=1)
bg_blue_entry.grid(row=7, column=1)
bg_alpha_entry.grid(row=8, column=1)
protagonist_height_entry.grid(row=9, column=1)
protagonist_width_entry.grid(row=10, column=1)
protagonist_speed_entry.grid(row=11, column=1)
projectile_height_entry.grid(row=12, column=1)
projectile_width_entry.grid(row=13, column=1)
num_projectiles_entry.grid(row=14, column=1)
projectile_speed_entry.grid(row=15, column=1)

# Load Preset Button
load_preset_button = tk.Button(root, text="Load Preset: Pong", command=lambda: load_preset("Pong"))
load_preset_button.grid(row=16, column=0, columnspan=2)

# Create Game Button
create_button = tk.Button(root, text="Create Game!", command=create_game)
create_button.grid(row=17, column=0, columnspan=2)

root.protocol("WM_DELETE_WINDOW", on_closing)
root.mainloop()

