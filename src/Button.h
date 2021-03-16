#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Button
{
public:
	Button();//constructs the object.
	bool clicked(sf::Window& window);//checks if the button was clicked.
	void setLocation(sf::Vector2f newLocation);//sets new location to button.
	void setImage(sf::Sprite* s);//sets the image shown for the button.
	void setAction(sf::Sprite* s);//sets the action the button does.
	void setId(char c);//sets the button character id.
	sf::Sprite* getImage();//returns the image shown for the button.
	sf::Sprite* getAction();//retrns the action the button does.
	char getId();//returns the buttons character id.
	~Button();
private:
	char m_id;//holds the buttons character id.
	sf::Vector2f m_location;//holds the buttons location.
	sf::Sprite* m_p2Image;//holds the butons image.
	sf::Sprite* m_p2Action;//holds the buttons action.
	//bool m_exists = false;//checks if button exists or not.
};

