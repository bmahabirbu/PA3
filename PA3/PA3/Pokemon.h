#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <string>

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

class Pokemon : public GameObject
{
public: 
	Pokemon();
	Pokemon(char in_code); // contructors
	Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed,
		Point2D in_loc);

	void ShowStatus(); //Show status function (most important)

	void SetupDestination(Point2D dest);//important for functions 

	void StartMoving(Point2D dest); //Functions

	void StartMovingToCenter(PokemonCenter* center);

	void StartMovingCenter(PokemonGym* gym);

	void StartTraining(unsigned int num_training_units);

	void StartRecoveringStamina(unsigned int num_stamina_points);


private:
	double speed;
	bool is_in_gym;
	bool is_in_center;
	unsigned int stamina;
	unsigned int experience_points;
	double pokemon_dollars;
	unsigned int training_units_to_buy;
	string name;
	PokemonCenter* currrent_center;
	PokemonGym* current_gym;
	Point2D destination;
	Vector2D delta;
};