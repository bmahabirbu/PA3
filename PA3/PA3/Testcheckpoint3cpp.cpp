#include "Pokemon.h"
#include "GameObject.h"


int main(void)
{
	Pokemon pikachu("pikachu", 32, 'P', 100, Point2D(9, 9));
	pikachu.ShowStatus();

}