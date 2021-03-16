#include "Graphics.h"


/*This function constructs the object.
  Paramaters:
  Return:
  */
Graphics::Graphics()
{
	m_textures.resize(9);
	m_textures[0] = "images/robot_ex4_55.jpg";
	m_textures[1] = "images/guard_ex4_55.jpg";
	m_textures[2] = "images/box_ex4_55.jpg";
	m_textures[3] = "images/wall_ex4_55.jpg";
	m_textures[4] = "images/door_ex4_55.jpg";
	m_textures[5] = "images/erase_ex4_55.jpg";
	m_textures[6] = "images/clear_ex4_55.jpg";
	m_textures[7] = "images/save_ex4_55.jpg";
	m_textures[8] = "images/floor_ex4_55.jpg";

	setTexture();
}

/*This function sets the textures to the sprites.
  Paramaters:
  Return:
  */
void Graphics::setTexture()
{
	m_buttonsSprite.resize(9);
	m_buttonTexture.resize(9);

	for (size_t i = 0; i < m_buttonTexture.size(); i++)
	{
		m_buttonTexture[i].loadFromFile(m_textures[i]);
		m_buttonsSprite[i].setTexture(m_buttonTexture[i]);
	}
}

/*This function returns the sprite of a specific button.
  Paramaters: The specific index.
  Return: The requested sprite(pointer).
  */
sf::Sprite* Graphics::getSprite(int i)
{
	return &m_buttonsSprite[i];
}


Graphics::~Graphics()
{
}
