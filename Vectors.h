#pragma once

class Vector2i
{
public:
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
	Vector3i() : x(0), y(0), lvl(0) {};
	Vector3i(int x, int y, int lvl) : x(x), y(y), lvl(lvl) {};

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

	bool operator <(const Vector3i rhs)
	{
		return (lvl < rhs.lvl) || (lvl == rhs.lvl && x < rhs.x) || (lvl == rhs.lvl && x == rhs.x && y < rhs.y);
	}

	bool operator >(const Vector3i rhs)
	{
		return (lvl > rhs.lvl) || (lvl == rhs.lvl && x > rhs.x) || (lvl == rhs.lvl && x == rhs.x && y > rhs.y);
	}

	Vector3i& operator+=(const Vector3i rhs)
	{
		x += rhs.x;
		y += rhs.y;
		lvl += rhs.lvl;
		return *this;
	}
};
