//MAVI - Unidad 3 - Ejercicio 6
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Texture texture_red;
Texture texture_yellow;
Texture texture_blue;
Texture texture_grey;
Sprite sprite_red;
Sprite sprite_yellow;
Sprite sprite_blue;
Sprite sprite_grey;

int main() {
	
	sf::RenderWindow App(sf::VideoMode(1024, 768, 32), "Cuadrados");

	texture_red.loadFromFile("Unidad3_Assets/cuad_red.png");
	texture_yellow.loadFromFile("Unidad3_Assets/cuad_yellow.png");
	texture_blue.loadFromFile("Unidad3_Assets/cuad_blue.png");
	texture_grey.loadFromFile("Unidad3_Assets/cuad_grey.png");
	sprite_red.setTexture(texture_red);
	sprite_yellow.setTexture(texture_yellow);
	sprite_blue.setTexture(texture_blue);
	sprite_grey.setTexture(texture_grey);

	float sizeRed_x = (float)texture_red.getSize().x;
	float sizeRed_y = (float)texture_red.getSize().y;
	float sizeYellow_x = (float)texture_yellow.getSize().x;
	float sizeYellow_y = (float)texture_yellow.getSize().y;
	float sizeBlue_x = (float)texture_blue.getSize().x;
	float sizeBlue_y = (float)texture_blue.getSize().y;
	float sizeGrey_x = (float)texture_grey.getSize().x;
	float sizeGrey_y = (float)texture_grey.getSize().y;

	//Obtener escalas x,y en base al sprite cuadrado rojo
	float escalaX_blue = sizeRed_x / sizeBlue_x;
	float escalaY_blue = sizeRed_y / sizeBlue_y;
	float escalaX_yellow = sizeRed_x / sizeYellow_x;
	float escalaY_yellow = sizeRed_y / sizeYellow_y;
	float escalaX_grey = sizeRed_x / sizeGrey_x;
	float escalaY_grey = sizeRed_y / sizeGrey_y;

	//Escalamiento
	sprite_yellow.setScale(escalaX_yellow, escalaY_yellow);
	sprite_blue.setScale(escalaX_blue, escalaY_blue);
	sprite_grey.setScale(escalaX_grey, escalaY_grey);

	//Tamaño de la pantalla
	float winWidth = 1024, winHeight = 768;

	//Posicionamiento
	sprite_red.setPosition((winWidth/2) - sizeRed_x , (winHeight/2) - sizeRed_y);
	sprite_yellow.setPosition(winWidth/2 , (winHeight / 2) - sizeRed_y);
	sprite_blue.setPosition((winWidth / 2) - sizeRed_x , winHeight / 2);
	sprite_grey.setPosition(winWidth / 2 , winHeight / 2);

	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		App.clear();

		App.draw(sprite_red);
		App.draw(sprite_yellow);
		App.draw(sprite_blue);
		App.draw(sprite_grey);

		App.display();
	}

	return 0;
}
