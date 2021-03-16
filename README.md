# Bomberman-level-builder
A level builder for my Bomberman project


## Design
### The Classes created for this program:
*	Graphics: This class holds all the textures and loads them from the file. That way we could load all the graphic objects at once in one place by the Graphics constructor. All other classes that need to use any graphic object will use them through this class.
*	Button: This class is used to create the Toolbar. The constructor of the class defines which object and action goes to each button. Other classes reference the buttons to get character id’s and images.
*	Map: This class is used to make the game map. It also makes the game map clickable in our case to place an object.
*	Place holder: This class is used to hold a place for a specific action, it is easy to change because it is designed to just hold data for a short period of time.
*	Controller: This class is used to manage and connect all the different elements in the program

### Files created:
*	Main.cpp- This file holds the main function and includes the sfml related files.
*	Graphics.h/.cpp- This file holds the values and functions for the Graphics class.
*	Button.h/.cpp- This file holds the values and functions for the Button class.
*	Map.h/.cpp- This file holds the values and functions for the Map class.
*	Controller.h/.cpp- This file holds the values and functions for the Controller class.
*	PlaceHolder.h/.cpp- This file holds the values and functions for the PlaceHolder class.


### Data structures
- Vectors/2D Vectors: These data structures hold all of the data we use- maps, toolbars and buttons. 


### Installation
I am working on a setup.exe <br>
This project was written using C++ and SFML.
