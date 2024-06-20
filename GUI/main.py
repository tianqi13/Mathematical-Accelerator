import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.slider import Slider
from kivy.uix.label import Label

class FractalExplorerApp(App):
    def build(self):
        self.title = 'Fractal Exploration'
        return FractalScreenManager()

class FractalScreenManager(BoxLayout):
    def update_zoom_value(self, slider, value):
        self.ids.zoom_value_label.text = f'Zoom Value: {int(value)}'
    
    def update_zoom_value_julia(self, slider, value):
        self.ids.zoom_value_label_julia.text = f'Zoom Value: {int(value)}'
    
    def show_main_menu(self):
        self.ids.main_menu_screen.opacity = 1
        self.ids.main_menu_screen.disabled = False
        self.ids.mandelbrot_screen.opacity = 0
        self.ids.mandelbrot_screen.disabled = True
        self.ids.julia_screen.opacity = 0
        self.ids.julia_screen.disabled = True
    
    def show_mandelbrot_screen(self):
        self.ids.main_menu_screen.opacity = 0
        self.ids.main_menu_screen.disabled = True
        self.ids.mandelbrot_screen.opacity = 1
        self.ids.mandelbrot_screen.disabled = False
        self.ids.julia_screen.opacity = 0
        self.ids.julia_screen.disabled = True
    
    def show_julia_screen(self):
        self.ids.main_menu_screen.opacity = 0
        self.ids.main_menu_screen.disabled = True
        self.ids.mandelbrot_screen.opacity = 0
        self.ids.mandelbrot_screen.disabled = True
        self.ids.julia_screen.opacity = 1
        self.ids.julia_screen.disabled = False

if __name__ == '__main__':
    FractalExplorerApp().run()
