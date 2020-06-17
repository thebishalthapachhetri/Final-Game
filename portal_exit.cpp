#pragma once

#include "portal_exit.h"

Portal_Exit::Portal_Exit()
	: Game_Object("Portal.Exit", "Texture.Portal.Exit")
{
	_width  = 90;
	_height = 90;
	_translation = Vector_2D(700, 300);
}

Portal_Exit::~Portal_Exit()
{

}

void Portal_Exit::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Portal_Exit::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
