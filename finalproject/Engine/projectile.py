## -------------------- In PONG: ball ---------------------- ##

class Projectile:
    def __init__(self, x, y, vx, vy, width, height):
        self.x = x
        self.y = y  
        self.vx = vx 
        self.vy = vy  
        self.width = width
        self.height = height

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
    def checkWallCollision(self, window_width, window_height):
        if self.y <= 0 or self.y >= window_height - self.height:
            self.reverseVelocityY()

    # pass an object in to see if there's a collision (in pong, checks the paddles)
    def checkCollision(self, object):
        if (self.x <= object.getX() + object.getWidth() and
                self.y >= object.getY() and
                self.y <= object.getY() + object.getHeight()):
            self.reverseVelocityX()

    # if ball moves "past" this object (in pong, checks if passed by paddle, therefore score + 1)
    def checkExitedWindow(self, window_width, window_height):
        if self.x <= 0 or self.x >= window_width:
            self.x = int((window_width / 2) - (self.width/ 2))
            self.y = int((window_height / 2) - (self.height / 2))
            return True
            


