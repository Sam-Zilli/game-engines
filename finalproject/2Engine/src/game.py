import mygameengine
from background import Background
from protagonist import Protagonist
from projectile import Projectile
import random

class Game:
    def __init__(self, values_dict):
        self.values_dict = values_dict
        self.game_engine = None
        # self.game_engine = mygameengine.GameApp() # game is run on this engine (bindings.cpp)
        self.quit = False
        self.gameObjects = []
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
        self.two_player_game = self.values_dict["Number of Players"] == 2 # True or False value for if 2 player game

        self.background = Background(0, self.color_map)
        self.player_one = Protagonist(0, int((self.values_dict["Height"]/2)-self.values_dict["Protagonist Height"]),self.values_dict["Protagonist Width"], self.values_dict["Protagonist Height"], self.values_dict["Protagonist Speed"])
        self.player_two = Protagonist(self.values_dict["Height"]-self.values_dict["Protagonist Width"], int((self.values_dict["Height"]/2)-self.values_dict["Protagonist Height"]), self.values_dict["Protagonist Width"], self.values_dict["Protagonist Height"], self.values_dict["Protagonist Speed"])
        self.projectile = Projectile(int((self.values_dict["Height"]/2)-self.values_dict["Projectile Height"]), int((self.values_dict["Height"]/2)-self.values_dict["Projectile Height"]), self.values_dict["Projectile Speed"], self.values_dict["Projectile Speed"], self.values_dict["Projectile Width"], self.values_dict["Projectile Height"])


    def getGameObjects(self):
        return self.gameObjects


    def setGameObjects(self, newObject):
        self.gameObjects = self.gameObjects.append(newObject)

    def draw_player_one(self):
        self.game_engine.DrawRectangle(self.player_one.getX(), self.player_one.getY(), self.player_one.getWidth(), self.player_one.getHeight())

    def draw_player_two(self):
        self.game_engine.DrawRectangle(self.player_two.getX(), self.player_two.getY(), self.player_two.getWidth(), self.player_two.getHeight())

    def draw_projectile(self):
        self.game_engine.DrawRectangle(self.projectile.getX(), self.projectile.getY(), self.projectile.getWidth(), self.projectile.getHeight())

    def set_background_color(self):
        self.game_engine.SetBackgroundColor(self.background.getRed(), self.background.getGreen(), self.background.getBlue(), self.background.getAlpha())

    def setGameEngine(self, engine):
        self.game_engine = engine

# ## -------------------- GAME LOOP START ---------------------- ##

    def run_game(self):
        self.setGameEngine(mygameengine.GameApp(self.values_dict["Width"], self.values_dict["Height"], self.values_dict["Game Name"]))
        self.game_engine.SetBackgroundColor(0,0,255,255)

        print("Finished Setup")

        while not self.quit:
            # print("Before poll")
            # self.game_engine.Poll() # should set all the values for if keys up/down from grpahics to Gameapps
            # print("After Poll")
            self.game_engine.Clear()
            print("After Clear")

            # has right arrow down been clicked?
            if self.game_engine.getRightArrowDown(): # Returns GAMEAPPS status
                # set new coordiantes for player two
                print("Location WAS: ", self.player_two.getX(), self.player_two.getY())
                print("RIGHT ARROW DOWN: ", self.game_engine.getRightArrowDown())
                self.player_two.moveUp()
                print("New Location: ", self.player_two.getX(), self.player_two.getY())

            if self.game_engine.getRightArrowUp():
                print("Changing player one location")
                self.player_two.moveDown()

            self.draw_player_two()

            if self.game_engine.getLeftArrowUp():
                print("Changing player one location")
                self.player_one.moveUp()
            if self.game_engine.getLeftArrowDown():
                self.player_one.moveDown()

            self.draw_player_one()

            self.projectile.move()
            self.projectile.checkWallCollision(self.values_dict["Height"])
            self.projectile.checkCollision(self.player_one)
            self.projectile.checkCollision(self.player_two)

            if self.projectile.checkExitedWindow(self.values_dict["Width"], self.values_dict["Height"]):
                self.background.colorIncrementer()
                self.set_background_color()

            self.draw_projectile()

            print("before last delay")
            self.game_engine.Delay(200)
            print("before flip")
            self.game_engine.Flip()
            print("Before GetQuit")
            self.quit = self.game_engine.GetQuit()
            print("End of this loop!")

## -------------------- GAME LOOP END ---------------------- ##