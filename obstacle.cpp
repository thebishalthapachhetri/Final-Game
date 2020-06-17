#pragma once

#include "obstacle.h"
#include <iostream>

obstacle::obstacle(std::string id)
	: Game_Object(id, "Texture.obstacle")
{
	//_x = 150;
	//_y = 50;
	_translation = Vector_2D(500, 300);
	_velocity = Vector_2D(-0.3f, 0);

	_collider.set_radius(_width / 25.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

}
obstacle::~obstacle()
{
}

void obstacle::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer,Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void obstacle::simulate_AI(Uint32, Assets*,Input*,Scene*)
{
}


void obstacle::handle_enter_state(State state, Assets*)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.obstacle";
		break;
	}
}

void obstacle::handle_exit_state(State state, Assets*)
{
	switch (state)
	{
	case State::Idle:
		break;
	
	}
}