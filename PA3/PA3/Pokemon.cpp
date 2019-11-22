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
	case STOPPED: cout << "stopped" << endl;
		break;

	case MOVING: cout << "moving at a speed of " << speed << " to destination " << destination
		<< " at each step of " << delta << endl;
		break;

	case EXHAUSTED: cout << "exhausted" << endl;
		break;

	case MOVING_TO_CENTER: cout << "heading to Pokemon Center " << id_num << "at a speed of " << speed <<
		" at each step of" << delta << endl;
		break;

	case MOVING_TO_GYM:  cout << "heading to Pokemon Gym " << id_num << "at a speed of " << speed <<
		" at each step of" << delta << endl;
		break;

	case IN_CENTER: cout << "inside Pokemon Center " << current_center->GetId() << endl;
		break;

	case IN_GYM: cout << "inside Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case TRAINING_IN_GYM: cout << "Training in Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case RECOVERING_STAMINA: cout << "recovering stamina in Pokemon Center " << current_center->GetId() << endl;
		break;
	default:
		cout << "something went wrong with the state" << endl;
	}
}

bool Pokemon::UpdateLocation()
{ 
	if (destination.x > location.x && destination.y > location.y)//error check for walking backwards
	{
		if (destination.x >= location.x + delta.x && destination.y >= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			location = destination;
			cout << "Arrived (update location)" << endl;
			return true;
		}
	}
	if (destination.x < location.x && destination.y < location.y)//walking forwards
	{
		if (destination.x <= location.x + delta.x && destination.y <= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			location = destination;
			cout << "Arrived (update location)" << endl;
			return true;
		}
	}
	if (location.x == destination.x && location.y == destination.y) //checks to see if destination = location
	{
		cout << display_code << id_num << ": I'm there!" << endl;
		return true;
	}
	else //move one step
	{
		location.x = location.x + delta.x; //move pokemon by one delta per step
		location.y = location.y + delta.y;
		cout << display_code << id_num << ": step..." << endl;
		return false;
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	destination = dest;
	delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
}

void Pokemon::StartMoving(Point2D dest)
{
	state = MOVING;
	SetupDestination(dest);
	if (dest.x == location.x && dest.y == location.y)
	{
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}
	else if (state == EXHAUSTED)
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
	state = MOVING_TO_CENTER;
	Point2D pokecenterloc = center->GetLocation();
	SetupDestination(center->GetLocation());
	cout << delta << endl;
	if (location.x == pokecenterloc.x && location.y == pokecenterloc.y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Center!" << endl;
	}
	else if (state == EXHAUSTED)
	{
		cout << display_code << id_num << ": I am exhausted so I cant move to recover stamina..." << endl;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Pokemon Center" << endl;
	}
}

void Pokemon::StartMovingToGym(PokemonGym * gym)
{
	Point2D pokegymloc = gym->GetLocation();
	SetupDestination(gym->GetLocation());
	state = MOVING_TO_GYM;
	if (location.x == pokegymloc.x && location.y == pokegymloc.y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Gym!" << endl;
	}
	else if (state == EXHAUSTED)
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
	Point2D pokegymloc = current_gym->GetLocation();
	state = TRAINING_IN_GYM;
	cout << display_code << " Started Training at Pokemon Gym: " << current_gym->GetId() << " with "
		<< num_training_units << endl;
	if (num_training_units == 0) //print only when training unit is zero
	{
		cout << display_code << id_num << " I am exhausted so no more training for me..." << endl;
	}

	if (location.x != pokegymloc.x && location.y != pokegymloc.y) //print only when location doesnt equal gym location
	{
		cout << display_code << id_num << "I can only train in a Pokemon Gym!" << endl;
	}

	if (current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina) == false) //print only when stamina and or dollars are less than required
	{
		cout << display_code << id_num << "Not enough stamina and/or money for training" << endl;
	}

	if (current_gym->GetState() == BEATEN)
	{
		cout << display_code << id_num << "Cannot train! This Pokemon Gym is already beaten!" << endl;
	}

	training_units_to_buy = num_training_units; 

}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
	state = RECOVERING_STAMINA;
	Point2D pokecenterloc = current_center->GetLocation();
	cout << display_code << id_num << " Started recovering " << stamina << " stamina point(s) at Pokemon Center " <<
		current_center->GetId() << endl;
	if (current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars) == false)
	{
		cout << display_code << id_num << " Not enough money to recover stamina" << endl;
	}

	if (current_center->GetNumStaminaPointsRemaining() <= 0)
	{
		cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
	}

	if (location.x != pokecenterloc.x && location.y != pokecenterloc.y)
	{
		cout << display_code << id_num << "I can only recover stamina in a Pokemon Center!" << endl;
	}

	stamina_points_to_buy = num_stamina_points;
}
 
void Pokemon::Stop()
{
	state = STOPPED;
	destination = location; //stops pokemon since it will already be at destination
}

bool Pokemon::isExhausted()
{
	if (stamina == 0)
	{
		return true;
	}
}

bool Pokemon::ShouldBeVisible()
{
	if (stamina >= 0)
	{
		return true;
	}
}

bool Pokemon::Update()
{
	switch (state)//switch statement to print information about the value of the state
	{
	case STOPPED:
	{
		ShowStatus();
		return false;
	}
		break;

	case MOVING:
	{
		ShowStatus();
		if (UpdateLocation() == true)
		{
			state = STOPPED;
			return true;
		}
	}
		break;

	case IN_GYM:
	{
		ShowStatus();
		return Update();
	}
		break;

	case IN_CENTER: 
	{
		ShowStatus();
		return Update();
	}
		break;

	case MOVING_TO_GYM: 
	{
		ShowStatus();
		if (UpdateLocation() == true)
		{
			state = IN_GYM;
			return true;
		}
	}
		break;

	case MOVING_TO_CENTER: 
	{
		ShowStatus();
		if (UpdateLocation() == true)
		{
			state = IN_CENTER;
			return true;
		}

	}
		break;

	case TRAINING_IN_GYM: 
	{
		ShowStatus();
		stamina = stamina - current_gym->GetStaminaCost(training_units_to_buy); //reduce stamina from stamina used for training units
		pokemon_dollars = pokemon_dollars - current_gym->GetDollarCost(training_units_to_buy); //reduce money from training units gotten
		experience_points = current_gym->TrainPokemon(training_units_to_buy); // gain exp from training units

		cout << "**" << name << "completed " << training_units_to_buy << " training unit(s)!**" << endl;
	}
		break;

	case RECOVERING_STAMINA: 
	{
		ShowStatus();
		stamina = stamina + current_center->DistributeStamina(stamina_points_to_buy);
		pokemon_dollars = pokemon_dollars - current_center->GetDollarCost(stamina_points_to_buy);
		
		cout << "**" << name << "recovered " << stamina << " stamina point(s)!**" << endl;
	}

		break;

	default:
		cout << "something went wrong with the state machine" << endl;
	}
}



