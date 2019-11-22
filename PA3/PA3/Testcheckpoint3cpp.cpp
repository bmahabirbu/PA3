#include "Pokemon.h"
#include "GameObject.h"


int main(void)
{
	cout << GetDistanceBetween(Point2D(0, 0), Point2D(9, 9)) << endl;
	Vector2D D = Point2D(0, 0) - Point2D(9, 9);
	cout << D << endl;
	Vector2D G = D * (100 / GetDistanceBetween(Point2D(0, 0), Point2D(9, 9)));
	cout << G << endl;

	Pokemon pikachu("pikachu", 32, 'P', 100, Point2D(9, 9));
	cout << (int)pikachu.GetState() << endl;
	PokemonCenter A;
	PokemonCenter* B = &A;
	Point2D loc = B->GetLocation();
	cout << loc.x << " yaayaya " << loc.y << endl;
	cout << B->GetLocation() << endl;
	pikachu.StartMovingToCenter(B);
	cout << B->GetId() << endl;
	pikachu.Update();
	pikachu.Update();
	pikachu.StartRecoveringStamina(5);
}