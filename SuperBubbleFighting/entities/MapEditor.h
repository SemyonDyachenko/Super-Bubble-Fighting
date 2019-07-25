#ifndef TILEMAP_H
#define TILEMAP_H



#include "Tile.h"
#include "Player.h"

class MapEditor
{
private:
	void clear();

	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2f maxSizeWorldGrid;
	sf::Vector2f maxSizeF;
	sf::RenderWindow * window;
	unsigned layers;
	std::vector < std::vector < std::vector < Tile*> > > map;

	sf::RectangleShape TileSet;
	sf::RectangleShape collisionBox;

	sf::Texture textureSheet;
	std::string textureFile;

	sf::Vector2i pixelPos;
	sf::Vector2f pos;

	void initTextures();
	void initTileSet();
public:
	MapEditor(sf::RenderWindow * window,std::string textureFile);
	virtual ~MapEditor();

	void addTile(const unsigned  x, const unsigned y, const unsigned z, sf::IntRect& textureRect,const bool collision,const short type);
	void removeTile(const unsigned  x, const unsigned y, const unsigned z);
	
	sf::Texture &getTextureSheet();

	void saveToFile(const std::string filename);
	void loadFromFile(const std::string filename);


	void checkCollision(Player*player);

	void update(float time);
	void render(sf::RenderWindow& window);

	
};



#endif // ! TILEMAP_H