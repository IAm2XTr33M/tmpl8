#pragma once
class Vector2
{
public:
	Vector2(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int x,y;

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};

class Vector2f
{
public:
	Vector2f(float _x, float _y) {
		x = _x;
		y = _y;
	}
	float x,y;

	Vector2f operator+(const Vector2f& other) const {
		return Vector2f(x + other.x, y + other.y);
	}

	Vector2f operator*(const float& other) const {
		return Vector2f(x * other, y * other);
	}


	Vector2f& operator+=(const Vector2f& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};
