scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

Game.set_scene scene

=begin
scene2 = Scene.new "Next Scene"
scene2.add Actor.new("../data/avatar.jpg")

scene.to scene2
=end
