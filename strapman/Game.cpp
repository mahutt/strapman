#include "Game.h"

#include <iostream>
#include <fstream>

Game::Game(const std::string& config)
{
	init(config);
}

void Game::init(const std::string& path)
{
	// HERE, READ IN CONFIG FILE
	// USE PREMADE PLAYERCONFIG, ENEMYCONFIG, AND BULLETCONFIG VARIABLES
	std::ifstream fin(path);

	// example for code to be inserted above:
	/*fin >> m_playerConfig.SR >> m_playerConfig.CR;*/

	// Set up default window parameters
	m_window.create(sf::VideoMode(1280, 720), "Assignment 2");
	m_window.setFramerateLimit(60);

	spawnPlayer();
	// also should spawn maps / initial enemys?

}

void Game::run() 
{
	// ADD PAUSE FUNCTIONALITY
	// (SOME SYSTEMS SHOULD FUNCTION WHILE PAUSED, SUCH AS RENDERING)
	// OTHERS LIKE MOVEMENT/INPUT SHOULDN'T FUNCTION
	while (m_running) 
	{
		//m_entities.update(); // updating entity manager

		/*if (!m_paused)
		{

		}*/

		// Calling systems
		sEnemySpawner();
		sMovement();
		sCollision();
		sUserInput();
		sRender();

		// increment the current frame
		// may need ot be moved when pause implemented
		m_currentFrame++;
	}
}

void Game::setPaused(bool paused)
{
	 // double check this:
	m_paused = paused;
}

// (re)spawn the player in the screen's center
void Game::spawnPlayer()
{
	// for positioning at center:
	float mx = m_window.getSize().x / 2.0f;
	float my = m_window.getSize().y / 2.0f;



	// ADD ALL REMAINING PROPERTIES OF THE PLAYER WITH CORERCT CONFIG VALUES

	// Entities created by calling EntityManager.addEntity(tag)
	auto entity = m_entities.addEntity("player");

	// this entity is given a transform such that is spawns at (200,200) with v(1,1) at angle 0
	entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(0.0f, 0.0f), 0.0f);
	entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f); // read in from config, ex: m_playerConfig.SR for radius
	entity->cInput = std::make_shared<CInput>();
	m_player = entity;
}

void Game::spawnEnemy()
{
	// CREATE (SPAWN) ENEMY
	
	//RECORD TIME OF MOST RECENT SPAWN:
	m_lastEnemySpawnTime = m_currentFrame;
}

void Game::sRender() {
	
	m_window.clear();


	// to change: DRAW ALL ENTITIES
	

	// set position pased on transform's pos
	m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

	m_player->cTransform->angle += 1.0f;
	m_player->cShape->circle.setRotation(m_player->cTransform->angle);
	m_window.draw(m_player->cShape->circle);


	m_window.display();
}