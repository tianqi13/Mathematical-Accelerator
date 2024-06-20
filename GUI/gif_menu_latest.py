
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QVBoxLayout,QHBoxLayout, QWidget, QStackedLayout, QFrame, QSizePolicy, QColorDialog, QSpacerItem, QDialog
from PyQt5.QtGui import QMovie, QFontDatabase, QFont, QPixmap, QPainter, QIcon, QCursor, QMouseEvent
from PyQt5.QtCore import Qt, QSize, QTimer, QEvent, QRegExp
from PyQt5.QtMultimedia import QSound
import pygame
from pynput.mouse import Button as MouseButton, Controller as MouseController

import socket
import time
# Global variable to hold the current background index
current_background_index = 0
current_book_index = 0
        
class TexturedButton(QPushButton): 
    def __init__(self, texture_normal, texture_pressed, parent=None):
        super().__init__("", parent)
        self.texture_normal = QPixmap(texture_normal)
        self.texture_pressed = QPixmap(texture_pressed)
        self.current_texture = self.texture_normal
        self.text = ""
        self.text_size = 12  # Default text size
        
        # Load the custom font
        font_id = QFontDatabase.addApplicationFont("PressStart2P-Regular.ttf")
        if font_id != -1:
            self.custom_font_family = QFontDatabase.applicationFontFamilies(font_id)[0]
        else:
            self.custom_font_family = "Comic Sans MS"  # Fallback to a default font
            
    def setText(self, text):
        self.text = text
        self.update()

    def setTextSize(self, size):
        self.text_size = size
        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.drawPixmap(self.rect(), self.current_texture)

        # Draw the text
        painter.setPen(Qt.black)
        font = QFont(self.custom_font_family, self.text_size)
        painter.setFont(font)
        offset = 10 if self.current_texture == self.texture_pressed else 0
        rect = self.rect().adjusted(0, offset, 0, offset)
        painter.drawText(rect, Qt.AlignCenter, self.text)
        painter.end()

    def mousePressEvent(self, event):
        #if event.button() == Qt.LeftButton:
        self.current_texture = self.texture_pressed
        self.update()
        super().mousePressEvent(event)

    def mouseReleaseEvent(self, event):
        #if event.button() == Qt.LeftButton:
        self.current_texture = self.texture_normal
        self.update()
        super().mouseReleaseEvent(event)

class FractalExplorer(QMainWindow):
    def __init__(self):
        super().__init__()
#******************************************************************************
        # Initialize Pygame and the controller
        pygame.init()
        pygame.joystick.init()
        self.joystick = None
        if pygame.joystick.get_count() > 0:
            self.joystick = pygame.joystick.Joystick(0)
            self.joystick.init()

        # Initialize the mouse controller
        self.mouse_controller = MouseController()

        # Timer for Pygame events
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.check_controller_input)
        self.timer.start(16)  # Approximately 60 times per second

        # Flag to track the state of the X,O,R1,L1 buttons
        self.x_button_pressed = False
        self.o_button_pressed = False
        self.r1_button_pressed = False
        self.l1_button_pressed = False
        self.right_button_pressed = False
        self.left_button_pressed = False
        
        # Flag to track the special movement mode
        self.movement_mode_active = False
