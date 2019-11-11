#pragma once
#ifndef _GameObject_h
#define _GameObject_h
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;

class GameObject
{
protected:
	Point2D location;
	int id_num;
	char display_code;
	char state;
public:
	GameObject();
	GameObject(char in_code);
	GameObject(Point2D in_loc, int in_id, char in_code);
	Point2D GetLocation();
	int GetId();
	char GetState();
	void ShowStatus();
};

#endif