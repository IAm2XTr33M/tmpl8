#include "precomp.h"
#include "Level.h"
#include "Player.h"
#include "Sprite.h"

Sprite camSplit = Sprite(new Surface("bomber assets/split.png"), 12);

Level::Level(int capacity)
{
	maxObjects = capacity;
	gameObjects = new GameObject * [capacity];

	leftScreen = new Sprite(new Surface(SCRWIDTH / 2, SCRHEIGHT), 1);
	rightScreen = new Sprite(new Surface(SCRWIDTH / 2, SCRHEIGHT), 1);

	leftSurface = leftScreen->GetSurface();
	rightSurface = rightScreen->GetSurface();
}

Level::~Level()
{
	for (int i = 0; i < count; i++) {
		delete gameObjects[i];
	}
	delete[] gameObjects;

	delete leftScreen;
	delete rightScreen;
}

void Level::AddGameObject(GameObject* obj)
{
	if (count < maxObjects) {
		gameObjects[count++] = obj;
	}
}
void Level::AddPlayer(Player* obj, int _player)
{
	obj->player = _player;
	if (_player == 1) {
		player1 = obj;
	}
	else {
		player2 = obj;
	}
	if (count < maxObjects) {
		gameObjects[count++] = obj;
	}
}

void Level::Init(Surface* _screen)
{
	screen = _screen;

	for (int i = 0; i < count; i++) {
		gameObjects[i]->surfaceL = leftSurface;
		gameObjects[i]->surfaceR = rightSurface;
		gameObjects[i]->level = this;
		gameObjects[i]->Init();
	}
}

void Level::Update(float _deltatime)
{
	int tileSize = 48;

	for (int i = 0; i < count; i++) {
		gameObjects[i]->deltatime = _deltatime;
		gameObjects[i]->Update();
	}

	float p1Left = player1->position.x;
	float p1Right = player1->position.x + tileSize;
	float p2Left = player2->position.x;
	float p2Right = player2->position.x + tileSize;

	float distance = fabs((p1Left + p1Right) / 2.0f - (p2Left + p2Right) / 2.0f);
	float lockThreshold = (SCRWIDTH / 2) - tileSize;
	float unlockThreshold = (SCRWIDTH / 2);

	if (!lockCam && distance <= lockThreshold) lockCam = true;
	else if (lockCam && distance > unlockThreshold) {
		lockCam = false;
	}

	float targetCam1 = cam1offset;
	float targetCam2 = cam2offset;

	if (lockCam) {
		float minX = std::min(p1Left, p2Left);
		float maxX = std::max(p1Right, p2Right);

		float t1 = minX - (SCRWIDTH / 4 - tileSize / 2);
		float t2 = maxX - (SCRWIDTH / 4 + tileSize / 2);

		float mid = (t1 + t2) * 0.5f;
		targetCam1 = mid - SCRWIDTH / 4;
		targetCam2 = mid + SCRWIDTH / 4;

		if (targetCam1 < 0) {
			targetCam1 = 0;
			targetCam2 = SCRWIDTH / 2;
		}
		if (targetCam2 > MAPWIDTH - SCRWIDTH / 2) {
			targetCam2 = MAPWIDTH - SCRWIDTH / 2;
			targetCam1 = targetCam2 - SCRWIDTH / 2;
		}

		if (camSplitFrame < 12) {
			camSplitTimer += _deltatime * 48;
			if (camSplitTimer >= 1) {
				camSplitFrame++;
				camSplitTimer = 0;
			}
		}
	}
	else {

		float desiredCam1 = p1Left - SCRWIDTH / 4;
		float desiredCam2 = p2Left - SCRWIDTH / 4;

		desiredCam1 = std::clamp(desiredCam1, 0.0f, MAPWIDTH - SCRWIDTH / 2.0f);
		desiredCam2 = std::clamp(desiredCam2, 0.0f, MAPWIDTH - SCRWIDTH / 2.0f);

		targetCam1 = Lerp(cam1offset, desiredCam1, 0.2f);
		targetCam2 = Lerp(cam2offset, desiredCam2, 0.2f);
		if (camSplitFrame > 1) {
			camSplitTimer += _deltatime * 24;
			if (camSplitTimer >= 1) {
				camSplitFrame--;
				camSplitTimer = 0;
			}
		}
	}

	cam1offset = Lerp(cam1offset, targetCam1, 0.2f);
	cam2offset = Lerp(cam2offset, targetCam2, 0.2f);

}

void Level::Render()
{
	leftSurface->Clear(0x000000);
	rightSurface->Clear(0x000000);

	for (int i = 0; i < count; i++) {
		gameObjects[i]->Render();
	}

	leftScreen->Draw(screen, 0, 0);
	rightScreen->Draw(screen, SCRWIDTH / 2, 0);

	if(camSplitFrame < 12){
		camSplit.SetFrame(camSplitFrame);
		camSplit.Draw(screen, SCRWIDTH / 2 - 48 / 2, 0);
	}
}