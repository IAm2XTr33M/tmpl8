#include "precomp.h"
#include "player.h"
#include "iostream"
#include "level.h"


Player::~Player()
{
}

void Player::Init()
{
	std::cout << "Init Player" << std::endl;
	sprite = new Sprite(new Surface("bomber assets/Player.png"), 1);
}

void Player::Update()
{
	Vector2f movement = { 0,0 };

	//Up
	if (GetAsyncKeyState(87) & 0x8000 && player == 1 ||
		GetAsyncKeyState(73) & 0x8000 && player == 2)
	{ 
		movement.y -= speed;
	}

	//Down
	if (GetAsyncKeyState(83) & 0x8000 && player == 1 ||
		GetAsyncKeyState(75) & 0x8000 && player == 2)
	{ 
		movement.y += speed;
	}

	//Left
	if (GetAsyncKeyState(65) & 0x8000 && player == 1 ||
		GetAsyncKeyState(74) & 0x8000 && player == 2)
	{ 
		movement.x -= speed;
	}

	//Right
	if (GetAsyncKeyState(68) & 0x8000 && player == 1 ||
		GetAsyncKeyState(76) & 0x8000 && player == 2)
	{ 
		movement.x += speed;
	}


	position += movement * deltatime;

	//int tileSize = 48;

	//if (!level->lockCam)
	//{
	//	if (player == 1)
	//	{
	//		if (position.x > SCRWIDTH / 4)
	//			level->cam1offset = position.x - SCRWIDTH / 4;
	//		else
	//			level->cam1offset = 0;
	//	}
	//	else if (player == 2)
	//	{
	//		if (position.x + tileSize < MAPWIDTH - SCRWIDTH / 4)
	//			level->cam2offset = position.x + tileSize - SCRWIDTH / 4;
	//		else
	//			level->cam2offset = MAPWIDTH - SCRWIDTH / 2;
	//	}
	//}


	//std::cout << level->cam2offset - level->cam1offset << std::endl;

}
