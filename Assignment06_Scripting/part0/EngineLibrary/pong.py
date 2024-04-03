import mygameengine

# Initialize SDL
test = mygameengine.SDLGraphicsProgram(400, 400)

# Clear the screen
test.clear()

test.DrawRectangle(100, 100, 100, 100)

test.delay(100)

# Refresh the screen
test.flip()

test.poll()


test.runPongGame();

# End of program


