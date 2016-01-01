#pragma once

#include "Component.h"

#include "Vectors.h"




struct Position : Component
{
	Position(int x, int y, int level) { pos.x = x; pos.y = y; pos.lvl = level; };
	Vector3i pos;
};