class Protagonist:
    def __init__(self, x, y, width, height, movement_increment):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.movement_increment = movement_increment

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