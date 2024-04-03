import mygameengine

WINDOW_WIDTH = 400
WINDOW_HEIGHT = 400
PADDLE_WIDTH = 10
PADDLE_HEIGHT = 40
BALL_WIDTH = 5
BALL_HEIGHT = 5

# Initialize SDL / window
gameEngine = mygameengine.SDLGraphicsProgram(WINDOW_WIDTH, WINDOW_HEIGHT)

# Main game loop
quit = False



class Paddle:
    def __init__(self, x, y):
        self.x = x
        self.y = y



# While running 
while not quit:

    gameEngine.poll()

    gameEngine.clear()

    # left paddle
    gameEngine.DrawRectangle(0, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT)

    # right paddle
    gameEngine.DrawRectangle(WINDOW_HEIGHT-PADDLE_WIDTH, int((WINDOW_HEIGHT/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT)

    # ball
    gameEngine.DrawRectangle(int(int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), int(int((WINDOW_HEIGHT/2)-BALL_HEIGHT)), BALL_WIDTH, BALL_HEIGHT)

    # Delay for a short time
    gameEngine.delay(100)

    # Refresh the screen
    gameEngine.flip()

    # Check if game should quit
    quit = gameEngine.getQuit()

    # Run the Pong game


# End of program


