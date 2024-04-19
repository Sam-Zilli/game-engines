import mygameengine
from background import Background
from protagonist import Protagonist
from projectile import Projectile
import random

PADDLE_HEIGHT = 20
PADDLE_WIDTH = 20
MOVEMENT = 20
BALL_HEIGHT = 3
BALL_WIDTH = 10
BALL_V = 10


class Game:
    def __init__(self, game_engine, values_dict):
        self.values_dict = values_dict
        self.game_engine = game_engine
        self.quit = False
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

        self.background = Background(0, self.color_map)
        self.left_paddle = Protagonist(0, int((self.values_dict["Height"]/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
        self.right_paddle = Protagonist(self.values_dict["Height"]-PADDLE_WIDTH, int((self.values_dict["Height"]/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
        self.ball = Projectile(int((self.values_dict["Height"]/2)-BALL_HEIGHT), int((self.values_dict["Height"]/2)-BALL_HEIGHT), BALL_V, BALL_V, BALL_WIDTH, BALL_HEIGHT)
        self.game_engine = mygameengine.SDLGraphicsProgram(self.values_dict["Width"], self.values_dict["Height"], self.values_dict["Game Name"])
        self.game_engine.setBackgroundColor(0, 0, 0, 0)

    def draw_left_paddle(self):
        self.game_engine.DrawRectangle(self.left_paddle.getX(), self.left_paddle.getY(), self.left_paddle.getWidth(), self.left_paddle.getHeight())

    def draw_right_paddle(self):
        self.game_engine.DrawRectangle(self.right_paddle.getX(), self.right_paddle.getY(), self.right_paddle.getWidth(), self.right_paddle.getHeight())

    def draw_ball(self):
        self.game_engine.DrawRectangle(self.ball.getX(), self.ball.getY(), self.ball.getWidth(), self.ball.getHeight())

    def set_background_color(self):
        self.game_engine.setBackgroundColor(self.background.getRed(), self.background.getGreen(), self.background.getBlue(), self.background.getAlpha())

## -------------------- GAME LOOP START ---------------------- ##

    def run_game(self):
        while not self.quit:
            self.game_engine.poll()
            self.game_engine.clear()

            if self.game_engine.getRightPaddleDown():
                self.right_paddle.moveUp()
            if self.game_engine.getRightPaddleUp():
                self.right_paddle.moveDown()
            self.draw_right_paddle()

            if self.game_engine.getLeftPaddleUp():
                self.left_paddle.moveUp()
            if self.game_engine.getLeftPaddleDown():
                self.left_paddle.moveDown()
            self.draw_left_paddle()

            self.ball.move()
            self.ball.checkWallCollision(self.values_dict["Height"])
            self.ball.checkCollision(self.left_paddle)
            self.ball.checkCollision(self.right_paddle)

            if self.ball.checkExitedWindow(self.values_dict["Width"], self.values_dict["Height"]):
                self.background.colorIncrementer()
                self.set_background_color()

            self.draw_ball()

            self.game_engine.delay(200)
            self.game_engine.flip()

            self.quit = self.game_engine.getQuit()

## -------------------- GAME LOOP END ---------------------- ##
   