#*********************************************************************************
  
        self.background_music = QSound("mandeltheme.wav")
        self.background_music.setLoops(QSound.Infinite)
        self.background_music.play()
        
        self.setWindowTitle("Fractal Exploration")
        self.setGeometry(100, 100, 1400, 900)  # Set the initial size
        
        self.main_widget = QWidget()
        self.setCentralWidget(self.main_widget)
        
        self.main_layout = QStackedLayout(self.main_widget)
        
        self.character_backgrounds = ["8bitmangoback.png", "MINEdelback.png", "8bitbackwithbarbie_final.png", "8bitmidnightback.png", "moonbackground.png","8bitback_final.png" ]
        self.character_text_colors = ["#000000", "#000000", "#000000", "#00FFFF", "#FFFF00", "#FFFFFF"]
        self.book_pages = ["first_page.png", "second_page.png", "third_page.png"]


        self.create_main_menu()
        self.create_mandelbrot_screen()
        self.create_julia_screen()
        self.create_settings_screen() 
        self.create_about_screen()
        
        self.show_main_menu()
        self.showMaximized()  # Make the window fullscreen
        self.client_socket = None
        self.current_preset = 0
        #self.current_theme = 0
    
    def change_music(self, file_path):
        self.background_music.stop()
        self.background_music = QSound(file_path)
        self.background_music.setLoops(QSound.Infinite)
        self.background_music.play()

    def check_controller_input(self):
        if self.joystick:
            pygame.event.pump()
            axis_x = self.joystick.get_axis(0)
            axis_y = self.joystick.get_axis(1)
            axis_r2 = self.joystick.get_axis(5)  # R2 is typically axis 5
            axis_l2 = self.joystick.get_axis(4)  # L2 is typically axis 4
            move_left = move_right = move_up = move_down = zoom_in = zoom_out = False
            threshold = 0.4

            if self.movement_mode_active:
                #print(f"L-stick X: {axis_x}, Y: {axis_y}, R2: {axis_r2}, L2: {axis_l2}")
                move_left = axis_x < -threshold
                move_right = axis_x > threshold
                move_up = axis_y < -threshold
                move_down = axis_y > threshold
                zoom_in  = axis_r2 > threshold
                zoom_out = axis_l2 > threshold
                time.sleep(0.1)
                if move_left and move_down:
                    print("Diagonal movement: Move left and down0")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_left_down0")
                elif move_left and move_up:
                    print("Diagonal movement: Move left and up0")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_left_up0")
                elif move_right and move_down:
                    print("Diagonal movement: Move right and down0")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right_down0")
                elif move_right and move_up:
                    print("Diagonal movement: Move right and up0")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right_up0")
                elif move_left:
                    print("Move left")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_left0")
                elif move_right:
                    print("Move right")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right0")
                elif move_up:
                    print("Move up")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_up0")
                elif move_down:
                    print("Move down")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_down0")
                elif zoom_in:
                    print("Zoom in")
                    # Send the movement command to the server
                    self.client_socket.send(b"zoom_in0")
                elif zoom_out:
                    print("Zoom out")
                    # Send the movement command to the server
                    self.client_socket.send(b"zoom_out0")
                else:
                    print("No movement")

                # Check if OPTIONS button is pressed to exit movement mode
                if self.joystick.get_button(2):  # Square button
                    # Reset the original position
                    self.client_socket.send(b"reset")

                if self.joystick.get_button(6):  # OPTIONS button
                    # Close connection
                    print("Exiting movement mode")
                    self.client_socket.send(b"close")
                    self.client_socket.close()
                    print("Connection closed")
                    self.movement_mode_active = False
            else:
                self.move_mouse(axis_x, axis_y)

                # Check the state of the X button --> mouse left click
                if self.joystick.get_button(0):  # X button || If you continue to press it nothing happens.
                    self.x_button_pressed = True
                else:                            #effect of button press only at release
                    if self.x_button_pressed:
                        self.click_mouse()
                    self.x_button_pressed = False #you would need to release X and press again for another click
                
                # Check the state of the O button --> go back
                if self.joystick.get_button(1):  # O button
                    self.o_button_pressed = True
                else:
                    if self.o_button_pressed:
                        self.press_back_button()
                    self.o_button_pressed = False
                
                # Check if R1 button is pressed to change theme to the next one
                if self.joystick.get_button(10):  # R1 button
                    self.r1_button_pressed = True
                else:
                    if self.r1_button_pressed:
                        self.show_next_character()#Also want to change mandelbrot&Julia backgrounds live
                        self.set_mandelbrot_background()
                    self.r1_button_pressed = False

                # Check if L1 button is pressed to change theme to the previous one
                if self.joystick.get_button(9):  # R1 button
                    self.l1_button_pressed = True
                else:
                    if self.l1_button_pressed:
                        self.show_previous_character() #Also want to change mandelbrot&Julia backgrounds live
                        self.set_mandelbrot_background()
                    self.l1_button_pressed = False
                
                # Check if LEFT button is pressed to change BOOK PAGE to the previous one
                if self.joystick.get_button(13):  # LEFT button
                    self.left_button_pressed = True
                else:
                    if self.left_button_pressed:
                        self.show_previous_page() #PREVIOUS PAGE
                    self.left_button_pressed = False
                
                # Check if RIGHT button is pressed to change BOOK PAGE to the next one
                if self.joystick.get_button(14):  # RIGHT button
                    self.right_button_pressed = True
                else:
                    if self.right_button_pressed:
                        self.show_next_page() #NEXT PAGE
                    self.right_button_pressed = False

#X:0, O:1, SQUARE:2, triangle:3, SHARE:4, PS:5, OPT:6, L3:7, R3:8, L1:9, R1:10, UP:11, DOWN:12, LEFT:13, RIGHT:14, TOUCHPAD:15

    def move_mouse(self, x, y):
        # Adjust sensitivity as needed
        sensitivity = 10
        # Get the current mouse position
        pos = self.mouse_controller.position
        # Move the cursor
        new_x = pos[0] + int(x * sensitivity)
        new_y = pos[1] + int(y * sensitivity)
        self.mouse_controller.position = (new_x, new_y)

    def click_mouse(self):
        # Get the current mouse position
        pos = QCursor.pos()
        # Simulate a mouse click at the current cursor position
        widget = QApplication.widgetAt(pos)
        if widget is not None:
            if isinstance(widget, TexturedButton):
                # Directly call mouse press and release events on the TexturedButton
                press_event = QMouseEvent(QEvent.MouseButtonPress, widget.mapFromGlobal(pos), Qt.LeftButton, Qt.LeftButton, Qt.NoModifier)
                release_event = QMouseEvent(QEvent.MouseButtonRelease, widget.mapFromGlobal(pos), Qt.LeftButton, Qt.LeftButton, Qt.NoModifier)
                widget.mousePressEvent(press_event)
                QTimer.singleShot(100, lambda: widget.mouseReleaseEvent(release_event))  # Simulate delay for release
            else:
                # Simulate a mouse click using pynput for other widgets
                self.mouse_controller.click(MouseButton.left, 1)

    def press_back_button(self):
        # Simulate a click on the back button in any screen
        back_buttons = self.findChildren(QPushButton, QRegExp("back_button_*"))
        for back_button in back_buttons:
            if back_button.isVisible():
                back_button.click()
                break

