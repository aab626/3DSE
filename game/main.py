import pyglet
from pyglet.gl import glGetString, glClear, glViewport
from pyglet.gl import GL_VERSION, GL_VENDOR, GL_RENDERER, GL_SHADING_LANGUAGE_VERSION
from pyglet.gl import GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT
import ctypes
import math
import time

from engine.engine_lib import Engine
from engine.engine_lib import ModuleType
from engine.engine_lib import TestModule, LoggerModule, TransformModule
from engine.engine_lib import Entity

engine = Engine.GetInstance()
engine.RegisterModuleType(ModuleType.MODULE_TYPE_TEST, TestModule.moduleTypeName)
engine.RegisterModuleType(ModuleType.MODULE_TYPE_LOGGER, LoggerModule.moduleTypeName)
engine.RegisterModuleType(ModuleType.MODULE_TYPE_TRANSFORM, TransformModule.moduleTypeName)

ent1 = Entity()
mTransform1 = TransformModule("ent1 transform module")
ent1.AddModule(mTransform1)

print(mTransform1.GetPosition())


# ent1 = Entity()
# ent1.
print("exiting!")
import sys
sys.exit(0)


# Create a window with OpenGL context
window = pyglet.window.Window(width=800, height=600, caption="Test")

# Check OpenGL version
# print(f"OpenGL Version: {ctypes.string_at(glGetString(GL_VERSION)).decode('utf-8')}")
# print(f"OpenGL Vendor: {ctypes.string_at(glGetString(GL_VENDOR)).decode('utf-8')}")
# print(f"OpenGL Renderer: {ctypes.string_at(glGetString(GL_RENDERER)).decode('utf-8')}")
# print(f"GLSL Version: {ctypes.string_at(glGetString(GL_SHADING_LANGUAGE_VERSION)).decode('utf-8')}")

# Game state variables
triangle_x = 0
triangle_y = 300
start_time = time.time()

def render_triangle(x, y, size=10):
    """Render a triangle at position (x, y) with given size using Pyglet shapes"""
    # Create a triangle shape using Pyglet's built-in shapes
    triangle = pyglet.shapes.Triangle(
        x, y + size,        # Top vertex
        x - size, y - size, # Bottom left
        x + size, y - size, # Bottom right
        color=(255, 0, 0)   # Red color
    )
    triangle.draw()


@window.event
def on_draw():
    # Clear the screen
    window.clear()
    
    # Render triangle at current position
    render_triangle(triangle_x, triangle_y, 10)


def update(dt):
    """Update function called every 1/60th of a second"""
    global triangle_x, triangle_y

    # Example: Move triangle in a circle using elapsed time
    # elapsed_time = time.time() - start_time
    # triangle_x = 400 + 100 * math.cos(elapsed_time)
    # triangle_y = 300 + 100 * math.sin(elapsed_time)
    triangle_x+=1

# Run the application
pyglet.clock.schedule_interval(update, 1/60.0)
pyglet.app.run()
