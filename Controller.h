#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Graphics.h"
#include "Button.h"
#include "PlaceHolder.h"
#include "Map.h"


class Controller
{
public:
	Controller(); //constructs the object.
	void setMap(int width, int height);//sets basic map.
	void drawMap(); //draws the graphic map.
	void setButtons(int width); //sets button locations and textures.
	bool clicked(sf::Window& window, sf::Sprite sprite);//checks if a tile was clicked.
	void saveBoard();//saves the board to a text file.
	void clearBoard(sf::RenderWindow &window);//clears the board and creates a new one.
	bool checkDoorRobot(char id);//checks if door or robot are placed.
	void loadFromFile(std::ifstream &file);//loads existing level from a file.
	void information();//displays information to the user.
	~Controller();
private:
	std::vector<std::vector<Map>> m_map;//holds the graphic map.
	std::vector<Button> m_buttons;//holds the toolbar buttons.
	sf::Sprite m_background;//holds the background tile.
	std::vector<Button> m_blanks;//fills out the empty spots next to the toolbar.
	PlaceHolder m_action;//holds the specific action taking place.
	Graphics graphics_type;//holds the texturs for the buttons.
	sf::Sprite Handler;//helps with special effects.

	//these variables help control the flow and existence of certain objects.
	bool m_robotExists = false;//for robot.
	bool m_doorExists = false;//for door.
	bool firstClick = false;//for control.
};

