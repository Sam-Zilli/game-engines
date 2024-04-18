import mygameengine
import random
from background import Background  # Import the Background class
from protagonist import Protagonist # Import the Protagonist class to use as each paddle
from projectile import Projectile #  Ball! 

PADDLE_WIDTH = 10
PADDLE_HEIGHT = 40
BALL_WIDTH = 5
BALL_HEIGHT = 5

# the increments in which movement occurs
MOVEMENT = 20

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


## -------------------- Game ---------------------- ##

leftPaddle = Protagonist(0, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
rightPaddle = Protagonist(WINDOW_HEIGHT-PADDLE_WIDTH, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)
ball = Projectile((int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), (int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), 10, 10, BALL_WIDTH, BALL_HEIGHT)
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

    # Check for collisions with wall
    ball.checkWallCollision(WINDOW_WIDTH, WINDOW_HEIGHT)

    # check for collisions with left paddle
    ball.checkCollision(leftPaddle)

    # check for collisions with right paddle
    ball.checkCollision(rightPaddle)

    # check if passed paddle (Exited window)
    if ball.checkExitedWindow(WINDOW_WIDTH, WINDOW_HEIGHT):
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


