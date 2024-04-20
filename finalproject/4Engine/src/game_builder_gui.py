import mygameengine

print("Before app creation")

# Current working version
values_dict = {
    "game_name": "Game Name!!!",
    "window_width": "1000",
    "window_height": "1000"
}


# More functionality version
# values_dict_2 = {
#     "game_name": "Game Name!!!",
#     "window_width": "1000",
#     "window_height": "1000",
#     "backgroundRed: ": "0",
#     "backgroundGreen: ": "0",
#     "BackgroundBlue: ": "0",
#     "backgroundAlpha: ": "255",
#     "projectileSpeed: ": "10",
#     "protagonistSpeed: ": "5",
#     "numberOfEnemies: ": "2",
# }


loop_duration = 120.0


# Create an instance of Application
app = mygameengine.Application(values_dict)

print("Before running loop")
# Call the Loop method
app.Loop(loop_duration)
# print("End of game_builder_gui.py")