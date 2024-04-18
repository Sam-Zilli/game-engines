import mygameengine
import random
from background import Background  # Import the Background class
from protagonist import Protagonist # Import the Protagonist class to use as each paddle

PADDLE_WIDTH = 10
PADDLE_HEIGHT = 40
BALL_WIDTH = 5
BALL_HEIGHT = 5

# the increments in which movement occurs
MOVEMENT = 10

# Ask the user for input regarding the size of the window
# WINDOW_WIDTH = int(input("Enter the width of the window: "))
# WINDOW_HEIGHT = int(input("Enter the height of the window: "))

WINDOW_WIDTH = 200
WINDOW_HEIGHT = 200

# Initialize SDL / window
gameEngine = mygameengine.SDLGraphicsProgram(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong!")
# should pass in the values the user chose - currently Black to start
gameEngine.setBackgroundColor(0,0,0,0)

# Main game loop
quit = False


color_map = {
    'red': (255, 0, 0, 255),       # Red with alpha value 255
    'green': (0, 255, 0, 255),     # Green with alpha value 255
    'blue': (0, 0, 255, 255),      # Blue with alpha value 255
    'yellow': (255, 255, 0, 255),  # Yellow with alpha value 255
    'pink': (255, 0, 255, 255),    # Pink with alpha value 255
    'white': (255, 255, 255, 255), # White with alpha value 255
    'black': (0, 0, 0, 255),       # Black with alpha value 255
    'gray': (128, 128, 128, 255),  # Gray with alpha value 255
}


## -------------------- BALL ---------------------- ##

class Ball:
    def __init__(self, x, y, vx, vy):
        self.x = x
        self.y = y  
        self.vx = vx 
        self.vy = vy  
        self.width = BALL_WIDTH 
        self.height = BALL_HEIGHT 

    def getWidth(self):
        return self.width

    def getHeight(self):
        return self.height

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def getVelocityX(self):
        return self.vx

    def getVelocityY(self):
        return self.vy

    def setVelocityX(self, vx):
        self.vx = vx

    def setVelocityY(self, vy):
        self.vy = vy

    def move(self):
        self.x += self.vx
        self.y += self.vy

    def reverseVelocityX(self):
        self.vx *= -1

    def reverseVelocityY(self):
        self.vy *= -1
        
    # checking for collisions with top or bottom "wall" of window    
    def checkWallCollision(self):
        if self.y <= 0 or self.y >= WINDOW_HEIGHT - BALL_HEIGHT:
            self.reverseVelocityY()

    # checking for paddle collisions
    def checkPaddleCollision(self):
        if (self.x <= leftPaddle.getX() + leftPaddle.getWidth() and
                self.y >= leftPaddle.getY() and
                self.y <= leftPaddle.getY() + leftPaddle.getHeight()):
            self.reverseVelocityX()


        if (self.x + BALL_WIDTH >= rightPaddle.getX() and
                self.y >= rightPaddle.getY() and
                self.y <= rightPaddle.getY() + rightPaddle.getHeight()):
            self.reverseVelocityX()

    # if ball moves past left or right paddle than the other player scores
    def checkPassedPaddle(self):
        if self.x <= 0 or self.x >= WINDOW_WIDTH:
            self.x = int((WINDOW_WIDTH / 2) - (BALL_WIDTH / 2))
            self.y = int((WINDOW_HEIGHT / 2) - (BALL_HEIGHT / 2))
            return True
            






## -------------------- Game ---------------------- ##

leftPaddle = Protagonist(0, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
rightPaddle = Protagonist(WINDOW_HEIGHT-PADDLE_WIDTH, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
ball = Ball((int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), (int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), 10, 10)
background = Background(0, color_map)


## -------------------- Interacting with C++ via Bindings ---------------------- ##

def drawLeftPaddle():
    gameEngine.DrawRectangle(leftPaddle.getX(), leftPaddle.getY(), leftPaddle.getWidth(), leftPaddle.getHeight())

def drawRightPaddle():
    gameEngine.DrawRectangle(rightPaddle.getX(), rightPaddle.getY(), rightPaddle.getWidth(), rightPaddle.getHeight())

def drawBall():
    gameEngine.DrawRectangle(ball.getX(), ball.getY(), ball.getWidth(), ball.getHeight())

def setBackgroundColor():
    gameEngine.setBackgroundColor(background.getRed(), background.getGreen(), background.getBlue(), background.getAlpha())

## -------------------- Game Loop ---------------------- ##

# While running 
while not quit:

    gameEngine.poll()
    gameEngine.clear()

    # checking for right paddle movement
    if(gameEngine.getRightPaddleDown()):
        rightPaddle.moveUp()
    if(gameEngine.getRightPaddleUp()):
        rightPaddle.moveDown()
    # drawing right paddle
    drawRightPaddle()


    # checking for left paddle movement
    if(gameEngine.getLeftPaddleUp()):
        leftPaddle.moveUp()
    if(gameEngine.getLeftPaddleDown()):
        leftPaddle.moveDown()

    # drawing left paddle
    drawLeftPaddle()

    # Move the ball
    ball.move()

    # Check for collisions
    ball.checkWallCollision()
    ball.checkPaddleCollision()
    if ball.checkPassedPaddle():
        background.colorIncrementer()
        setBackgroundColor()

    drawBall()

    # Delay for a short time
    gameEngine.delay(200)

    # Refresh the screen
    gameEngine.flip()

    # Check if game should quit
    quit = gameEngine.getQuit()


## -------------------- END ---------------------- ##


