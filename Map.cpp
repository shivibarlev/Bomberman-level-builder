#include "Map.h"

/*This function is used to set the location of the instance.
  Paramaters: The new location of the instance.
  Return value: */
void Map::setLocation(sf::Vector2f newLocation)
{
	m_location = newLocation;
	m_object.setPosition(m_location);
}

Map::~Map()
{   
}

/*This function is used to set the character id of the instance.
  Paramaters: The new character id of the instance.
  Return value: */
void Map::setId(char c)
{
	m_id = c;
}

/*This function is used to get the character id of the instance.
  Paramaters:
  Return value: The current character id. */
char Map::getId()
{
	return m_id;
}

/*This function is used to set the object representation of the instance.
  Paramaters: The new object representation of the instance.
  Return value: */
void Map::setObject(const sf::Texture* object)
{
	m_object.setTexture(*object);
}

/*This function is used to get the object representation of the instance.
  Paramaters: 
  Return value: The current object representation of the instance.*/
sf::Sprite* Map::getObject()
{
	return &m_object;
}


