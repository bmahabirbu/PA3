#include "View.h"

View::View()
{
	size = 11;
	scale = 2;
	origin = Point2D(0, 0);
}

void View::Clear()
{
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::Plot(GameObject* ptr)
{
	int out_x, out_y;
	GetSubscripts(out_x, out_y, ptr->GetLocation());
	ptr->DrawSelf(**grid);
	grid[out_x][out_y][0] = ***grid;
	grid[out_x][out_y][1] = ***(grid+1);

}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	 out_x = (location.x - origin.x) / scale;
	 out_y = (location.y - origin.y) / scale;
	 if (out_x > 20 || out_y > 20)
	 {
		 cout << "Object outside bounds" << endl;
		 return false;
	 }
	 else return true;
		
}

void View::Draw()
{	
	for (int column = 0; column < size; column++) 
	{
		if (column % 2 == 0) //prints y axis
		{
			if (20 - 2 * column <= 10)
			{
				cout << 20 - 2 * column << " ";
			}
			else
				cout << 20-2*column;
		}
		else
			cout << "  "; //end of y axis

		for (int row = 0; row < size; row++) 
		{
			for (int char_num = 0; char_num < scale; char_num++)
			{
				cout << grid[row][column][char_num];

			}
		} 
		cout << endl;
	} 
	cout << "  0   4   8   12  16  20" << endl; //prints x axis
	
}

