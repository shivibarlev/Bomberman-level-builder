#include "PlaceHolder.h"



PlaceHolder::PlaceHolder()
{
}


PlaceHolder::~PlaceHolder()
{
}

/*This function sets the character id of the object.
  Paramaters: new id.
  Return:
  */
void PlaceHolder::setId(char c)
{
	m_id = c;
}

/*This function returns the character id of the object.
  Paramaters:
  Return: the current id.
  */
char PlaceHolder::getId()
{
	return m_id;
}

/*This function sets the sprite of the object.
  Paramaters: a pointer to the new sprite.
  Return:
  */
void PlaceHolder::setObject(sf::Sprite* object)
{
	m_object = object;
}

/*This function sets the sprite of the object.
  Paramaters:
  Return: a pointer to the objects sprite.
  */
sf::Sprite* PlaceHolder::getObject()
{
	return m_object;
}



