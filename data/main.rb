puts "Hello World"

scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

Game.set_scene scene
