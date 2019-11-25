#include "Point2D.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;



GameObject::GameObject()
{
	display_code = 0;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

GameObject::GameObject(char in_code)
{
	display_code = in_code;
	id_num = 1;
	state = 0;
	cout << "GameObject contructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = 0;
	cout << "GameObject contructed" << endl;
}

Point2D GameObject::GetLocation()
{
	return location;
}

int GameObject::GetId()
{
	return id_num;
}

char GameObject::GetState()
{
	return state;
}

void GameObject::ShowStatus()
{
	cout << display_code << id_num << " at location " << location;
}

void GameObject::DrawSelf(char * ptr)
{
	*ptr = display_code;
	char id_char = (char)id_num;
	*(ptr+1) = id_char;
}
