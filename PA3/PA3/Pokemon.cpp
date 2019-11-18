#include "Pokemon.h"

Pokemon::Pokemon()
{
	speed = 5;
	cout << "Pokemon default contructed" << endl;
}

Pokemon::Pokemon(char in_code)
{
	speed = 5;
	state = STOPPED;
	display_code = in_code;
	cout << "Pokemon contructed" << endl;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
{
	speed = in_speed;
	name = in_name;
	id_num = in_id;
	display_code = in_code;
	location = in_loc;
	state = STOPPED;
	cout << "Pokemon contructed" << endl;
}

void Pokemon::ShowStatus()
{
	cout << name << " status: " << endl;
	GameObject::ShowStatus();

	switch (state)//switch statement to print information about the value of the state
	{
	case (char)0: cout << "stopped" << endl;
		break;

	case (char)1: cout << "moving at a speed of " << speed << " to destination " << location
		<< " at each step of" << delta << endl;
		break;

	case (char)2: cout << "exhausted" << endl;
		break;

	case (char)3: cout << "heading to Pokemon Center " << id_num << "at a speed of " << speed <<
		" at each step of" << delta << endl;
		break;

	case (char)4:  cout << "heading to Pokemon Gym " << id_num << "at a speed of " << speed <<
		" at each step of" << delta << endl;
		break;

	case (char)5: cout << "inside Pokemon Center " << currrent_center->GetId() << endl;
		break;

	case (char)6: cout << "inside Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case (char)7: cout << "Training in Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case (char)8: cout << "recovering stamina in Pokemon Center " << currrent_center->GetId() << endl;
		break;
	default:
		cout << "something went wrong with the state" << endl;
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	Vector2D delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
}

void Pokemon::StartMoving(Point2D dest)
{
	state = MOVING;
	SetupDestination(dest);
	if (dest.x == location.x && dest.y == location.y)
	{
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}
	else if (state = 2)
	{
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
	}
	else
	{
		cout << display_code << id_num << " On my way" << endl;
	}
}

void Pokemon::StartMovingToCenter(PokemonCenter * center)
{
	Point2D pokecenterloc = center->GetLocation;
	SetupDestination(center->GetLocation);
	state = MOVING_TO_CENTER;
	if (location.x == pokecenterloc.x && location.y == pokecenterloc.y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Center!" << endl;
	}
	else if (state = 2)
	{
		cout << display_code << id_num << ": I am exhausted so I cant move to recover stamina..." << endl;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Pokemon Center" << endl;
	}
}

void Pokemon::StartMovingCenter(PokemonGym * gym)
{
	Point2D pokegymloc = gym->GetLocation;
	SetupDestination(gym->GetLocation);
	state = MOVING_TO_GYM;
	if (location.x == pokegymloc.x && location.y == pokegymloc.y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Gym!" << endl;
	}
	else if (state = EXHAUSTED)
	{
		cout << display_code << id_num << ": I am exhausted so shouldnt go to the gym" << endl;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Pokemon Gym" << endl;
	}
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
	Point2D pokegymloc = current_gym->GetLocation;
	state = TRAINING_IN_GYM;
	cout << display_code << " Started Training at Pokemon Gym: " << id_num << " with "
		<< num_training_units << endl;
	if (num_training_units == 0) //print only when training unit is zero
	{
		cout << display_code << id_num << " I am exhausted so no more training for me..." << endl;
	}

	if (location.x != pokegymloc.x && location.y != pokegymloc.y) //print only when location doesnt equal gym loc
	{
		cout << display_code << id_num << "I can only train in a Pokemon Gym!" << endl;
	}

	if (stamina <= current_gym->GetStaminaCost(num_training_units)
		|| pokemon_dollars <= current_gym->GetDollarCost(num_training_units)) //print only when stamina and or dollars are less than required
	{
		cout << display_code << id_num << "Not enough stamina and/or money for training" << endl;
	}

	if (current_gym->GetState == BEATEN)
	{
		cout << display_code << id_num << "Cannot train! This Pokemon Gym is already beaten!" << endl;
	}
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
	state = RECOVERING_STAMINA;
	cout << display_code << id_num << "     "
}



