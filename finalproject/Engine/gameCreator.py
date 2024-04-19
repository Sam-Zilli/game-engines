import mygameengine
from background import Background
from protagonist import Protagonist
from projectile import Projectile
from pong import Pong
import random


class GameCreator:
    def __init__(self):
        self.name = "Game Creator!"

    def create_game(self, values_dict):
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


        print("Values aquired. Now time for game loop!")
        print("Values Dict: ", values_dict)
        # print("Before Create Game Pong: ", self.values_dict)
        pong_game = Pong({})
        pong_game.run_game()
