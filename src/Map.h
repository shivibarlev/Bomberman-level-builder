#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	void setLocation(sf::Vector2f newLocation);//sets the locations of the instance.
	~Map();
	void setId(char c); //sets the character id of the instance.
	char getId(); //returns the character id of the instance.
	void setObject(const sf::Texture* object); //sets the object the instance represents.
	sf::Sprite* getObject(); //returns the current object the instance represents.
	
private:
	sf::Sprite m_object;  //Theobject the map intance represents.
	sf::Vector2f m_location; //Location of the map instance.
	char m_id; //The character id of the map instance.
};

