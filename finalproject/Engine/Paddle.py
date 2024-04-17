class Paddle:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = PADDLE_WIDTH
        self.height = PADDLE_HEIGHT

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
        self.y -= MOVEMENT

    def moveUp(self):
        self.y += MOVEMENT
