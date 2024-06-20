import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.colorpicker import ColorPicker
from kivy.uix.popup import Popup
from kivy.uix.button import Button
from kivy.uix.image import Image
from kivy.uix.label import Label
from kivy.uix.slider import Slider
from kivy.properties import ListProperty
from kivy.clock import Clock

import pygame
from pynput.mouse import Button as MouseButton, Controller as MouseController

kivy.require('2.1.0')


class ControllerGUI(BoxLayout):
    selected_color_1 = ListProperty([1, 1, 1, 1])
    selected_color_2 = ListProperty([1, 1, 1, 1])
    selected_color_3 = ListProperty([1, 1, 1, 1])

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        pygame.init()
        pygame.joystick.init()
        self.joystick = None
        if pygame.joystick.get_count() > 0:
            self.joystick = pygame.joystick.Joystick(0)
            self.joystick.init()
        self.mouse = MouseController()
        Clock.schedule_interval(self.check_controller_input, 1.0 / 60.0)

    def open_color_picker(self, color_property):
        color_picker = ColorPicker()
        box = BoxLayout(orientation='vertical')
        box.add_widget(color_picker)
        done_button = Button(text='DONE', size_hint=(1, 0.1))

        def on_done(instance):
            setattr(self, color_property, color_picker.color)
            popup.dismiss()

        done_button.bind(on_release=on_done)
        box.add_widget(done_button)

        popup = Popup(title="Select Color", content=box, size_hint=(0.8, 0.8))
        popup.open()

    def check_controller_input(self, dt):
        if self.joystick:
            pygame.event.pump()
            # Example of reading joystick axis and buttons
            axis_x = self.joystick.get_axis(0)  # Left stick horizontal
            axis_y = self.joystick.get_axis(1)  # Left stick vertical
            button_cross = self.joystick.get_button(0)  # Cross button (left click)
            button_square = self.joystick.get_button(3)  # Square button (right click)

            # Move the mouse
            sensitivity = 5  # Adjust sensitivity as needed
            current_pos = self.mouse.position
            new_x = current_pos[0] + axis_x * sensitivity
            new_y = current_pos[1] - axis_y * sensitivity  # Invert Y axis for natural control
            self.mouse.position = (new_x, new_y)

            # Handle mouse clicks
            if button_cross:
                self.mouse.press(MouseButton.left)
            else:
                self.mouse.release(MouseButton.left)

            if button_square:
                self.mouse.press(MouseButton.right)
            else:
                self.mouse.release(MouseButton.right)

            print(f"Axis X: {axis_x}, Axis Y: {axis_y}, Cross: {button_cross}, Square: {button_square}")


class ControllerApp(App):
    def build(self):
        return ControllerGUI()


if __name__ == '__main__':
    ControllerApp().run()
