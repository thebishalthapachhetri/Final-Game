#include "base.h"


base::base(std::string id)
	: Game_Object(id, "Texture.base")
{
	//_x = 400;
	//_y = 200;
	_translation = Vector_2D(-5,400);
	_width = 1800;
	_height = 100;
}
base::~base()
{
}
void base::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}