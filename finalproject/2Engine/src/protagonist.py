import threading

# self.left_paddle = Protagonist(0, int((self.window_height/2)-PADDLE_HEIGHT), PADDLE_WIDTH, PADDLE_HEIGHT, MOVEMENT)

class Protagonist:
    def __init__(self, x, y, width, height, movement_increment):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.movement_increment = movement_increment
        self.default_movement_increment = movement_increment  # Store the default value


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

    def moveDown(self):
        self.y -= self.movement_increment

    def moveUp(self):
        self.y += self.movement_increment

    def setMovementIncrement(self, new_increment):
        self.movement_increment = new_increment

    # def setTemporaryMovementIncrement(self, new_increment, duration):
    #     self.movement_increment = new_increment  # Set new increment
    #     threading.Timer(duration, self.resetMovementIncrement).start()  # Reset increment after duration

    def resetMovementIncrement(self):
        self.movement_increment = self.default_movement_increment  # Reset to default increment