scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

ui = TextWidget.new "Hello World", 0, 0
ui.text = "HI?"

Game.set_scene scene
Game.ui = ui

