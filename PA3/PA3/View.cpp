#include "View.h"

View::View()
{
	size = 11;
	scale = 2;
	origin = Point2D(0, 0);
}

void View::Clear()
{
	for (int i = 0; i < 20; i++)
	{
		grid[i][i]['.'];
	}
}

void View::Plot(GameObject* ptr)
{
	int out_x, out_y;
	GetSubscripts(out_x, out_y, ptr->GetLocation());
	//ptr->DrawSelf();

}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	 out_x = (location.x - origin.x) / scale;
	 out_y = (location.y - origin.y) / scale;
	 if (out_x > 20 || out_y > 20)
	 {
		 return false;
	 }
	 else return true;
		
}
