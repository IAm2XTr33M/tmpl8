#include "precomp.h"
#include "Level.h"

Level::Level(int capacity)
{
	maxObjects = capacity;
	gameObjects = new GameObject * [capacity];
}

Level::~Level()
{
	for (int i = 0; i < count; i++) {
		delete gameObjects[i];
	}
	delete[] gameObjects;
}

void Level::AddGameObject(GameObject* obj)
{
	if (count < maxObjects) {
		gameObjects[count++] = obj;
	}
}

void Level::Init(Surface* surfaceL, Surface* surfaceR)
{
	for (int i = 0; i < count; i++) {
		gameObjects[i]->surfaceL = surfaceL;
		gameObjects[i]->surfaceR = surfaceR;
		gameObjects[i]->level = this;
		gameObjects[i]->Init();
	}
}

void Level::Update(float _deltatime)
{
	for (int i = 0; i < count; i++) {
		gameObjects[i]->deltatime = _deltatime;
		gameObjects[i]->Update();
	}
}

void Level::Render()
{
	for (int i = 0; i < count; i++) {
		gameObjects[i]->Render();
	}
}