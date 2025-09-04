#pragma once
#include "Game/GameObject.h"

class Player;

class Level
{
public:
	Level(int capacity);
	~Level();

	void AddGameObject(GameObject* obj);
	void AddPlayer(Player* obj, int player);
	void Init(Surface* _screen);
	void Update(float _deltatime);
	void Render();


	float cam1offset = 0;
	float cam2offset = 0;

	bool lockCam = false;
	bool lockCam1Set = false;
	bool lockCam2Set = false;
	float lockedCam1Pos = 0;
	float lockedCam2Pos = 0;
private:
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	GameObject** gameObjects;
	int maxObjects;
	int count;

	Sprite* leftScreen;
	Sprite* rightScreen;

	Surface* leftSurface;
	Surface* rightSurface;

	Surface* screen = nullptr;

	float Lerp(float a, float b, float t) { return a + (b - a) * t; }

	int camSplitFrame = 1;
	float camSplitTimer = 0;

};
