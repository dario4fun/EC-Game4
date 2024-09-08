#pragma once

#ifndef GAME_H
#define GAME_H

#include "Renderer.h"
#include "AudioManager.h"
#include "FontManager.h"
#include "Player.h"
#include "Platform.h"

class Game {

public:

	Game();											// Constructor

	void Update(float dt);							// Controlador del juego

	void Draw(Renderer& renderer);					// Renderizado del juego

	void InitGameWindow(sf::RenderWindow* window);  // Este metodo se llama para traer la ventana del motor a la clase juego

	Player _Player;

private:

	sf::RenderWindow* _Window;			// Variable para almacenar la ventana del motor

	FontManager _FontManager;			// Font manager del motor
	AudioManager _AudioManager;			// AudioManager del motor

	sf::Texture _PlayerTexture;
	sf::Texture _PlataformaTexture;
	sf::Texture _BackgroundTexture;
	sf::Sprite _BackgroundSprite;
	

	std::vector<Platform> platforms;

	void InitVariables();				// Metodo para inicializar variables
};

#endif
