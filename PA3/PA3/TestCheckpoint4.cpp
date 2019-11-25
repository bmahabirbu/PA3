#include "GameCommand.h"

int main(void)
{
	srand(time(NULL));
	Model model;
	

	
	while (true)
	{
		char command;
		cout << "enter command" << endl;
		cin >> command;
		switch (command)
		{
			case 'm':
			{
				int ID, x, y;
				cin >> ID >> x >> y;
				DoMoveCommand(model, ID, Point2D(x, y));
			}
			break;

			case 'g':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoMoveToGymCommand(model, ID1, ID2);
			}
			break;

			case 'c':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoMoveToCenterCommand(model, ID1, ID2);
			}
			break;

			case 's':
			{
				int ID;
				cin >> ID;
				DoStopCommand(model, ID);
			}
			break;

			case 'r':
			{
				int ID1, stamina_amount;
				cin >> ID1 >> stamina_amount;
				DoRecoverInCenterCommand(model, ID1, stamina_amount);
			}
			break;

			case 't':
			{
				int ID1, unit_amount;
				cin >> ID1 >> unit_amount;
				DoTrainInGymCommand(model, ID1, unit_amount);
			}
			break;

			case 'v':
			{
				model.Update();
			}
			break;

			case 'x':
			{

			}
			break;

			case 'q':
			{
				exit(0);
			}
			break;

			default:
			{
				cout << "Something went wrong" << endl;
			}
		}

	}
	

}
