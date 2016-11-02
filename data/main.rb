scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

ui = TextWidget.new "FPS: 0", 540, 10
ui.update do
  self.text = "FPS: #{Game.fps.round(3)}"
  self.x = 620 - self.width
end

Game.set_scene scene
Game.ui = ui

