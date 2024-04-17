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