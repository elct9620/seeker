p ObjectSpace.count_objects

scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

Game.set_scene scene

p ObjectSpace.count_objects

scene2 = Scene.new "Next Scene"
scene3 = Scene.new "Next3 Scene"
scene4 = Scene.new "Next4 Scene"

scene.to scene2
scene2.to scene3
scene3.to scene4
p scene.nil?
p scene
p scene.class
#scene4.to scene

p ObjectSpace.count_objects

prev = scene4
(1..500).each do |i|
  curr = Scene.new "Scene #{i}"
  curr.add Actor.new("../data/avatar.jpg")
  prev.to curr
  prev = curr
end

p ObjectSpace.count_objects

=begin
scene2 = Scene.new "Next Scene"
scene2.add Actor.new("../data/avatar.jpg")

scene.to scene2
=end
