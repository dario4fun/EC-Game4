#include "Game.h"

/// <summary>
/// Almacenamos la ventana del motor en la clase por si la necesitamos para algo
/// </summary>
/// <param name="window"></param>
void Game::InitGameWindow(sf::RenderWindow* window)
{
	_Window = window;
}

/// <summary>
/// En esta funcion se cargan las variables de inicio del juego
/// </summary>
void Game::InitVariables()
{

	// Cargamos una textura
	_PlayerTexture.loadFromFile("./Resources/file.png");
	_PlataformaTexture.loadFromFile("./Resouces/ptf.png");
	_BackgroundTexture.loadFromFile("./Resources/bg.png");

	_BackgroundSprite.setTexture(_BackgroundTexture);

	// Creamos un player con la animacion de la textura sheet que hemos añadido (columnas y filas)
	_Player = Player(&_PlayerTexture, sf::Vector2u(5, 2), 0.1f, 300.0f, 200.0f);

	// Creamos dos plataformas con collisiones
	platforms.push_back(Platform(&_PlataformaTexture, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(&_PlataformaTexture, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(&_PlataformaTexture, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));

}

// Constructor donde se inizializa el juego
Game::Game()
{
	InitVariables();
}

/// <summary>
/// Funcion que se encarga de la logica del juego
/// </summary>
/// <param name="dt"> delta time </param>
void Game::Update(float dt)
{

	_Player.Update(dt, *_Window);

	sf::Vector2f direction;

	for (Platform& platform : platforms) {
		if (platform.GetCollider().checkCollision(_Player.GetCollider(), direction, 1.0f)) _Player.OnCollision(direction);
	}

}

/// <summary>
/// Funcion que se encarga de dibujar todos los elementos del juego
/// </summary>
/// <param name="renderer"></param>
void Game::Draw(Renderer& renderer)
{

	renderer.Draw(_BackgroundSprite);

	_Player.Draw(*_Window);                        // Dibujamos el player en la ventana

	// Dibujamos las plataformas con collision
	for (Platform& platform : platforms) {
		platform.Draw(*_Window);
	}
}



