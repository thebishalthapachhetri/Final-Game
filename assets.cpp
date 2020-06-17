#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
	
	// Cache rat Texture.
	{
		Texture* texture = new Texture("Texture.base", "Assets/base.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Cache obstacle Texture.
	{
		const int frame_count = 1;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* texture = new Animated_Texture(
			"Texture.obstacle",
			"Assets/obstacle.png",
			renderer,
			frame_count,
			frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}

	//cache moving player
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* texture = new Animated_Texture("Texture.player", "Assets/movingplayer.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}


	// Create player jump texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* texture = new Animated_Texture("Texture.player.jump", "Assets/jumper.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}

	// cache collider texture
	{
		Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create door entry texture.
	{
		const int frame_count = 1;
		const Uint32 frame_duration_milliseconds = 80;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Entry", "Assets/door.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Create door exit texture.
	{
		const int frame_count = 1;
		const Uint32 frame_duration_milliseconds = 80;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Exit", "Assets/door.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Create music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/music.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}


	
}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}