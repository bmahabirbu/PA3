#include "GameCommand.h"

void DoMoveCommand(Model &model, int pokemon_id, Point2D p1)
{
	while (model.GetPokemonPtr(pokemon_id) == 0)
	{
		cout << "Error: please enter a valid command!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin); //error check for right input
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id); //for readability set the pointer to a name
	cout << "Moving " << Poke1->GetName() << " to location " << p1 << endl;
	Poke1->StartMoving(p1);
	
}

void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id)
{
	while (model.GetPokemonPtr(pokemon_id) == 0)//error check
	{
		cout << "Error: please enter a valid command!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin); //error check for right input
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	while (model.GetPokemonCenterPtr(center_id) == 0) //error check
	{
		cout << "Error: please enter a valid Pokemon Center id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonCenterPtr(idin);
	}
	PokemonCenter* PokeC1 = model.GetPokemonCenterPtr(center_id);//for readability set pointer to a name

	cout << " Moving " << Poke1->GetName() << " to center " << PokeC1->GetId() << endl;
	Poke1->StartMovingToCenter(PokeC1); //start moving
	
}

void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id)
{
	while (model.GetPokemonPtr(pokemon_id) == 0) //error check
	{
		cout << "Error: please enter a valid pokemon id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin);
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	while (model.GetPokemonGymPtr(gym_id) == 0)//error check
	{
		cout << "Error: please enter a valid Pokemon Gym id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonGymPtr(idin);
	}

	PokemonGym* PokeG1 = model.GetPokemonGymPtr(gym_id);

	cout << " Moving " << Poke1->GetName() << " to gym " << PokeG1->GetId() << endl;
	Poke1->StartMovingToGym(PokeG1); //start moving to gym
	
}

void DoStopCommand(Model & model, int pokemon_id)
{
	while (model.GetPokemonPtr(pokemon_id) == 0)
	{
		cout << "Error: please enter a valid pokemon id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin);
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Stopping " << Poke1->GetName() << Poke1->GetDisplay_code() << Poke1->GetId();
	Poke1->Stop();

}

void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units)
{
	while (model.GetPokemonPtr(pokemon_id) == 0)
	{
		cout << "Error: please enter a valid pokemon id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin);
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Training " << Poke1->GetName() << endl;
	Poke1->StartTraining(training_units);

}

void DoRecoverInCenterCommand(Model & model, int pokemon_id, unsigned int stamina_points)
{
	while (model.GetPokemonPtr(pokemon_id) == 0)
	{
		cout << "Error: please enter a valid pokemon id!" << endl;
		int idin;
		cin >> idin;
		model.GetPokemonPtr(idin);
	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Recovering " << Poke1->GetName() << "'s stamina" << endl;
	Poke1->StartRecoveringStamina(stamina_points);
	
}

void DoGoCommand(Model & model, View & view)
{

}

void DoRunCommand(Model & model, View & view)
{

}


