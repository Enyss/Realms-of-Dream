#pragma once

class Vector2i
{
public:
	Vector2i(int x, int y) : x(x), y(y) {};

	int x;
	int y;

	bool operator==(const Vector2i rhs)
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const Vector2i rhs)
	{
		return x != rhs.x || y != rhs.y;
	}

	bool operator<(const Vector2i rhs)
	{
		return (x < rhs.x) || (x == rhs.x && y < rhs.y);
	}

	bool operator>(const Vector2i rhs)
	{
		return (x > rhs.x) || (x == rhs.x && y > rhs.y);
	}

	Vector2i& operator+=(const Vector2i rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}



};

class Vector3i
{
public :
	int x;
	int y;
	int lvl;

	bool operator==(const Vector3i rhs)
	{
		return x == rhs.x && y == rhs.y && lvl == rhs.lvl;
	}

	bool operator!=(const Vector3i rhs)
	{
		return x != rhs.x || y != rhs.y || lvl != rhs.lvl;
	}

	friend bool Vector3i::operator<(const Vector3i lhs, const Vector3i rhs)
	{
		return (lhs.lvl < rhs.lvl)
			|| (lhs.lvl == rhs.lvl && lhs.x < rhs.x)
			|| (lhs.lvl == rhs.lvl && lhs.x == rhs.x && lhs.y < rhs.y)
			;
	}

	Vector3i& operator+=(const Vector3i rhs)
	{
		x += rhs.x;
		y += rhs.y;
		lvl += rhs.lvl;
		return *this;
	}
};

