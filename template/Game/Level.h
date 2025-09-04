#pragma once
#include "Game/GameObject.h"

class Level
{
public:
	Level(int capacity);
	~Level();

	void AddGameObject(GameObject* obj);
	void Init(Surface* surfaceL, Surface* surfaceR);
	void Update(float _deltatime);
	void Render();


	float cam1offset = 0;
	float cam2offset = 0;
private:
	GameObject** gameObjects;
	int maxObjects;
	int count;


};
