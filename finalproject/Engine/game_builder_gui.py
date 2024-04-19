import tkinter as tk
from tkinter import ttk, filedialog
from tkinter import messagebox
import mygameengine 
import random
from pong import Pong


# Dictionary to store values
values_dict = {}


## -------------------- SCRIPT ---------------------- ##

# Function to create game using the values dictionary
def create_game(values_dict):
    print("Values when entering create_game function: ", values_dict)

    game_name = values_dict.get('Game Name', 'GAME NAME') or 'GAME NAME'
    game_creator = values_dict.get('Game Creator', 'Default Game Creator')
    color = values_dict.get('Color', 'Default Color')


    # Validate and convert width
    width_str = values_dict.get('Width', '')  # Default width is '800'
    try:
        width = int(width_str)
    except ValueError:
        if not width_str:
            print("Empty width value. Using default.")
        else:
            print("Invalid width value. Using default.")
        width = 800


    # Validate and convert height
    height_str = values_dict.get('Height', '')  # Default height is '600'
    try:
        height = int(height_str)
    except ValueError:
        if not height_str:
            print("Empty height value. Using default.")
        else:
            print("Invalid height value. Using default.")
        height = 600


    # Validate and convert number of targets
    number_of_targets_str = values_dict.get('Number of Targets', '1')  # Default number of targets = 1
    if number_of_targets_str.isdigit():
        number_of_targets = int(number_of_targets_str)
    else:
        print("Invalid number of targets value. Using default.")
        number_of_targets = 10


    # Audio Genre validation
    audio = values_dict.get('Audio Genre', 'Action')  # Default audio genre is 'Action'
    valid_audio_genres = ["Action", "Adventure", "Horror", "Sci-Fi", "Fantasy", "Mystery"]
    if audio not in valid_audio_genres:
        print("Invalid audio genre. Using default.")
        audio = 'Action'

    # Protagonist Image validation
    protagonist = values_dict.get('Protagonist Image', 'protagonist1.png')  # Default protagonist image


    # Target Image validation
    target = values_dict.get('Target Image', 'target1.png')  # Default target image


    # Physics Setting validation
    physics = values_dict.get('Physics Setting', 'Classic')  # Default physics setting is 'Classic'
    valid_physics_settings = ["Classic", "Quantum", "Relativistic"]
    if physics not in valid_physics_settings:
        print("Invalid physics setting. Using default.")
        physics = 'Classic'

    # Collision Action validation
    collision = values_dict.get('Collision Action', 'Bounce')  # Default collision action is 'Bounce'
    valid_collision_actions = ["Bounce", "Explode", "Disappear"]
    if collision not in valid_collision_actions:
        print("Invalid collision action. Using default.")
        collision = 'Bounce'

    # Number of Levels validation
    number_of_levels_str = values_dict.get('Number of Levels', '1')  # Default number of levels = '1'
    if number_of_levels_str.isdigit():
        number_of_levels = int(number_of_levels_str)
    else:
        print("Invalid number of levels value. Using default.")
        number_of_levels = 1

    # Number of Projectiles validation
    number_of_projectiles_str = values_dict.get('Number of Projectiles', '3')  # Default number of projectiles = '3'
    if number_of_projectiles_str.isdigit():
        number_of_projectiles = int(number_of_projectiles_str)
    else:
        print("Invalid number of projectiles value. Using default.")
        number_of_projectiles = 50


# ## -------------------- Running the created game ---------------------- ##

    print("Before Create Game Pong: ", values_dict)
    pong_game = Pong(values_dict)
    pong_game.run_game()
    
    # quit = False

    # While running 
    # while not quit:

    #     gameEngine.poll()
    #     gameEngine.clear()
    #     # gameEngine.setBackgroundColor()

    #     # Delay for a short time
    #     gameEngine.delay(200)

    #     # Refresh the screen
    #     gameEngine.flip()

    #     # Check if game should quit
    #     quit = gameEngine.getQuit()

    # End of program  



    










 ## -------------------- Validating Dictionary Values ---------------------- ##

