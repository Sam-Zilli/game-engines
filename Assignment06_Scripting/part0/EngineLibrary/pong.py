import mygameengine

# Initialize SDL
gameEngine = mygameengine.SDLGraphicsProgram(400, 400)

# Main game loop
quit = False

# While running 
while not quit:

    gameEngine.poll()

    gameEngine.clear()

    # Draw a rectangle
    gameEngine.DrawRectangle(100, 100, 100, 100)

    # Delay for a short time
    gameEngine.delay(100)

    # Refresh the screen
    gameEngine.flip()

    # Check if game should quit
    quit = gameEngine.getQuit()

    # Run the Pong game


# End of program


