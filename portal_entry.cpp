#pragma once

#include "portal_entry.h"
#include "scene.h"

Portal_Entry::Portal_Entry()
	: Game_Object("Portal.Entry", "Texture.Portal.Entry")
{
	_width = 90;
	_height = 120;
	_translation = Vector_2D(-85, 325);
}

Portal_Entry::~Portal_Entry()
{

}
void Portal_Entry::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Portal_Entry::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{



	Game_Object* obstacle = scene->get_game_object("obstacle");

	Vector_2D portal_center = _translation
									+ Vector_2D((float)_width / 2, (float)_height / 2);
	Vector_2D obstacle_center = obstacle->translation()
									+ Vector_2D((float)obstacle->width() / 2, (float)obstacle->height() / 2);

	float distance_to_obstacle = (portal_center - obstacle_center).magnitude();

	if(distance_to_obstacle < 50.0f)
	{
		Game_Object* portal_exit     = scene->get_game_object("Portal.Exit");
		Vector_2D portal_exit_location = portal_exit->translation()
			+ Vector_2D(100.f, 0.f);

		obstacle->set_translation(portal_exit_location);
	}
}
