## -------------------- BACKGROUND ---------------------- ##

class Background:
    def __init__(self, current_color_index, color_map):
        self.backgroundRed = 255
        self.backgroundGreen = 255
        self.backgroundBlue = 255 
        self.backgroundAlpha = 255
        self.current_color_index = current_color_index
        self.color_map = color_map  # Store the color map (options for background color)

    def setBackgroundColor(self, red, green, blue, alpha):
        self.backgroundRed = red
        self.backgroundGreen = green
        self.backgroundBlue = blue
        self.backgroundAlpha = alpha

    def getRed(self):
        return self.backgroundRed
    
    def getGreen(self):
        return self.backgroundGreen
    
    def getBlue(self):
        return self.backgroundBlue
    
    def getAlpha(self):
        return self.backgroundAlpha
    
    def getCurrentColorIndex(self):
        return self.current_color_index
    
    # iterates through possible background colors
    def colorIncrementer(self):
        self.current_color_index = (self.current_color_index + 1) % len(self.color_map)
        color_name = list(self.color_map.keys())[self.current_color_index]
        self.setBackgroundColor(*self.color_map[color_name])