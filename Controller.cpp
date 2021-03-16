#include "Controller.h"

/*This function constructs the object.
  Paramaters:
  Return:
  */
Controller::Controller()
{
	m_background = *graphics_type.getSprite(8);//sets background tile.
	m_background.setTextureRect({ 0, 0, 55, 55 });
	m_action.setObject(&m_background);//sets basic action.
}

/*This function sets the basic graphic map of the object.
  Paramaters: width and height.
  Return:
  */
void Controller::setMap(int width, int height)
{
	m_map.resize(height);
	m_blanks.resize(width);//for the tiles on the side of the toolbar.

	for (size_t i = 0; i < height; i++)
	{
		m_map[i].resize(width);
		for (size_t j = 0; j < width; j++)
		{
			m_map[i][j].setObject(m_background.getTexture());
			m_map[i][j].setLocation({ (float)55 * j, (float)55 * (i + 1) + 10 });
		}
	}
	setButtons(width);//sets the toolbar.
}

/*This function draws the graphic map of the object.
  Paramaters:
  Return:
  */
void Controller::drawMap()
{
	int scalar;//to allign the toolbar correctly.
	sf::RenderWindow window(sf::VideoMode((unsigned int)m_map[0].size() * 55, (unsigned int)m_map.size() * 55 + 10), "BomberMan Level Editor");

	if (m_map.size() < 8)//sets the scalar.
		scalar = 8 - (int)m_map.size();
	else
		scalar = 0;
	window.setSize({window.getSize().x + scalar*55, window.getSize().y + 55 });

	while (window.isOpen())//controlls the flow of the program.
	{
		// handles events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (size_t i = 0; i < m_buttons.size(); i++)//finds the button pressed from the toolbar and sets the appropriate action.
					if (m_buttons[i].clicked(window))
					{
						firstClick = true;
						m_action.setObject(m_buttons[i].getAction());
						m_action.setId(m_buttons[i].getId());
						Handler = *graphics_type.getSprite((int)i);
						break;
					}
				if (m_action.getId() == 'S')//if the action is "save".
				{
					saveBoard();
					continue;
				}
				if (m_action.getId() == 'C')//if the action is "clear".
				{
					clearBoard(window);
					break;
				}

				for(size_t i = 0; i < m_map.size(); i++)//makes changes to the graphic map according to the action.
					for (size_t j = 0; j < m_map[i].size(); j++)
					{
						if (clicked(window, *m_map[i][j].getObject()))
						{							
							if (checkDoorRobot(m_map[i][j].getId()))
								break;
					
							m_map[i][j].setObject(m_action.getObject()->getTexture());
							m_map[i][j].setId(m_action.getId());					
						}
					}

			}
			if (event.type == sf::Event::Resized)//keeps all the objects in place.
				window.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
	
			if (event.type == sf::Event::Closed)//closes window.
				window.close();
		}

		// draw the map
		window.clear();

		//sets the rectangle behind the buttons so it would have a background.(created every time to match the maps size)
		for (size_t i=0; i < m_map.size(); i++) 
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(55, 55));
			rectangle.setPosition(55 * (float)i, 5);
			rectangle.setTexture(m_background.getTexture());
			window.draw(rectangle);
		}

		for (size_t i = 0; i < m_map.size(); i++)//adds shading effect to map.
			for (size_t j = 0; j < m_map[i].size(); j++)
			{
				if (m_map[i][j].getObject()->getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				{
					m_map[i][j].getObject()->setColor(sf::Color(255, 255, 255, 128));
				}
				else
				{
					m_map[i][j].getObject()->setColor(sf::Color::White);
				}
				window.draw(*m_map[i][j].getObject());
			}

		for (size_t i = 0; i < m_buttons.size(); i++)//adds shading effect to the toolbar.
		{
			if (m_buttons[i].getImage()->getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				m_buttons[i].getImage()->setColor(sf::Color(255, 255, 255, 128));
			else
				m_buttons[i].getImage()->setColor(sf::Color::White);
			window.draw(*m_buttons[i].getImage());
		}

		if ((m_action.getId() != 'S') && (m_action.getId() != 'C') && (firstClick))//adds the drag effect when a button is selected.
		{
			window.setMouseCursorVisible(false);
			Handler.setPosition({ (float)sf::Mouse::getPosition(window).x - 27, (float)sf::Mouse::getPosition(window).y - 27 });

			if (sf::Mouse::getPosition(window).y < 65)
			{
				Handler.setColor(sf::Color::Transparent);
				window.setMouseCursorVisible(true);
			}
			else
				Handler.setColor(sf::Color(255, 255, 255, 128));
			window.draw(Handler);
		}
		else
			window.setMouseCursorVisible(true);

		window.display();
	}
}

/*This function builds the toolbar.
  Paramaters: width of the map.
  Return:
  */
void Controller::setButtons(int width)
{	
	int scalar = 0;//to scale the toolbar and put it in the middle.
	m_buttons.resize(8);	

	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setImage(graphics_type.getSprite((int)i));
		if (width > 8)
			scalar = width - 8;
		m_buttons[i].setLocation({ (float)(i * 55 + (scalar * 55) * 0.5), 5.0f });

		switch (i)//assigns different actions to the right button.
		{
		case 0:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('/');
			break;
		case 1:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('!');
			break;
		case 2:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('@');
			break;
		case 3:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('#');
			break;
		case 4:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('D');
			break;
		case 5:
			m_buttons[i].setAction(&m_background);
			m_buttons[i].setId(' ');
			break;
		case 6:
			m_buttons[i].setAction(&m_background);
			m_buttons[i].setId('C');
			break;
		case 7:
			m_buttons[i].setId('S');
			break;
		}
	}
}