#Main menu and resize settings
    def create_main_menu(self):
        self.main_menu = QWidget(self)
        
        # Add QLabel for GIF background
        self.gif_label = QLabel(self.main_menu)
        self.gif_label.setGeometry(0, 0, self.width(), self.height())
        self.movie = QMovie("26e1fc2a4778a6fddee664468cf0063b.gif")
        self.gif_label.setMovie(self.movie)
        self.gif_label.setScaledContents(True)
        self.movie.start()
        
        # Add title with line break
        self.title_label = QLabel("Welcome to the\nfractal dimension!", self.main_menu)
        self.title_label.setGeometry((self.width() - 1250) // 2, 100, 1250, 200)
        self.title_label.setAlignment(Qt.AlignCenter)
        
        # Load custom font
        font_id = QFontDatabase.addApplicationFont("PressStart2P-Regular.ttf")
        if font_id != -1:
            font_family = QFontDatabase.applicationFontFamilies(font_id)[0]
            self.font_family = font_family
        else:
            self.font_family = "Comic Sans MS"  # Fallback font
        
        # Set initial font size
        font = QFont(self.font_family, 40)
        self.title_label.setFont(font)
        self.title_label.setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0.5);")
        
        # Add a container for buttons
        button_container = QWidget(self.main_menu)
        button_layout = QVBoxLayout(button_container)
        
        # Adjust button width and set text
        button_width = 500
        button_height = 100
        button_spacing = 50  # Increase the spacing between buttons
        
        self.mandelbrot_button = TexturedButton( 'not pressed button.png', 'pressed button.png', self.main_menu)
        self.mandelbrot_button.setText("Mandelbrot Set")
        self.mandelbrot_button.setGeometry((self.width() - button_width) // 2, 400, button_width, button_height)
        self.mandelbrot_button.clicked.connect(self.show_mandelbrot_screen)
        
        self.julia_button = TexturedButton( 'not pressed button.png', 'pressed button.png', self.main_menu)
        self.julia_button.setText("Julia Set")
        self.julia_button.setGeometry((self.width() - button_width) // 2, 400 + button_height + button_spacing, button_width, button_height)
        self.julia_button.clicked.connect(self.show_julia_screen)
        
        self.settings_button = TexturedButton( 'not pressed button.png', 'pressed button.png', self.main_menu)
        self.settings_button.setText("Themes")
        self.settings_button.setGeometry((self.width() - button_width) // 2, 400 + 2 * (button_height + button_spacing), button_width, button_height)
        self.settings_button.clicked.connect(self.show_settings_screen)
        
        self.about_button = TexturedButton( 'not pressed button.png', 'pressed button.png', self.main_menu)
        self.about_button.setText("About")
        self.about_button.setGeometry((self.width() - button_width) // 2, 400 + 3 * (button_height + button_spacing), button_width, button_height)
        self.about_button.clicked.connect(self.show_about_screen)

        self.main_layout.addWidget(self.main_menu)
        
    def resizeEvent(self, event):
        self.gif_label.setGeometry(0, 0, self.width(), self.height())
        #self.gif_label_about.setGeometry(0, 0, self.width(), self.height())
        button_width = 500
        button_height = 100
        button_spacing = 50
        self.title_label.setGeometry((self.width() - 1250) // 2, 100, 1250, 200)
        self.mandelbrot_button.setGeometry((self.width() - button_width) // 2, 400, button_width, button_height)
        self.julia_button.setGeometry((self.width() - button_width) // 2, 400 + button_height + button_spacing, button_width, button_height)
        self.settings_button.setGeometry((self.width() - button_width) // 2, 400 + 2 * (button_height + button_spacing), button_width, button_height)
        self.about_button.setGeometry((self.width() - button_width) // 2, 400 + 3 * (button_height + button_spacing), button_width, button_height)
        super().resizeEvent(event)


#Mandelbrot, Julia pages and MAP and BOOK screens for Mandelbrot
    def create_mandelbrot_screen(self):
        self.mandelbrot_screen = QWidget()
        self.main_layout.addWidget(self.mandelbrot_screen)

        # Main vertical layout
        layout = QVBoxLayout(self.mandelbrot_screen)

        # Title
        title_label = QLabel("MANDELBROT SET", self)
        # Set initial font size
        font = QFont(self.font_family, 30)
        title_label.setFont(font)
        title_label.setAlignment(Qt.AlignCenter)
        #title_label.setStyleSheet("color: #000000; font-weight: bold; background:transparent; margin-bottom: 10px;")
        layout.addWidget(title_label)

        # Columns layout
        columns_layout = QHBoxLayout()
        layout.addLayout(columns_layout)

        # Colour Column
        color_frame = QFrame(self)
        color_frame.setFrameShape(QFrame.NoFrame)
        color_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        color_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        color_layout = QVBoxLayout(color_frame)
        columns_layout.addWidget(color_frame)

        color_label = QLabel("Go-to map locations", self)
        color_label.setFont(font)
        color_label.setStyleSheet("color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(color_label)
        
        presets = ["Preset1", "Preset2", "Preset3", "Preset4", "Preset5", "Preset6"]
        preset_buttons = []
        for preset in presets:
            btn = TexturedButton('not pressed button.png', 'pressed button.png', self)
            btn.setText(preset)
            btn.setTextSize(14)  # Custom text size
            btn.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
            color_layout.addWidget(btn)
            preset_buttons.append(btn)

        # Adding spacer item for spacing after preset buttons
        spacer_item_after_presets = QSpacerItem(20, 20, QSizePolicy.Minimum, QSizePolicy.Fixed)
        color_layout.addSpacerItem(spacer_item_after_presets)

        # Adding text label before the color buttons
        personalize_label = QLabel("Personalise the colour\nof your Mandelbrot:", self)
        personalize_label.setFont(QFont(self.font_family, 14))
        personalize_label.setStyleSheet("color: black ; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(personalize_label)
        
        # Adding three individual color buttons
        self.color_buttons = []
        for i in range(1):
            color_button = TexturedButton('not pressed button.png', 'pressed button.png', self)
            color_button.setText(f"Colour {i + 1}")
            color_button.setTextSize(14)
            color_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
            color_button.clicked.connect(lambda _, b=color_button: self.choose_color(b))
            color_layout.addWidget(color_button)
            self.color_buttons.append(color_button)
            color_layout.addWidget(color_button)

        # Movement and Zoom Column
        movement_frame = QFrame(self)
        movement_frame.setFrameShape(QFrame.NoFrame)
        movement_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        movement_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        movement_layout = QVBoxLayout(movement_frame)
        columns_layout.addWidget(movement_frame)

        movement_label = QLabel("Select the map icon for\nfull screen map:", self)
        movement_label.setFont(font)
        movement_label.setStyleSheet(" color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        movement_layout.addWidget(movement_label)

        # Add the new button to show the MAP
        self.show_picture_button = QPushButton(self)
        self.show_picture_button.setIcon(QIcon("minimap.png"))
        self.show_picture_button.setIconSize(QSize(500, 500))
        self.show_picture_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.show_picture_button.setStyleSheet("border: none;")  # Remove the button border
        self.show_picture_button.clicked.connect(self.show_picture_screen)
        movement_layout.addWidget(self.show_picture_button)

    
        self.activate_movement_button = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.activate_movement_button.setText("Control movement")
        self.activate_movement_button.setTextSize(17)
        self.activate_movement_button.setFixedSize(800, 100)
        self.activate_movement_button.clicked.connect(self.activate_movement_mode)
        movement_layout.addWidget(self.activate_movement_button)

        # Other Parameters Column
        params_frame = QFrame(self)
        params_frame.setFrameShape(QFrame.NoFrame)
        params_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        params_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        params_layout = QVBoxLayout(params_frame)
        columns_layout.addWidget(params_frame)

        other_params_label = QLabel("Extra information", self)
        other_params_label.setFont(font)
        other_params_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        params_layout.addWidget(other_params_label)

        # Add the new button to show the BOOK
        self.show_info_button = QPushButton(self)
        self.show_info_button.setIcon(QIcon("8bitbook.png"))
        self.show_info_button.setIconSize(QSize(500, 500))
        self.show_info_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.show_info_button.setStyleSheet("border: none;")  # Remove the button border
        self.show_info_button.clicked.connect(self.show_info_screen)
        params_layout.addWidget(self.show_info_button)

        # Set stretch factors to increase column heights
        for i in range(columns_layout.count()):
            columns_layout.setStretch(i, 1)
        
        # Adding the Back button at the bottom right
        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        self.back_button_mandelbrot = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.back_button_mandelbrot.setObjectName("back_button_mandelbrot")  # Set a unique object name
        self.back_button_mandelbrot.setText("Back")
        self.back_button_mandelbrot.setTextSize(14)
        self.back_button_mandelbrot.setFixedSize(250, 75)  # Set fixed size for back button
        self.back_button_mandelbrot.clicked.connect(self.show_main_menu)
        back_button_layout.addWidget(self.back_button_mandelbrot)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom

        # Check if preset buttons are pressed
        for i, btn in enumerate(preset_buttons):
            # Print the index of the button when clicked
            btn.clicked.connect(lambda checked, i=i: self.set_current_preset(i))
            #print(self.current_preset)
        self.set_mandelbrot_background()

    def set_current_preset(self, i):
        self.current_preset = i
        print("Current preset:", self.current_preset)
        
    def create_julia_screen(self):
        self.juliabrot_screen = QWidget()
        self.main_layout.addWidget(self.juliabrot_screen)

        # Main vertical layout
        layout = QVBoxLayout(self.juliabrot_screen)

        # Title
        title_label = QLabel("MANDELBROT SET", self)
        # Set initial font size
        font = QFont(self.font_family, 30)
        title_label.setFont(font)
        title_label.setAlignment(Qt.AlignCenter)
        #title_label.setStyleSheet("color: #000000; font-weight: bold; background:transparent; margin-bottom: 10px;")
        layout.addWidget(title_label)

        # Columns layout
        columns_layout = QHBoxLayout()
        layout.addLayout(columns_layout)

        # Colour Column
        color_frame = QFrame(self)
        color_frame.setFrameShape(QFrame.NoFrame)
        color_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        color_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        color_layout = QVBoxLayout(color_frame)
        columns_layout.addWidget(color_frame)

        color_label = QLabel("Go-to map locations", self)
        color_label.setFont(font)
        color_label.setStyleSheet("color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(color_label)
        
        presets = ["Preset1", "Preset2", "Preset3", "Preset4", "Preset5", "Preset6"]
        for preset in presets:
            btn = TexturedButton('not pressed button.png', 'pressed button.png', self)
            btn.setText(preset)
            btn.setTextSize(14)  # Custom text size
            btn.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
            color_layout.addWidget(btn)

        # Adding spacer item for spacing after preset buttons
        spacer_item_after_presets = QSpacerItem(20, 20, QSizePolicy.Minimum, QSizePolicy.Fixed)
        color_layout.addSpacerItem(spacer_item_after_presets)

        # Adding text label before the color buttons
        personalize_label = QLabel("Personalise the colour\nof your Mandelbrot:", self)
        personalize_label.setFont(QFont(self.font_family, 14))
        personalize_label.setStyleSheet("color: black ; font-weight: bold; margin-bottom: 10px;")
        color_layout.addWidget(personalize_label)
        
        # Adding three individual color buttons
        self.color_buttons = []
        for i in range(3):
            color_button = TexturedButton('not pressed button.png', 'pressed button.png', self)
            color_button.setText(f"Colour {i + 1}")
            color_button.setTextSize(14)
            color_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
            color_button.clicked.connect(lambda _, b=color_button: self.choose_color(b))
            color_layout.addWidget(color_button)
            self.color_buttons.append(color_button)
            color_layout.addWidget(color_button)

        # Movement and Zoom Column
        movement_frame = QFrame(self)
        movement_frame.setFrameShape(QFrame.NoFrame)
        movement_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        #movement_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        movement_layout = QVBoxLayout(movement_frame)
        columns_layout.addWidget(movement_frame)

        movement_label = QLabel("Select the map icon for\nfull screen map:", self)
        movement_label.setFont(font)
        movement_label.setStyleSheet(" color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        movement_layout.addWidget(movement_label)

        # Add the new button to show the MAP
        self.show_picture_button = QPushButton(self)
        self.show_picture_button.setIcon(QIcon("minimap.png"))
        self.show_picture_button.setIconSize(QSize(500, 500))
        self.show_picture_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.show_picture_button.setStyleSheet("border: none;")  # Remove the button border
        self.show_picture_button.clicked.connect(self.show_picture_screen)
        movement_layout.addWidget(self.show_picture_button)

        # Add this in the create_mandelbrot_screen method
        self.activate_movement_button = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.activate_movement_button.setText("Control movement")
        self.activate_movement_button.setTextSize(17)
        self.activate_movement_button.setFixedSize(800, 100)
        self.activate_movement_button.clicked.connect(self.activate_movement_mode)
        movement_layout.addWidget(self.activate_movement_button)

        # Other Parameters Column
        params_frame = QFrame(self)
        params_frame.setFrameShape(QFrame.NoFrame)
        params_frame.setStyleSheet("background: transparent;")  # Make the background transparent
        params_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        params_layout = QVBoxLayout(params_frame)
        columns_layout.addWidget(params_frame)

        other_params_label = QLabel("Extra information", self)
        other_params_label.setFont(font)
        other_params_label.setStyleSheet("color: #000000; font-size: 16pt; font-weight: bold; margin-bottom: 10px;")
        params_layout.addWidget(other_params_label)

        other_info_label = QLabel("", self)
        other_info_label.setFont(font)
        other_info_label.setStyleSheet("color: #000000; font-size: 12pt; border: 0px solid #000000; margin-bottom: 10px;")
        other_info_label.setAlignment(Qt.AlignCenter)
        other_info_label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        params_layout.addWidget(other_info_label)

        # Set stretch factors to increase column heights
        for i in range(columns_layout.count()):
            columns_layout.setStretch(i, 1)
        
        # Adding the Back button at the bottom right
        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        self.back_button_juliabrot = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.back_button_juliabrot.setObjectName("back_button_mandelbrot")  # Set a unique object name
        self.back_button_juliabrot.setText("Back")
        self.back_button_juliabrot.setTextSize(14)
        self.back_button_juliabrot.setFixedSize(250, 75)  # Set fixed size for back button
        self.back_button_juliabrot.clicked.connect(self.show_main_menu)
        back_button_layout.addWidget(self.back_button_juliabrot)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom

        self.set_juliabrot_background()
    
    def show_picture_screen(self):
        self.picture_screen = QWidget()
        #self.picture_screen.setStyleSheet("background-image: url('pirate8bitdesk.png'); background-position: center; background-repeat: no-repeat; background-size: contain;")
        self.picture_screen.setStyleSheet("background: #c88d5b;")

        layout = QVBoxLayout(self.picture_screen)
        
        picture_label = QLabel(self.picture_screen)
        picture_pixmap = QPixmap("fullmap.png")
        picture_label.setPixmap(picture_pixmap.scaled(self.size(), Qt.KeepAspectRatio, Qt.SmoothTransformation))
        picture_label.setStyleSheet("background: transparent;")
        picture_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(picture_label)
        

        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        back_button_map = TexturedButton('not pressed button.png', 'pressed button.png', self)
        back_button_map.setObjectName("back_button_map")  # Set a unique object name
        back_button_map.setText("Back")
        back_button_map.setTextSize(14)
        back_button_map.setFixedSize(250, 75)  # Set fixed size for back button
        back_button_map.clicked.connect(lambda: self.main_layout.setCurrentWidget(self.mandelbrot_screen))        
        back_button_layout.addWidget(back_button_map)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom
        
        self.main_layout.addWidget(self.picture_screen)
        self.main_layout.setCurrentWidget(self.picture_screen)
   
    def show_info_screen(self):
        self.info_screen = QWidget()
        self.current_page_index = 0
        self.info_screen.setStyleSheet(f"background-image: url('{self.book_pages[self.current_page_index]}'); background-position: center;")
        font = QFont(self.font_family, 30)# pixel font and initial font zise

        layout = QVBoxLayout(self.info_screen)

        # Columns layout
        columns_layout = QHBoxLayout()
        layout.addLayout(columns_layout)

        #Add left arrow
        self.left_arrow_book = QPushButton(self)
        self.left_arrow_book.setFixedHeight(950)
        self.left_arrow_book.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.left_arrow_book.setIcon(QIcon("leftarrow.png"))
        self.left_arrow_book.setIconSize(QSize(200, 200))  # Adjust the size as needed
        self.left_arrow_book.clicked.connect(self.show_previous_page)
        columns_layout.addWidget(self.left_arrow_book)

        #Used to separate arrows in the book
        text1_label = QLabel("", self)
        text1_label.setFont(font)
        text1_label.setStyleSheet("color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        text1_label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        text1_label.setAlignment(Qt.AlignCenter)
        columns_layout.addWidget(text1_label)
        
        #Add right arrow
        self.right_arrow_book = QPushButton(self)
        self.right_arrow_book.setFixedHeight(950)
        self.right_arrow_book.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.right_arrow_book.setIcon(QIcon("rightarrow.png"))
        self.right_arrow_book.setIconSize(QSize(200, 200))  # Adjust the size as needed
        self.right_arrow_book.clicked.connect(self.show_next_page)
        columns_layout.addWidget(self.right_arrow_book)

        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        back_button_book = TexturedButton('not pressed button.png', 'pressed button.png', self)
        back_button_book.setObjectName("back_button_book")  # Set a unique object name
        back_button_book.setText("Back")
        back_button_book.setTextSize(14)
        back_button_book.setFixedSize(250, 75)  # Set fixed size for back button
        back_button_book.clicked.connect(lambda: self.main_layout.setCurrentWidget(self.mandelbrot_screen))        
        back_button_layout.addWidget(back_button_book)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom
        
        self.main_layout.addWidget(self.info_screen)
        self.main_layout.setCurrentWidget(self.info_screen)

    def show_previous_page(self):
        global current_book_index
        self.current_page_index = (self.current_page_index - 1) % len(self.book_pages)
        self.info_screen.setStyleSheet(f"background-image: url('{self.book_pages[self.current_page_index]}'); background-position: center;")
        current_book_index = self.current_page_index
    
    def show_next_page(self):
        global current_book_index
        self.current_page_index = (self.current_page_index + 1) % len(self.book_pages)
        self.info_screen.setStyleSheet(f"background-image: url('{self.book_pages[self.current_page_index]}'); background-position: center;")
        current_book_index = self.current_page_index

# Themes page and changing character & background
    def create_settings_screen(self):
        self.settings_screen = QWidget()
        self.main_layout.addWidget(self.settings_screen)

        # Set background image
        self.settings_screen.setStyleSheet("background-image: url('8bitmangoback.png'); background-position: center;")

        # Main vertical layout
        layout = QVBoxLayout(self.settings_screen)

        # Title
        title_label = QLabel("Themes", self)
        # Set initial font size
        font = QFont(self.font_family, 30)
        title_label.setFont(font)
        title_label.setAlignment(Qt.AlignCenter)
        title_label.setStyleSheet("color: #61dafb; font-weight: bold; margin-bottom: 10px; background: transparent;")
        layout.addWidget(title_label)

        # Character selection
        char_select_layout = QHBoxLayout()
        layout.addLayout(char_select_layout)

        self.left_arrow_button = QPushButton(self)
        self.left_arrow_button.setFixedHeight(950)
        self.left_arrow_button.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.left_arrow_button.setIcon(QIcon("leftarrow.png"))
        self.left_arrow_button.setIconSize(QSize(200, 200))  # Adjust the size as needed
        self.left_arrow_button.clicked.connect(self.show_previous_character)
        char_select_layout.addWidget(self.left_arrow_button)

        self.character_label = QLabel(self)
        self.character_label.setFixedHeight(950)
        self.character_label.setStyleSheet("background: transparent;")  # Make QLabel background transparent
        self.character_pixmaps = [QPixmap("8bitmango.png")] + [QPixmap("MINE8bit.png")] + [QPixmap("8bitbarbieicon.png")] + [QPixmap("8bitsleepy.png")] + [QPixmap("8bitrocket.png")] + [QPixmap("8bitgametoy.png")]
        self.character_music = ["mandeltheme.wav", "MINEdeltheme.wav", "", "", "midnighttheme.wav", "8bittheme.wav"]
        self.character_label.setAlignment(Qt.AlignCenter)
        self.current_character_index = 0
        self.character_label.setPixmap(self.character_pixmaps[self.current_character_index].scaled(400, 400, Qt.KeepAspectRatio))
        char_select_layout.addWidget(self.character_label)

        self.right_arrow_button = QPushButton(self)
        self.right_arrow_button.setFixedHeight(950)
        self.right_arrow_button.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.right_arrow_button.setIcon(QIcon("rightarrow.png"))
        self.right_arrow_button.setIconSize(QSize(200, 200))  # Adjust the size as needed
        self.right_arrow_button.clicked.connect(self.show_next_character)
        char_select_layout.addWidget(self.right_arrow_button)

        # Adding the Back button at the bottom right
        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        self.back_button_settings = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.back_button_settings.setObjectName("back_button_settings")  # Set a unique object name
        self.back_button_settings.setText("Back")
        self.back_button_settings.setTextSize(14)
        self.back_button_settings.setFixedSize(250, 75)  # Set fixed size for back button
        self.back_button_settings.clicked.connect(self.show_main_menu)
        back_button_layout.addWidget(self.back_button_settings)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom

    def show_previous_character(self):
        global current_background_index
        self.current_character_index = (self.current_character_index - 1) % len(self.character_pixmaps)
        self.character_label.setPixmap(self.character_pixmaps[self.current_character_index].scaled(400, 400, Qt.KeepAspectRatio))
        self.change_music(self.character_music[self.current_character_index])
        self.settings_screen.setStyleSheet(f"background-image: url('{self.character_backgrounds[self.current_character_index]}'); background-position: center;")
        current_background_index = self.current_character_index

    def show_next_character(self):
        global current_background_index
        self.current_character_index = (self.current_character_index + 1) % len(self.character_pixmaps)
        self.character_label.setPixmap(self.character_pixmaps[self.current_character_index].scaled(400, 400, Qt.KeepAspectRatio))
        self.change_music(self.character_music[self.current_character_index])
        self.settings_screen.setStyleSheet(f"background-image: url('{self.character_backgrounds[self.current_character_index]}'); background-position: center;")
        current_background_index = self.current_character_index


#About screen and credits  
    def create_about_screen(self):
        self.about_screen = QWidget()
        self.about_screen.setStyleSheet("background: black;")
        self.main_layout.addWidget(self.about_screen)

        # Create overlay widget to contain the credits and back button
        overlay_layout = QVBoxLayout(self.about_screen)

        # Credits label
        font = QFont(self.font_family, 30)
        self.credits_label = QLabel(self.about_screen)
        self.credits_label.setFont(font)
        self.credits_label.setAlignment( Qt.AlignCenter)
        self.credits_label.setStyleSheet("font-size: 24px; color: white; font-weight: bold; background-color: black;")
        self.credits_label.setText(self.get_credits_text()) 
        self.credits_label.setGeometry(300, 0, 1250, 3000)   
        #self.credits_label.adjustSize()  # Ensure the label size is set correctly  

        # Add stretch to push the back button to the bottom
        overlay_layout.addStretch()

        # Back button
        self.back_button_about = TexturedButton('not pressed button.png', 'pressed button.png', self.about_screen)
        self.back_button_about.setObjectName("back_button_about")  # Set a unique object name
        self.back_button_about.setText("Back")
        self.back_button_about.setTextSize(14)
        self.back_button_about.setFixedSize(250, 75)
        self.back_button_about.clicked.connect(self.show_main_menu)
        overlay_layout.addWidget(self.back_button_about, alignment=Qt.AlignRight)
        #overlay_layout.addWidget(self.back_button_about)

        # Timer for rolling credits
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.scroll_credits)
        self.timer.start(50)  # Adjust the interval for scrolling speed
        
        # Use a QTimer to set the initial position of the credits_label after the widget is shown
        QTimer.singleShot(0, self.reset_credits_position)

    def reset_credits_position(self):
        self.credits_label.move(300, 0)

    def get_credits_text(self):
        return """
MathMatrix Masters presents:
THE FRACTAL DIMENSION

Mandelbrot and Julia hardware developed by:
- Developer 1
- Developer 2
- Developer 3

UI and peripherals developed by:
- Developer 1
- Developer 2
- Developer 3

Special Thanks to:
- ED STOTT THE DEBUGGING GOD

2024 MathMatrix Masters
IMPERIAL COLLEGE LONDON
    """

    def scroll_credits(self):
        current_value = self.credits_label.geometry().y()
        new_value = current_value - 3 # Adjust this value for scrolling speed
        self.credits_label.move(300, new_value)

        # Debug information
        #print("Credits label position:", self.credits_label.geometry())

        # Reset the position when it scrolls off-screen
        if new_value + 1800 < 0:
            self.credits_label.move(300, 0)


#Show pages and set background, music, text colour depending on Themes
    def show_main_menu(self):
        self.main_layout.setCurrentWidget(self.main_menu)
    
    def set_mandelbrot_background(self):
        global current_background_index
        # Set background image
        self.mandelbrot_screen.setStyleSheet(f"background-image: url('{self.character_backgrounds[current_background_index]}'); background-position: center;")

        # Set text color based on the background
        text_color = self.character_text_colors[current_background_index]
        self.update_text_color(text_color)
        
    def set_juliabrot_background(self):
        global current_background_index
        # Set background image
        self.juliabrot_screen.setStyleSheet(f"background-image: url('{self.character_backgrounds[current_background_index]}'); background-position: center;")

        # Set text color based on the background
        text_color = self.character_text_colors[current_background_index]
        self.update_text_color_julia(text_color)

    def update_text_color_julia(self, color):
        # Update the text color for all relevant labels and buttons in the screen depending on Theme
        for widget in self.juliabrot_screen.findChildren(QLabel):
            widget.setStyleSheet(f"color: {color}; background: transparent; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
            
    def update_text_color(self, color):
        # Update the text color for all relevant labels and buttons in the screen depending on Theme
        for widget in self.mandelbrot_screen.findChildren(QLabel):
            widget.setStyleSheet(f"color: {color}; background: transparent; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        
    def show_mandelbrot_screen(self):
        self.set_mandelbrot_background()
        self.main_layout.setCurrentWidget(self.mandelbrot_screen)
    
    def show_julia_screen(self):
        self.set_juliabrot_background()
        self.main_layout.setCurrentWidget(self.juliabrot_screen)
    
    def show_settings_screen(self):
        self.main_layout.setCurrentWidget(self.settings_screen)
    
    def show_about_screen(self):
        # Reset the credits label position to the bottom of the screen
        self.reset_credits_position()
        self.main_layout.setCurrentWidget(self.about_screen)

#Colour popup 
    def choose_color(self, button):
        color = QColorDialog.getColor()
        if color.isValid():
            button.setStyleSheet(f"background-color: {color.name()}")
            button.setText(color.name())

    def activate_movement_mode(self):
        print("Movement Activated")
        self.movement_mode_active = True
        # Open a TCP connection to the server
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_ip = "192.168.2.99"
        server_port = 12337
        self.client_socket.connect((server_ip, server_port))

        # Send Inital messages
        preset = "P" + str(self.current_preset + 1)
        self.client_socket.send(preset.encode())
        #self.client_socket.send(b"start")
        theme = "T" + str(current_background_index)
        self.client_socket.send(theme.encode())
        print("Initial messages sent: ", preset, theme)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = FractalExplorer()
    ex.show()
    sys.exit(app.exec_())