def retrieve_input_values(width_entry, height_entry, game_name_entry, game_creator_entry, color_entry, targets_entry,
                          audio_genre_var, protagonist_var, target_var, physics_var, collision_var, levels_entry,
                          projectiles_entry):
    
    width_value = validate_and_get_value(width_entry.get(), int, default=600)
    height_value = validate_and_get_value(height_entry.get(), int, default=600)
    
    # Validate width and height range
    if not (400 <= width_value <= 1000):
        print("Invalid width value. Using default.")
        width_value = 600
    
    if not (400 <= height_value <= 1000):
        print("Invalid height value. Using default.")
        height_value = 600
    
    values_dict['Width'] = width_value
    values_dict['Height'] = height_value
    values_dict['Game Name'] = game_name_entry.get()
    values_dict['Game Creator'] = game_creator_entry.get()
    values_dict['Color'] = color_entry.get()
    values_dict['Number of Targets'] = str(validate_and_get_value(targets_entry.get(), int, default=10))
    values_dict['Audio Genre'] = audio_genre_var.get()
    values_dict['Protagonist Image'] = protagonist_var.get()
    values_dict['Target Image'] = target_var.get()
    values_dict['Physics Setting'] = physics_var.get()
    values_dict['Collision Action'] = collision_var.get()
    values_dict['Number of Levels'] = str(validate_and_get_value(levels_entry.get(), int, default=1))
    values_dict['Number of Projectiles'] = str(validate_and_get_value(projectiles_entry.get(), int, default=1))

def validate_and_get_value(value, data_type, default):
    if isinstance(value, int):
        return value
    try:
        return data_type(value)
    except (ValueError, TypeError):
        print(f"Invalid value: {value}. Using default: {default}")
        return default






 ## -------------------- Game Creation GUI ---------------------- ##

def create_game_gui():
    # Create main window
    window = tk.Tk()
    window.title("Interactive Window")  # Set the title of the window

    # Create a frame for inputs
    input_frame = ttk.Frame(window, padding="20")
    input_frame.grid(row=0, column=0, padx=10, pady=10)

    # Game Name input
    game_name_label = ttk.Label(input_frame, text="Game Name:")
    game_name_label.grid(row=0, column=0, padx=5, pady=5, sticky="e")
    game_name_entry = ttk.Entry(input_frame)
    game_name_entry.grid(row=0, column=1, padx=5, pady=5)

    # Game Creator input
    game_creator_label = ttk.Label(input_frame, text="Game Creator:")
    game_creator_label.grid(row=1, column=0, padx=5, pady=5, sticky="e")
    game_creator_entry = ttk.Entry(input_frame)
    game_creator_entry.grid(row=1, column=1, padx=5, pady=5)

    # Color input
    color_label = ttk.Label(input_frame, text="Enter Color:")
    color_label.grid(row=2, column=0, padx=5, pady=5, sticky="e")
    color_entry = ttk.Entry(input_frame)
    color_entry.grid(row=2, column=1, padx=5, pady=5)

    # Size input
    size_label = ttk.Label(input_frame, text="Enter Size (Width x Height):")
    size_label.grid(row=3, column=0, padx=5, pady=5, sticky="e")
    width_label = ttk.Label(input_frame, text="Width:")
    width_label.grid(row=3, column=1, padx=5, pady=5, sticky="e")
    width_entry = ttk.Entry(input_frame)
    width_entry.grid(row=3, column=2, padx=5, pady=5)
    height_label = ttk.Label(input_frame, text="Height:")
    height_label.grid(row=3, column=3, padx=5, pady=5, sticky="e")
    height_entry = ttk.Entry(input_frame)
    height_entry.grid(row=3, column=4, padx=5, pady=5)

    # Number of targets input
    targets_label = ttk.Label(input_frame, text="Number of Targets:")
    targets_label.grid(row=4, column=0, padx=5, pady=5, sticky="e")
    targets_entry = ttk.Entry(input_frame)
    targets_entry.grid(row=4, column=1, padx=5, pady=5)

    # Audio Genre dropdown
    audio_genre_label = ttk.Label(input_frame, text="Audio Genre:")
    audio_genre_label.grid(row=5, column=0, padx=5, pady=5, sticky="e")
    audio_genre_var = tk.StringVar()
    audio_genre_dropdown = ttk.Combobox(input_frame, textvariable=audio_genre_var,
                                        values=["Action", "Adventure", "Horror", "Sci-Fi", "Fantasy", "Mystery"])
    audio_genre_dropdown.grid(row=5, column=1, padx=5, pady=5)

    # Protagonist Image dropdown
    protagonist_label = ttk.Label(input_frame, text="Select Protagonist Image:")
    protagonist_label.grid(row=6, column=0, padx=5, pady=5, sticky="e")
    protagonist_var = tk.StringVar()
    protagonist_dropdown = ttk.Combobox(input_frame, textvariable=protagonist_var,
                                        values=["protagonist1.png", "protagonist2.png", "protagonist3.png"])
    protagonist_dropdown.grid(row=6, column=1, padx=5, pady=5)

    # Target Image dropdown
    target_label = ttk.Label(input_frame, text="Select Target Image:")
    target_label.grid(row=7, column=0, padx=5, pady=5, sticky="e")
    target_var = tk.StringVar()
    target_dropdown = ttk.Combobox(input_frame, textvariable=target_var,
                                    values=["target1.png", "target2.png", "target3.png"])
    target_dropdown.grid(row=7, column=1, padx=5, pady=5)

    # Physics settings dropdown
    physics_label = ttk.Label(input_frame, text="Physics Setting:")
    physics_label.grid(row=8, column=0, padx=5, pady=5, sticky="e")
    physics_var = tk.StringVar()
    physics_dropdown = ttk.Combobox(input_frame, textvariable=physics_var,
                                    values=["Classic", "Quantum", "Relativistic"])
    physics_dropdown.grid(row=8, column=1, padx=5, pady=5)

    # Collision action dropdown
    collision_label = ttk.Label(input_frame, text="Collision Action:")
    collision_label.grid(row=9, column=0, padx=5, pady=5, sticky="e")
    collision_var = tk.StringVar()
    collision_dropdown = ttk.Combobox(input_frame, textvariable=collision_var,
                                        values=["Bounce", "Explode", "Disappear"])
    collision_dropdown.grid(row=9, column=1, padx=5, pady=5)

    # Number of levels input
    levels_label = ttk.Label(input_frame, text="Number of Levels:")
    levels_label.grid(row=10, column=0, padx=5, pady=5, sticky="e")
    levels_entry = ttk.Entry(input_frame)
    levels_entry.grid(row=10, column=1, padx=5, pady=5)

    # Number of projectiles input
    projectiles_label = ttk.Label(input_frame, text="Number of Projectiles:")
    projectiles_label.grid(row=11, column=0, padx=5, pady=5, sticky="e")
    projectiles_entry = ttk.Entry(input_frame)
    projectiles_entry.grid(row=11, column=1, padx=5, pady=5)

    # Create Game button calls retrieve_input_values and then create_game
    create_game_button = ttk.Button(window, text="Create Game", command=lambda: (
    retrieve_input_values(width_entry, height_entry, game_name_entry, game_creator_entry, color_entry, targets_entry,
                          audio_genre_var, protagonist_var, target_var, physics_var, collision_var, levels_entry,
                          projectiles_entry),

    create_game(values_dict)))
    create_game_button.grid(row=12, column=0, padx=10, pady=10, sticky="e")

    # Configure row and column weights for resizing
    window.rowconfigure(0, weight=1)
    window.columnconfigure(0, weight=1)

    # Run the application
    window.mainloop()