/*This function checks if a tile was clicked.
  Paramaters: The window we operate in, the tile to check.
  Return: true if clicked on and false if not.
  */
bool Controller::clicked(sf::Window & window, sf::Sprite sprite)
{
	if (sprite.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
		return true;
	return false;
}

/*This function saves the map to a text file.
  Paramaters:
  Return:
  */
void Controller::saveBoard()
{
	std::ofstream saveFile;
	saveFile.open("Board.Bomb.txt");
	
	for (size_t i = 0; i < m_map.size(); i++)
	{
		for (size_t j = 0; j < m_map[i].size(); j++)
			saveFile << m_map[i][j].getId();

		if(i < m_map.size()-1)
			saveFile << std::endl;
	}
	saveFile.close();
}

/*This function clears the map to make a new one.
  Paramaters: The window we operate in.
  Return:
  */
void Controller::clearBoard(sf::RenderWindow &window)
{
	int scalar;
	for (size_t i = 0; i < m_map.size(); i++)//clears the map.
		for (size_t j = 0; j < m_map[i].size(); j++)
		{
			m_map[i][j].setObject(m_action.getObject()->getTexture());
			m_map[i][j].setId(' ');
			m_robotExists = false;
			m_doorExists = false;
		}

	std::cout << "Please enter new width and height:" << std::endl;
	information();//information for the user

	int width, height;
	std::cin >> width >> height;

	setMap(width, height);//create new map
	window.setSize({ (unsigned int)m_map[0].size() * 55, (unsigned int)m_map.size() * 55 + 10 });
	if (m_map.size() < 8)
		scalar = 8 - (int)m_map.size();
	else
		scalar = 0;
	window.setSize({ window.getSize().x + scalar * 55, window.getSize().y + 55 });

	m_action.setId('S');//so it will not trigger any response when clicked on the map again.
}

/*This function checks and regulates if door and robot were placed on map.
  Paramaters: The id of current tile.
  Return:True if can't put tile there, false if can.
  */
bool Controller::checkDoorRobot(char id)
{
	if ((m_action.getId() == '/'))
		if (m_robotExists)
			return true;
		else
		{
			if (id == 'D')
				m_doorExists = false;
			m_robotExists = true;
			return false;
		}

	if ((m_action.getId() == 'D'))
		if (m_doorExists)
			return true;
		else
		{
			if (id == '/')
				m_robotExists = false;
			m_doorExists = true;
			return false;
		}

	if ((m_action.getId() != '/') && (id == '/'))
	{
		m_robotExists = false;
		return false;
	}

	if ((m_action.getId() != 'D') && (id == 'D'))
	{
		m_doorExists = false;
		return false;
	}

	
	return false;
}

/*This function loads existing map from a file.
  Paramaters: The file.
  Return:
  */
void Controller::loadFromFile(std::ifstream &file)
{
	std::vector<std::string> textMap;//creates a text map. 
	size_t i = 0;
	std::string c;//holds a string from the file.

	while (!file.eof())//gets all the text in the text map.
	{
		std::getline(file, c);
		textMap.push_back(c);
	}

	m_map.resize(textMap.size());//resize graphic map.
	m_blanks.resize(textMap[0].size());//resize blanks for the toolbar background.
	setButtons((int)textMap[0].size());//sets the buttons.

	for (size_t i = 0; i < m_map.size(); i++)//set the graphic map according to the text map.
	{
		m_map[i].resize(textMap[i].size());
		for (size_t j = 0; j < m_map[i].size(); j++)
		{
			m_map[i][j].setLocation({ (float)55 * j, (float)55 * (i + 1) + 10 });
			switch (textMap[i][j])
			{
			case '/':
				m_map[i][j].setObject(m_buttons[0].getImage()->getTexture());
				m_map[i][j].setId(m_buttons[0].getId());
				m_robotExists = true;
				break;
			case '!':
				m_map[i][j].setObject(m_buttons[1].getImage()->getTexture());
				m_map[i][j].setId(m_buttons[1].getId());
				break;
			case '@':
				m_map[i][j].setObject(m_buttons[2].getImage()->getTexture());
				m_map[i][j].setId(m_buttons[2].getId());
				break;
			case '#':
				m_map[i][j].setObject(m_buttons[3].getImage()->getTexture());
				m_map[i][j].setId(m_buttons[3].getId());
				break;
			case 'D':
				m_map[i][j].setObject(m_buttons[4].getImage()->getTexture());
				m_map[i][j].setId(m_buttons[4].getId());
				m_doorExists = true;
				break;
			case '\0':
				m_map[i][j].setObject(m_buttons[5].getAction()->getTexture());
				m_map[i][j].setId(' ');
				break;
			case ' ':
				m_map[i][j].setObject(m_buttons[5].getAction()->getTexture());
				m_map[i][j].setId(' ');
				break;
			}	
		}
	}
}

/*This function displays information to the user.
  Paramaters:
  Return:
  */
void Controller::information()
{
	sf::Text text;
	sf::Font font;
	font.loadFromFile("LCALLIG.TTF");
	text.setFont(font);
	text.setString("Please enter width and height in the console!");
	sf::RenderWindow window({ 810,40 }, "Information");
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))//so only when user actively closes the window and sees the text he can continue.
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				window.close();
		}
		window.clear();
		window.draw(text);
		window.display();
	}
}


Controller::~Controller()
{
}