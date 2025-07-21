import pyglet
from pyglet.gl import *
from engine import Engine
import engine

class GameWindow(pyglet.window.Window):
    def __init__(self):
        super().__init__(800, 600, "Space Game")
        self.engine = Engine()
        self.engine.init()
        
        # Create a list to hold game objects
        self.game_objects = []

        # Create 5 game objects with IDs 1 to 5
        for i in range(5):
            # obj = engine.GameObject(i)
            obj = self.engine.createGameObject()
            self.game_objects.append(obj)

        # Report their IDs
        for obj in self.game_objects:
            print(f"GameObject ID: {obj.get_id()}")
        
    def on_draw(self):
        self.clear()
        self.engine.render()

if __name__ == "__main__":
    window = GameWindow()
    pyglet.app.run()
