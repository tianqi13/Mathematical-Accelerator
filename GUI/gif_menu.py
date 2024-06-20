
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QVBoxLayout,QHBoxLayout, QWidget, QStackedLayout, QFrame, QSizePolicy, QColorDialog, QSpacerItem, QLineEdit
from PyQt5.QtGui import QMovie, QFontDatabase, QFont, QPixmap, QPainter, QIcon, QCursor, QMouseEvent, QDoubleValidator
from PyQt5.QtCore import Qt, QSize, QTimer, QEvent, QRegExp
from PyQt5.QtMultimedia import QSound
import pygame
from pynput.mouse import Button as MouseButton, Controller as MouseController

import time
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
        
        self.character_backgrounds = ["8bitmangoback.png", "MINEdelback.png", "8bitbackwithbarbie_final.png", "8bitmidnightback.png", "moonbackground.png","8bitback_final_final_Red.png" ]
        self.character_text_colors = ["#000000", "#000000", "#000000", "#00FFFF", "#FFFF00", "#FFFFFF"]
        self.mandelbrot_book_pages = ["first_page.png", "second_page.png", "third_page.png"]
        self.julia_book_pages = ["julia_first_page.png", "julia_second_page.png", "julia_third_page"]

        self.zoom_factor = "1.0000"
        self.create_main_menu()
        self.create_mandelbrot_screen()
        self.create_julia_screen()
        self.create_settings_screen() 
        self.create_about_screen()
        self.create_controls_screen()

        self.show_main_menu()
        self.showMaximized()  # Make the window fullscreen
        self.client_socket = None
        self.current_preset = 0
        #self.zoom_factor = 1.0
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


            s = False
            if self.movement_mode_active:
                
                #print(f"L-stick X: {axis_x}, Y: {axis_y}, R2: {axis_r2}, L2: {axis_l2}")
                move_left = axis_x < -threshold
                move_right = axis_x > threshold
                move_up = axis_y < -threshold
                move_down = axis_y > threshold
                zoom_in  = axis_r2 > threshold
                zoom_out = axis_l2 > threshold
                #time.sleep(0.1)  # Add a small delay to prevent multiple inputs
                if move_left and move_down:
                    #print("Diagonal movement: Move left and down")
                    # Send the movement command to the server
                    print("Move Down")
                    self.client_socket.send(b"move_left_down")
                    s = True
                elif move_left and move_up:
                    #print("Diagonal movement: Move left and up")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_left_up")
                    s = True
                elif move_right and move_down:
                    #print("Diagonal movement: Move right and down")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right_down")
                    s = True
                elif move_right and move_up:
                    #print("Diagonal movement: Move right and up")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right_up")
                    s = True
                elif move_left:
                    #print("Move left")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_left")
                    s = True
                elif move_right:
                    #print("Move right")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_right")
                    s = True
                elif move_up:
                    #print("Move up")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_up")
                    s = True
                elif move_down:
                    #print("Move down")
                    # Send the movement command to the server
                    self.client_socket.send(b"move_down")
                    s = True
                elif zoom_in:
                    #print("Zoom in")
                    # Send the movement command to the server
                    self.client_socket.send(b"zoom_in")
                    s = True
                elif zoom_out:
                    #print("Zoom out")
                    # Send the movement command to the server
                    self.client_socket.send(b"zoom_out")
                    s = True
                #else:
                    #print("No movement")
                #senfing_state = False
                # If we get a response in the next second:
                if s:
                    print("Waiting for response")
                    response = self.client_socket.recv(1024)
                    self.zoom_factor = str(response.decode())
                    self.update_bubble_index()
                    print(self.zoom_factor)
                
                s = False
                # Check if OPTIONS button is pressed to exit movement mode
                #if self.joystick.get_button(2):  # Square button
                    # Reset the original position
                    #print("Resetting position")
                    #self.client_socket.send(b"reset")

                if self.joystick.get_button(2):  # SQUARE button
                    # Reset the original position
                    print("Resetting position")
                    self.client_socket.send(b"reset")
                if self.joystick.get_button(6):  # OPTIONS button
                    # Close connection
                    print("Exiting movement mode")
                    self.client_socket.send(b"close")
                    self.client_socket.close()
                    print("Connection closed")
                    self.movement_mode_active = False
                    self.client_socket = None
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
                        self.set_juliabrot_background()
                    self.r1_button_pressed = False

                # Check if L1 button is pressed to change theme to the previous one
                if self.joystick.get_button(9):  # R1 button
                    self.l1_button_pressed = True
                else:
                    if self.l1_button_pressed:
                        self.show_previous_character() #Also want to change mandelbrot&Julia backgrounds live
                        self.set_mandelbrot_background()
                        self.set_juliabrot_background()
                    self.l1_button_pressed = False
                
                #Note that we could only change page of current book and not of both (mandelbrot info and julia info) at the same time
                # Check if LEFT button is pressed to change BOOK PAGE to the previous one
                if self.joystick.get_button(13):  # LEFT button
                    self.left_button_pressed = True
                else:
                    if self.left_button_pressed:
                        if self.screen_flag == True:
                            self.show_previous_page() #PREVIOUS PAGE MANDELBROT
                        else:
                            self.show_previous_page_julia() #PREVIOUS PAGE JULIA
                    self.left_button_pressed = False
                
                # Check if RIGHT button is pressed to change BOOK PAGE to the next one
                if self.joystick.get_button(14):  # RIGHT button
                    self.right_button_pressed = True
                else:
                    if self.right_button_pressed:
                        if self.screen_flag == True:
                            self.show_next_page() #NEXT PAGE MANDELBROT
                        else:
                            self.show_next_page_julia() #NEXT PAGE JULIA
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
    
    def update_bubble_index(self):
        str_value = str(self.zoom_factor).split('.')
         
        # If there's no decimal part, return 0
        if len(str_value) == 1:
            return 0
        
        # Extract the decimal part
        decimal_part = str_value[1]
        
        # Count the number of leading zeros in the decimal part
        count = 0
        for digit in decimal_part:
            if digit == '0':
                count += 1
            else:
                break
        print(count)
        if str(self.zoom_factor)[-4]  == "e":
            count = int(self.zoom_factor[-1])
        count = min(count, 6)
        self.current_info_bubble_index = count
        self.info_bubble.setPixmap(self.info_bubble_pixmaps[self.current_info_bubble_index].scaled(200, 200, Qt.KeepAspectRatio))
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
        button_layout.setAlignment(Qt.AlignCenter)
        button_layout.setSpacing(20)  # Adjust spacing between buttons as needed

        button_width = 500
        button_height = 100

        spacer_item = QSpacerItem(20, 400, QSizePolicy.Minimum, QSizePolicy.Fixed)
        button_layout.addSpacerItem(spacer_item)

        self.mandelbrot_button = TexturedButton('not pressed button.png', 'pressed button.png', self.main_menu)
        self.mandelbrot_button.setText("Mandelbrot Set")
        self.mandelbrot_button.setFixedSize(button_width, button_height)
        self.mandelbrot_button.clicked.connect(self.show_mandelbrot_screen)
        button_layout.addWidget(self.mandelbrot_button)

        self.julia_button = TexturedButton('not pressed button.png', 'pressed button.png', self.main_menu)
        self.julia_button.setText("Julia Set")
        self.julia_button.setFixedSize(button_width, button_height)
        self.julia_button.clicked.connect(self.show_julia_screen)
        button_layout.addWidget(self.julia_button)

        self.settings_button = TexturedButton('not pressed button.png', 'pressed button.png', self.main_menu)
        self.settings_button.setText("Themes")
        self.settings_button.setFixedSize(button_width, button_height)
        self.settings_button.clicked.connect(self.show_settings_screen)
        button_layout.addWidget(self.settings_button)

        self.about_button = TexturedButton('not pressed button.png', 'pressed button.png', self.main_menu)
        self.about_button.setText("About")
        self.about_button.setFixedSize(button_width, button_height)
        self.about_button.clicked.connect(self.show_about_screen)
        button_layout.addWidget(self.about_button)

        self.controls_button = TexturedButton('not pressed button.png', 'pressed button.png', self.main_menu)
        self.controls_button.setText("Controls")
        self.controls_button.setFixedSize(button_width, button_height)
        self.controls_button.clicked.connect(self.show_controls_screen)
        button_layout.addWidget(self.controls_button)

        self.main_layout.addWidget(self.main_menu)
        self.main_menu.setLayout(button_layout)

    def resizeEvent(self, event):
        self.gif_label.setGeometry(0, 0, self.width(), self.height())
        #self.gif_label_about.setGeometry(0, 0, self.width(), self.height())
        button_width = 500
        button_height = 100
        button_spacing = 50
        self.title_label.setGeometry((self.width() - 1250) // 2, 100, 1250, 200)
        """self.mandelbrot_button.setGeometry((self.width() - button_width) // 2, 400, button_width, button_height)
        self.julia_button.setGeometry((self.width() - button_width) // 2, 400 + button_height + button_spacing, button_width, button_height)
        self.settings_button.setGeometry((self.width() - button_width) // 2, 400 + 2 * (button_height + button_spacing), button_width, button_height)
        self.about_button.setGeometry((self.width() - button_width) // 2, 400 + 3 * (button_height + button_spacing), button_width, button_height)
        """
        super().resizeEvent(event)


#Mandelbrot, Julia pages and MAP and BOOK screens for Mandelbrot
    def create_mandelbrot_screen(self):
        self.screen_flag = True
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
        
        presets = ["Elephant ", "Seahorse", "Julia 1", "Whirlpool", "Mini", "Julia 2"]
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
        #test
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
        self.activate_movement_button.clicked.connect(self.update_bubble_index)
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
        # for decimal places in zoom factor - get bubble index:
        
        self.info_bubble = QLabel(self)
        self.info_bubble.setFixedHeight(490)
        self.info_bubble.setFixedWidth(300)
        self.info_bubble.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.info_bubble_pixmaps = [QPixmap("comparisoearthgood.png")] + [QPixmap("comparisoplutogood.png")] + [QPixmap("comparisomoongood.png")] + [QPixmap("comparisowizardgood")] + [QPixmap("comparisobeachballgood.png")] + [QPixmap("comparisobasketballgood.png")] + [QPixmap("comparisotennisballgood.png")] + [QPixmap("comparisoatomgood.png")]
        self.current_info_bubble_index = min(0, 7) 
        self.info_bubble.setPixmap(self.info_bubble_pixmaps[self.current_info_bubble_index].scaled(200, 200, Qt.KeepAspectRatio)) 
        #self.info_bubble.clicked.connect(self.show_previous_character)
        params_layout.addWidget(self.info_bubble)
        
        # Adding spacer item for spacing after preset buttons
        spacer_item_after_bubble = QSpacerItem(20, 20, QSizePolicy.Minimum, QSizePolicy.Fixed)
        params_layout.addSpacerItem(spacer_item_after_bubble)
        
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
        self.screen_flag = False
        self.juliabrot_screen = QWidget()
        self.main_layout.addWidget(self.juliabrot_screen)

        # Main vertical layout
        layout = QVBoxLayout(self.juliabrot_screen)

        # Title
        title_label = QLabel("JULIA SET", self)
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

        color_label = QLabel("Suggested Julia Sets", self)
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
        personalize_label = QLabel("Personalise the colour\nof your Julia set:", self)
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
        #movement_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        movement_layout = QVBoxLayout(movement_frame)
        columns_layout.addWidget(movement_frame)

        movement_label = QLabel("Select your own coordinates\nbetween the limits:", self)
        movement_label.setFont(font)
        movement_label.setStyleSheet(" color: #000000; font-size: 14pt; font-weight: bold; margin-bottom: 10px;")
        movement_layout.addWidget(movement_label)

        # Adding a spacer item to push the control movement button down
        spacer_item1 = QSpacerItem(20, 200, QSizePolicy.Minimum, QSizePolicy.Minimum)
        movement_layout.addSpacerItem(spacer_item1)

        # Adding input fields for coordinates
        self.a0_input = QLineEdit(self)
        self.a0_input.setPlaceholderText("Enter a0 (-2 to 2)")
        self.a0_input.setValidator(QDoubleValidator(-2.0, 2.0, 5, self.a0_input))
        self.a0_input.setStyleSheet(f"font-size: 14pt; font-family: {self.font_family};")
        self.a0_input.setStyleSheet(f"QLineEdit {{ font-size: 14pt; font-family: {self.font_family}; }} QLineEdit::placeholder {{ color: grey; font-size: 14pt; font-family: {self.font_family}; }}")
        movement_layout.addWidget(self.a0_input)

        self.b0_input = QLineEdit(self)
        self.b0_input.setPlaceholderText("Enter b0 (-1.5 to 1.5)")
        self.b0_input.setValidator(QDoubleValidator(-1.5, 1.5, 5, self.b0_input))
        self.b0_input.setStyleSheet(f"font-size: 14pt; font-family: {self.font_family};")
        self.b0_input.setStyleSheet(f"QLineEdit {{ font-size: 14pt; font-family: {self.font_family}; }} QLineEdit::placeholder {{ color: grey; font-size: 14pt; font-family: {self.font_family}; }}")
        movement_layout.addWidget(self.b0_input)


        # Adding Enter button below the input fields
        self.enter_button = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.enter_button.setText("Enter")
        self.enter_button.setTextSize(17)
        self.enter_button.setFixedSize(800, 100)
        self.enter_button.clicked.connect(self.handle_enter_button)
        movement_layout.addWidget(self.enter_button)

        # Adding a spacer item to push the control movement button down
        spacer_item = QSpacerItem(20, 250, QSizePolicy.Minimum, QSizePolicy.Minimum)
        movement_layout.addSpacerItem(spacer_item)

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
        self.show_julia_info_button = QPushButton(self)
        self.show_julia_info_button.setIcon(QIcon("8bitbook.png"))
        self.show_julia_info_button.setIconSize(QSize(500, 500))
        self.show_julia_info_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.show_julia_info_button.setStyleSheet("border: none;")  # Remove the button border
        self.show_julia_info_button.clicked.connect(self.show_julia_info_screen)
        params_layout.addWidget(self.show_julia_info_button)

        # Set stretch factors to increase column heights
        for i in range(columns_layout.count()):
            columns_layout.setStretch(i, 1)
        
        # Adding the Back button at the bottom right
        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        self.back_button_juliabrot = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.back_button_juliabrot.setObjectName("back_button_julia")  # Set a unique object name
        self.back_button_juliabrot.setText("Back")
        self.back_button_juliabrot.setTextSize(14)
        self.back_button_juliabrot.setFixedSize(250, 75)  # Set fixed size for back button
        self.back_button_juliabrot.clicked.connect(self.show_main_menu)
        back_button_layout.addWidget(self.back_button_juliabrot)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom

        self.set_juliabrot_background()
    def handle_enter_button(self):
        a0_value = self.a0_input.text()
        b0_value = self.b0_input.text()
        # You can add the logic to handle the input values here
        print(f"Entered a0: {a0_value}, b0: {b0_value}")

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
        self.info_screen.setStyleSheet(f"background-image: url('{self.mandelbrot_book_pages[self.current_page_index]}'); background-position: center;")
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
    def show_julia_info_screen(self):
        self.julia_info_screen = QWidget()
        self.current_page_index = 0
        self.julia_info_screen.setStyleSheet(f"background-image: url('{self.julia_book_pages[self.current_page_index]}'); background-position: center;")
        font = QFont(self.font_family, 30)# pixel font and initial font zise

        layout = QVBoxLayout(self.julia_info_screen)

        # Columns layout
        columns_layout = QHBoxLayout()
        layout.addLayout(columns_layout)

        #Add left arrow
        self.left_arrow_book = QPushButton(self)
        self.left_arrow_book.setFixedHeight(950)
        self.left_arrow_book.setStyleSheet("QPushButton { background: transparent; border: none; }")  # Make background transparent and remove border
        self.left_arrow_book.setIcon(QIcon("leftarrow.png"))
        self.left_arrow_book.setIconSize(QSize(200, 200))  # Adjust the size as needed
        self.left_arrow_book.clicked.connect(self.show_previous_page_julia)
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
        self.right_arrow_book.clicked.connect(self.show_next_page_julia)
        columns_layout.addWidget(self.right_arrow_book)

        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        back_button_book = TexturedButton('not pressed button.png', 'pressed button.png', self)
        back_button_book.setObjectName("back_button_julia_book")  # Set a unique object name
        back_button_book.setText("Back")
        back_button_book.setTextSize(14)
        back_button_book.setFixedSize(250, 75)  # Set fixed size for back button
        back_button_book.clicked.connect(lambda: self.main_layout.setCurrentWidget(self.juliabrot_screen))        
        back_button_layout.addWidget(back_button_book)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom
        
        self.main_layout.addWidget(self.julia_info_screen)
        self.main_layout.setCurrentWidget(self.julia_info_screen)
    
    def show_previous_page(self):
        global current_book_index
        self.current_page_index = (self.current_page_index - 1) % len(self.mandelbrot_book_pages)
        self.info_screen.setStyleSheet(f"background-image: url('{self.mandelbrot_book_pages[self.current_page_index]}'); background-position: center;")
        current_book_index = self.current_page_index
    def show_next_page(self):
        global current_book_index
        self.current_page_index = (self.current_page_index + 1) % len(self.mandelbrot_book_pages)
        self.info_screen.setStyleSheet(f"background-image: url('{self.mandelbrot_book_pages[self.current_page_index]}'); background-position: center;")
        current_book_index = self.current_page_index

    def show_previous_page_julia(self):
        global current_book_index
        self.current_page_index = (self.current_page_index - 1) % len(self.mandelbrot_book_pages)
        self.julia_info_screen.setStyleSheet(f"background-image: url('{self.julia_book_pages[self.current_page_index]}'); background-position: center;")
        current_book_index = self.current_page_index
    def show_next_page_julia(self):
        global current_book_index
        self.current_page_index = (self.current_page_index + 1) % len(self.mandelbrot_book_pages)
        self.julia_info_screen.setStyleSheet(f"background-image: url('{self.julia_book_pages[self.current_page_index]}'); background-position: center;")
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
        self.character_music = ["mandeltheme.wav", "MINEdeltheme.wav", "mandeltheme.wav", "realmidnighttune.wav", "midnighttheme.wav", "8bittheme.wav"]
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

    def create_controls_screen(self):
        self.controls_screen = QWidget()
        self.main_layout.addWidget(self.controls_screen)

        # Set background image
        self.controls_screen.setStyleSheet("background-image: url('controls.png'); background-position: center;")

        # Main vertical layout
        layout = QVBoxLayout(self.controls_screen)

        label = QLabel("")
        label.setStyleSheet(" background: transparent;")
        label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Ensure the frame expands vertically
        layout.addWidget(label)

        # Adding the Back button at the bottom right
        back_button_layout = QHBoxLayout()
        back_button_layout.addStretch()  # Add a stretch to push the button to the right
        self.back_button_controls = TexturedButton('not pressed button.png', 'pressed button.png', self)
        self.back_button_controls.setObjectName("back_button_controls")  # Set a unique object name
        self.back_button_controls.setText("Back")
        self.back_button_controls.setTextSize(14)
        self.back_button_controls.setFixedSize(250, 75)  # Set fixed size for back button
        self.back_button_controls.clicked.connect(self.show_main_menu)
        back_button_layout.addWidget(self.back_button_controls)
        layout.addLayout(back_button_layout, 1)  # Add back button layout to the main layout and stretch to bottom
    
    def show_controls_screen(self):
        self.main_layout.setCurrentWidget(self.controls_screen)


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
        self.screen_flag = True
        self.set_mandelbrot_background()
        self.main_layout.setCurrentWidget(self.mandelbrot_screen)
    
    def show_julia_screen(self):
        self.screen_flag = False
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

        # Extract the red, green, and blue components
        red = color.red()
        green = color.green()
        blue = color.blue()
        
        # Rearrange to 0xBBGGRR format
        new_color = (blue << 16) | (green << 8) | red
        
        # Shift left by 5 bits and add 7
        self.modified_color = (new_color << 5) + 7
        
        if color.isValid():
            button.setStyleSheet(f"background-color: {color.name()}")
            button.setText(color.name())

    def activate_movement_mode(self):
        print("Movement Activated")
        self.movement_mode_active = True
        # Open a TCP connection to the server
        if self.client_socket is None: 
            self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server_ip = "192.168.2.99"
            server_port = 12344
            self.client_socket.connect((server_ip, server_port))

        # Send Inital messages
        preset = "P" + str(self.current_preset + 1)
        self.client_socket.send(preset.encode())
        self.client_socket.send()
        #self.client_socket.send(b"start")
        response = self.client_socket.recv(1024)
        print(response)
        theme = "T" + str(current_background_index)
        self.client_socket.send(theme.encode())

        response = self.client_socket.recv(1024)

        is_julia = self.screen_flag == False
        if self.screen_flag:
            is_julia = "0"
        else:
            is_julia = "1"
        julia = "J"  + is_julia # + IS JULIA SET
        self.client_socket.send(julia.encode())

        response = self.client_socket.recv(1024)

        print("Initial messages sent: ", preset, theme, julia)
        
        if hasattr(self, 'modified_color'):
            color_message = f"C{self.modified_color}"
            self.client_socket.send(color_message.encode())
            response = self.client_socket.recv(1024)
            print("Color message sent: ", color_message, " Response: ", response)
    
    
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = FractalExplorer()
    ex.show()
    sys.exit(app.exec_())
