#pragma once
#include "vector2.h"
#include "sprite.h"
#include "iostream"

class Level;

class GameObject {
public:
	GameObject() = default;
	GameObject(Vector2f _pos) {
		position = _pos;
	}
	GameObject(const char* _path, Vector2f _pos) {
		sprite = new Sprite(new Surface(_path), 1);
		position = _pos;
	}
	virtual ~GameObject() {
		delete sprite;
	};

	virtual void Init() {
		std::cout << "Init GameObject" << std::endl;
	};
	virtual void Update();
	void Render();

	Vector2 tilePosition = Vector2(0, 0);
	Vector2f position = Vector2f(0, 0);
	
	Surface* surfaceL = nullptr;
	Surface* surfaceR = nullptr;
	Sprite* sprite = nullptr;

	Level* level;
	
	float deltatime;
}; 