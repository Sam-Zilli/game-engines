import mygameengine
from background import Background
from protagonist import Protagonist
from projectile import Projectile
import random

class Game:
    def __init__(self, values_dict):
        self.values_dict = values_dict
        self.game_engine = mygameengine.GameApp() # game is run on this engine (bindings.cpp)
        self.quit = False
        self.backgroundRed = values_dict["BackgroundRedValue"]
        self.backgroundGreen = values_dict["BackgroundGreenValue"]
        self.backgroundBlue = values_dict["BackgroundBlueValue"]
        self.backgroundAlpha = values_dict["BackgroundAlphaValue"]
        self.color_map = {
            'red': (255, 0, 0, 255),
            'green': (0, 255, 0, 255),
            'blue': (0, 0, 255, 255),
            'yellow': (255, 255, 0, 255),
            'pink': (255, 0, 255, 255),
            'white': (255, 255, 255, 255),
            'black': (0, 0, 0, 255),
            'gray': (128, 128, 128, 255),
        }        
        self.two_player_game = self.values_dict["Number of Players"] == 2

        # self.background = Background(0, self.color_map)
        # self.player_one = Protagonist(0, int((self.values_dict["Height"]/2)-self.values_dict["Protagonist Height"]),self.values_dict["Protagonist Width"], self.values_dict["Protagonist Height"], self.values_dict["Protagonist Speed"])
        # self.player_two = Protagonist(self.values_dict["Height"]-self.values_dict["Protagonist Width"], int((self.values_dict["Height"]/2)-self.values_dict["Protagonist Height"]), self.values_dict["Protagonist Width"], self.values_dict["Protagonist Height"], self.values_dict["Protagonist Speed"])
        # self.projectile = Projectile(int((self.values_dict["Height"]/2)-self.values_dict["Projectile Height"]), int((self.values_dict["Height"]/2)-self.values_dict["Projectile Height"]), self.values_dict["Projectile Speed"], self.values_dict["Projectile Speed"], self.values_dict["Projectile Width"], self.values_dict["Projectile Height"])
    
        # self.game_engine = mygameengine.SDLGraphicsProgram(self.values_dict["Width"], self.values_dict["Height"], self.values_dict["Game Name"])
        # self.game_engine.setBackgroundColor(self.backgroundRed, self.backgroundGreen, self.backgroundBlue, self.backgroundAlpha)

#     def draw_player_one(self):
#         self.game_engine.DrawRectangle(self.player_one.getX(), self.player_one.getY(), self.player_one.getWidth(), self.player_one.getHeight())

#     def draw_player_two(self):
#         self.game_engine.DrawRectangle(self.player_two.getX(), self.player_two.getY(), self.player_two.getWidth(), self.player_two.getHeight())

#     def draw_projectile(self):
#         self.game_engine.DrawRectangle(self.projectile.getX(), self.projectile.getY(), self.projectile.getWidth(), self.projectile.getHeight())

#     def set_background_color(self):
#         self.game_engine.setBackgroundColor(self.background.getRed(), self.background.getGreen(), self.background.getBlue(), self.background.getAlpha())

# ## -------------------- GAME LOOP START ---------------------- ##


    def run_game(self):
        self.game_engine.StartUp(self.values_dict["Width"], self.values_dict["Height"], self.values_dict["Game Name"])
        print(self.values_dict)

        while not self.quit:
            self.game_engine.Delay()
            self.game_engine.Poll()

#     def run_game(self):
#         # print(self.values_dict)
#         while not self.quit:
#             self.game_engine.poll()
#             # self.game_engine.clear()

#             if self.game_engine.getRightPaddleDown():
#                 self.player_two.moveUp()
#             if self.game_engine.getRightPaddleUp():
#                 self.player_two.moveDown()
#             self.draw_player_two()

#             if self.game_engine.getLeftPaddleUp():
#                 self.player_one.moveUp()
#             if self.game_engine.getLeftPaddleDown():
#                 self.player_one.moveDown()
#             self.draw_player_one()

#             self.projectile.move()
#             self.projectile.checkWallCollision(self.values_dict["Height"])
#             self.projectile.checkCollision(self.player_one)
#             self.projectile.checkCollision(self.player_two)

#             if self.projectile.checkExitedWindow(self.values_dict["Width"], self.values_dict["Height"]):
#                 self.background.colorIncrementer()
#                 self.set_background_color()

#             self.draw_projectile()

#             self.game_engine.delay(200)
#             # self.game_engine.flip()

#             self.quit = self.game_engine.getQuit()
#             # print("Python quit: ", self.quit)


# ## -------------------- GAME LOOP END ---------------------- ##
   
