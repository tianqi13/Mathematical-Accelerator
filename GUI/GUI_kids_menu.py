import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QSlider, QVBoxLayout, QWidget, QHBoxLayout
from PyQt5.QtGui import QFont, QColor
from PyQt5.QtCore import Qt

class FractalApp(QMainWindow):
    def __init__(self):
        super().__init__()

        # Main Window settings
        self.setWindowTitle("Fractal Explorer for Kids")
        self.setGeometry(100, 100, 800, 600)
        self.setStyleSheet("background-color: #A9CCE3;")  # Light blue background

        # Fonts
        header_font = QFont('Comic Sans MS', 20, QFont.Bold)
        button_font = QFont('Comic Sans MS', 14)
        label_font = QFont('Comic Sans MS', 12)

        # Title Label
        self.title_label = QLabel("Welcome to the Fractal Dimension!", self)
        self.title_label.setFont(header_font)
        self.title_label.setStyleSheet("color: #1A5276;")  # Dark blue text
        self.title_label.setAlignment(Qt.AlignCenter)

        # Mandelbrot and Julia Buttons
        self.mandelbrot_button = QPushButton("Explore Mandelbrot Set", self)
        self.julia_button = QPushButton("Explore Julia Set", self)
        self.mandelbrot_button.setFont(button_font)
        self.julia_button.setFont(button_font)
        self.mandelbrot_button.setStyleSheet("background-color: #F7DC6F; color: #1A5276;")  # Yellow background, dark blue text
        self.julia_button.setStyleSheet("background-color: #F7DC6F; color: #1A5276;")  # Yellow background, dark blue text

        # Settings and Controls Button
        self.settings_button = QPushButton("Settings and Controls", self)
        self.settings_button.setFont(button_font)
        self.settings_button.setStyleSheet("background-color: #58D68D; color: #1A5276;")  # Green background, dark blue text

        # About Button
        self.about_button = QPushButton("About the Team", self)
        self.about_button.setFont(button_font)
        self.about_button.setStyleSheet("background-color: #AF7AC5; color: #1A5276;")  # Purple background, dark blue text

        # Layouts
        main_layout = QVBoxLayout()
        button_layout = QVBoxLayout()
        top_layout = QVBoxLayout()

        # Add widgets to layouts
        top_layout.addWidget(self.title_label)

        button_layout.addWidget(self.mandelbrot_button)
        button_layout.addWidget(self.julia_button)
        button_layout.addWidget(self.settings_button)
        button_layout.addWidget(self.about_button)

        main_layout.addLayout(top_layout)
        main_layout.addLayout(button_layout)

        # Main Widget
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

# Main function to start the application
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = FractalApp()
    ex.show()
    sys.exit(app.exec_())
