scene = Scene.new "Test Scene"
scene.add Actor.new("../data/avatar.jpg", 10, 10)

ui = TextWidget.new "FPS: 0", 540, 0
ui.update do
  self.text = "速度 => FPS: #{Game.fps.round(3)}"
end

Game.set_scene scene
Game.ui = ui

