#pragma once

#include "game_object.h"
#include "assets.h"

#include <stack>

class obstacle : public Game_Object
{
public:
	obstacle(std::string id);
	~obstacle();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;

	enum class State
	{
		Idle,
		
	};




	void push_state(State* state, Assets* assets);
	void pop_state(Assets* assets);

private:
		
	
	void handle_enter_state(State state, Assets* assets);
	void handle_exit_state(State state, Assets* assets);

	float _speed;
	std::stack<State> _state;




};