def load_preset_game(preset):
    # Logic to load a preset game
    if preset == "Pong":
        print("In load preset pong: ", values_dict)
        pong_game = Pong(values_dict)
        pong_game.run_game()







def open_game_window():
    # Create the main window
    main_window = tk.Tk()
    main_window.title("Game Selection")

    # Function to handle the "Create Game" button click event
    def create_game_selected():
        main_window.destroy()
        create_game_gui()

    # Function to handle the "Load Preset Game" button click event
    def load_preset_selected(gameName):
        # preset = preset_var.get()
        main_window.destroy()
        load_preset_game(gameName)

    # Frame for options
    options_frame = ttk.Frame(main_window, padding="20")
    options_frame.grid(row=0, column=0, padx=10, pady=10)

    # Create a label for instructions
    instructions_label = ttk.Label(options_frame, text="Choose an option:")
    instructions_label.grid(row=0, column=0, padx=5, pady=5)

    # Create "Create Game" button
    create_game_button = ttk.Button(options_frame, text="Create a new game", command=create_game_selected)
    create_game_button.grid(row=1, column=0, padx=5, pady=5)

    # Create a button for loading the "Pong" preset game
    load_pong_button = ttk.Button(options_frame, text="Load Pong Game", command=lambda: load_preset_selected("Pong"))
    load_pong_button.grid(row=2, column=0, padx=5, pady=5)

    # Run the main window
    main_window.mainloop()

open_game_window()
