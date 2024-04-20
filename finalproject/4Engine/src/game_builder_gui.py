import mygameengine

print("Before app creation")

values_dict = {
    "game_name": "Game Name!!!",
    "window_width": "1000",
    "window_height": "1000"
}

loop_duration = 120.0


# Create an instance of Application
app = mygameengine.Application(values_dict)

print("Before running loop")
# Call the Loop method
app.Loop(loop_duration)
# print("End of game_builder_gui.py")