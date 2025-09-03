#pragma once
#include "Game/GameObject.h"

class Level
{
public:
	Level(int capacity);
	~Level();

	void AddGameObject(GameObject* obj);
	void Init(Surface* surface);
	void Update(float _deltatime);
	void Render();

private:
	GameObject** gameObjects;
	int maxObjects;
	int count;
};
