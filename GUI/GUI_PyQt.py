import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QSlider, QVBoxLayout, QHBoxLayout, QGridLayout, QWidget, QLineEdit, QFrame
from PyQt5.QtCore import Qt

class FractalExplorer(QMainWindow):
    def __init__(self):
        super().__init__()
        
        self.setWindowTitle("Fractal Exploration")
        self.setGeometry(100, 100, 1400, 900)  # Set the initial size
        
        self.main_widget = QWidget()
        self.setCentralWidget(self.main_widget)
        
        self.main_layout = QVBoxLayout(self.main_widget)
        
        self.create_main_menu()
        self.create_mandelbrot_screen()
        self.create_julia_screen()
        
        self.show_main_menu()
        self.showMaximized()  # Make the window fullscreen
        
    def create_main_menu(self):
        self.main_menu = QWidget()
        self.main_layout.addWidget(self.main_menu)
        
        layout = QVBoxLayout(self.main_menu)
        
        self.mandelbrot_button = QPushButton("Explore Mandelbrot Set", self)
        self.mandelbrot_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 18pt;")
        self.mandelbrot_button.clicked.connect(self.show_mandelbrot_screen)
        layout.addWidget(self.mandelbrot_button)
        
        self.julia_button = QPushButton("Explore Julia Set", self)
        self.julia_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 18pt;")
        self.julia_button.clicked.connect(self.show_julia_screen)
        layout.addWidget(self.julia_button)
        
        self.settings_button = QPushButton("Settings and Controls", self)
        self.settings_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 18pt;")
        layout.addWidget(self.settings_button)
        
        self.about_button = QPushButton("About the Team", self)
        self.about_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 18pt;")
        layout.addWidget(self.about_button)
        
    def create_mandelbrot_screen(self):
        self.mandelbrot_screen = QWidget()
        self.main_layout.addWidget(self.mandelbrot_screen)
        
        layout = QVBoxLayout(self.mandelbrot_screen)
        
        title_label = QLabel("Mandelbrot Set", self)
        title_label.setAlignment(Qt.AlignCenter)
        title_label.setStyleSheet("color: #61dafb; font-size: 18pt; font-weight: bold; margin-bottom: 20px;")
        layout.addWidget(title_label)

        grid_layout = QGridLayout()
        layout.addLayout(grid_layout)

        # Colour Column
        color_frame = QFrame(self)
        color_frame.setFrameShape(QFrame.Box)
        color_layout = QVBoxLayout(color_frame)
        grid_layout.addWidget(color_frame, 0, 0)

        color_label = QLabel("Colour", self)
        color_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(color_label)

        presets = ["Preset1", "Preset2", "Preset3", "Preset4", "Preset5", "Preset6"]
        for preset in presets:
            btn = QPushButton(preset, self)
            btn.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
            color_layout.addWidget(btn)

        personal_color_button = QPushButton("Personalised Colour", self)
        personal_color_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
        color_layout.addWidget(personal_color_button)

        # Movement and Zoom Column
        movement_frame = QFrame(self)
        movement_frame.setFrameShape(QFrame.Box)
        movement_layout = QVBoxLayout(movement_frame)
        grid_layout.addWidget(movement_frame, 0, 1)

        movement_label = QLabel("Movement and Zoom", self)
        movement_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        movement_layout.addWidget(movement_label)

        zoom_slider = QSlider(Qt.Horizontal, self)
        zoom_slider.setMinimum(1)
        zoom_slider.setMaximum(100)
        zoom_slider.setValue(50)
        zoom_slider.valueChanged.connect(self.update_zoom_value)
        movement_layout.addWidget(zoom_slider)

        zoom_value_label = QLabel("Zoom Value: 50", self)
        zoom_value_label.setStyleSheet("color: #000000; font-size: 12pt; margin-bottom: 10px;")
        movement_layout.addWidget(zoom_value_label)
        self.zoom_value_label = zoom_value_label

        coordinates_label = QLabel("Coordinates: (0, 0)", self)
        coordinates_label.setStyleSheet("color: #000000; font-size: 12pt; margin-bottom: 10px;")
        movement_layout.addWidget(coordinates_label)
        self.coordinates_label = coordinates_label

        movement_image_label = QLabel("Image Placeholder for Movement Explanation", self)
        movement_image_label.setStyleSheet("color: #000000; font-size: 12pt; border: 1px solid #000000; margin-bottom: 10px;")
        movement_image_label.setAlignment(Qt.AlignCenter)
        movement_layout.addWidget(movement_image_label)

        activate_movement_button = QPushButton("Activate Movement", self)
        activate_movement_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
        movement_layout.addWidget(activate_movement_button)

        # Other Parameters Column
        params_frame = QFrame(self)
        params_frame.setFrameShape(QFrame.Box)
        params_layout = QVBoxLayout(params_frame)
        grid_layout.addWidget(params_frame, 0, 2)

        other_params_label = QLabel("Other Parameters", self)
        other_params_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        params_layout.addWidget(other_params_label)

        self.back_button_mandelbrot = QPushButton("Back", self)
        self.back_button_mandelbrot.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 14pt;")
        self.back_button_mandelbrot.clicked.connect(self.show_main_menu)
        layout.addWidget(self.back_button_mandelbrot)
        
    def create_julia_screen(self):
        self.julia_screen = QWidget()
        self.main_layout.addWidget(self.julia_screen)
        
        layout = QVBoxLayout(self.julia_screen)
        
        title_label = QLabel("Julia Set", self)
        title_label.setAlignment(Qt.AlignCenter)
        title_label.setStyleSheet("color: #61dafb; font-size: 18pt; font-weight: bold; margin-bottom: 20px;")
        layout.addWidget(title_label)
        
        grid_layout = QGridLayout()
        layout.addLayout(grid_layout)
        
        # Colour Column
        color_frame = QFrame(self)
        color_frame.setFrameShape(QFrame.Box)
        color_layout = QVBoxLayout(color_frame)
        grid_layout.addWidget(color_frame, 0, 0)

        color_label = QLabel("Colour", self)
        color_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(color_label)

        presets = ["Preset1", "Preset2", "Preset3", "Preset4", "Preset5", "Preset6"]
        for preset in presets:
            btn = QPushButton(preset, self)
            btn.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
            color_layout.addWidget(btn)

        personal_color_button = QPushButton("Personalised Colour", self)
        personal_color_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
        color_layout.addWidget(personal_color_button)

        # Movement and Zoom Column
        movement_frame = QFrame(self)
        movement_frame.setFrameShape(QFrame.Box)
        movement_layout = QVBoxLayout(movement_frame)
        grid_layout.addWidget(movement_frame, 0, 1)

        movement_label = QLabel("Movement and Zoom", self)
        movement_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        movement_layout.addWidget(movement_label)

        zoom_slider = QSlider(Qt.Horizontal, self)
        zoom_slider.setMinimum(1)
        zoom_slider.setMaximum(100)
        zoom_slider.setValue(50)
        zoom_slider.valueChanged.connect(self.update_zoom_value_julia)
        movement_layout.addWidget(zoom_slider)

        zoom_value_label = QLabel("Zoom Value: 50", self)
        zoom_value_label.setStyleSheet("color: #000000; font-size: 12pt; margin-bottom: 10px;")
        movement_layout.addWidget(zoom_value_label)
        self.zoom_value_label_julia = zoom_value_label

        coordinates_label = QLabel("Coordinates: (0, 0)", self)
        coordinates_label.setStyleSheet("color: #000000; font-size: 12pt; margin-bottom: 10px;")
        movement_layout.addWidget(coordinates_label)
        self.coordinates_label_julia = coordinates_label

        movement_image_label = QLabel("Image Placeholder for Movement Explanation", self)
        movement_image_label.setStyleSheet("color: #000000; font-size: 12pt; border: 1px solid #000000; margin-bottom: 10px;")
        movement_image_label.setAlignment(Qt.AlignCenter)
        movement_layout.addWidget(movement_image_label)

        activate_movement_button = QPushButton("Activate Movement", self)
        activate_movement_button.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 12pt;")
        movement_layout.addWidget(activate_movement_button)
        
        # Other Parameters Column
        params_frame = QFrame(self)
        params_frame.setFrameShape(QFrame.Box)
        params_layout = QVBoxLayout(params_frame)
        grid_layout.addWidget(params_frame, 0, 2)

        other_params_label = QLabel("Other Parameters", self)
        other_params_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        params_layout.addWidget(other_params_label)

        self.back_button_julia = QPushButton("Back", self)
        self.back_button_julia.setStyleSheet("background-color: #3e3e3e; color: #ffffff; font-size: 14pt;")
        self.back_button_julia.clicked.connect(self.show_main_menu)
        layout.addWidget(self.back_button_julia)
        
    def update_zoom_value(self, value):
        self.zoom_value_label.setText(f"Zoom Value: {value}")
        
    def update_zoom_value_julia(self, value):
        self.zoom_value_label_julia.setText(f"Zoom Value: {value}")
        
    def show_main_menu(self):
        self.main_menu.show()
        self.mandelbrot_screen.hide()
        self.julia_screen.hide()
        
    def show_mandelbrot_screen(self):
        self.main_menu.hide()
        self.mandelbrot_screen.show()
        self.julia_screen.hide()
        
    def show_julia_screen(self):
        self.main_menu.hide()
        self.mandelbrot_screen.hide()
        self.julia_screen.show()
        
if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWin = FractalExplorer()
    mainWin.show()
    sys.exit(app.exec_())
