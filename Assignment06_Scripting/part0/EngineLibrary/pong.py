import mygameengine

# Initialize SDL / window
gameEngine = mygameengine.SDLGraphicsProgram(400, 400)

# Main game loop
quit = False

# While running 
while not quit:

    gameEngine.poll()

    gameEngine.clear()

    # left paddle
    gameEngine.DrawRectangle(0, 200-40, 10, 40)

    # right paddle
    gameEngine.DrawRectangle(400-10, 200-40, 10, 40)

    # ball?
    gameEngine.DrawRectangle(200-10,200-10,10,10)

    # Delay for a short time
    gameEngine.delay(100)

    # Refresh the screen
    gameEngine.flip()

    # Check if game should quit
    quit = gameEngine.getQuit()

    # Run the Pong game


# End of program


