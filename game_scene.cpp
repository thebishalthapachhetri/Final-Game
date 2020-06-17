#include "game_scene.h"

#include "player.h"



#include "obstacle.h"
#include "base.h"

#include "portal_entry.h"
#include "portal_exit.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	


	Game_Object* Player = new player("player");
	_game_objects[Player->id()] = Player;
	
	
	Game_Object* Base = new base("base");
	_game_objects[Base->id()] = Base;




	Game_Object* Obstacle = new obstacle("obstacle");
	_game_objects[Obstacle->id()] = Obstacle;



	Game_Object* portal_entry = new Portal_Entry();
	_game_objects[portal_entry->id()] = portal_entry;

	Game_Object* portal_exit = new Portal_Exit();
	_game_objects[portal_exit->id()] = portal_exit;

}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}