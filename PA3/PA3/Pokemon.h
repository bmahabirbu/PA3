#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

enum PokemonStates {
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8
};

class Pokemon : GameObject
{
public: 
	Pokemon();
	Pokemon(char in_code);
private:
	double speed;
	bool is_in_gym;
	bool is_in_center;
	unsigned int stamina;
	unsigned int experience_points;
	double pokemon_dollars;
	unsigned int training_units_to_buy;
	string name;
	PokemonCenter * currrent_center;
	PokemonGym * current_gym;
	Point2D destination;
};