#pragma once
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <iostream>
#include <fstream>
#include <ostream>
#include "Controller.h"


int main()
{
	int width, height;
	Controller map;//controls the flow of the build process.
	std::ifstream file;//holds the file if it exists.
	file.open("Board.bomb.txt");
	if (file.is_open())//checks if the file exists.
		map.loadFromFile(file);
	else//if not, build the file.
	{
		map.information();
		std::cout << "Please enter width and height:" << std::endl;
		std::cin >> width >> height;
		map.setMap(width, height);
	}
	
	map.drawMap();

	return 0;
}



