#include "Button.h"


/*This function constructs the object.
  Paramaters:
  Return:
  */
Button::Button()
{
	m_id = ' ';
	m_location = { 0, 0 };
}

/*This function checks if the button was clicked.
  Paramaters: The window we are operating in.
  Return: True if the button was clicked.
  */
bool Button::clicked(sf::Window& window)
{
	if (m_p2Image->getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
		return true;
	return false;
}

/*This function set the new location of the button.
  Paramaters: The new location.
  Return:
  */
void Button::setLocation(sf::Vector2f newLocation)
{
	m_location = newLocation;
	m_p2Image->setPosition(newLocation);
}

/*This function sets the image of the object.
  Paramaters: A pointer to the sprite that holds the image.
  Return:
  */
void Button::setImage(sf::Sprite* s)
{
	this->m_p2Image = s;
	this->m_p2Image->setTextureRect({ 0, 0, 55, 55});
}

/*This function sets the action of the object.
  Paramaters: A pointer to the sprite that holds the action.
  Return:
  */
void Button::setAction(sf::Sprite * s)
{
	this->m_p2Action = s;
	this->m_p2Action->setTextureRect({ 0, 0, 55, 55});
}

/*This function sets the character id of the object.
  Paramaters: The character id.
  Return:
  */
void Button::setId(char c)
{
	this->m_id = c;
}

/*This function returns the image of the object.
  Paramaters:
  Return: A pointer to the image.
  */
sf::Sprite* Button::getImage()
{
	return m_p2Image;
}

/*This function returns the action of the object.
  Paramaters:
  Return: A pointer to the action.
  */
sf::Sprite * Button::getAction()
{
	return m_p2Action;
}

/*This function returns the character id of the object.
  Paramaters:
  Return: The character id.
  */
char Button::getId()
{
	return m_id;
}

Button::~Button()
{
}
