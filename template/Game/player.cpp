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
		GetAsyncKeyState(38) & 0x8000 && player == 2)
	{ 
		movement.y -= speed;
	}

	//Down
	if (GetAsyncKeyState(83) & 0x8000 && player == 1 ||
		GetAsyncKeyState(40) & 0x8000 && player == 2)
	{ 
		movement.y += speed;
	}

	//Left
	if (GetAsyncKeyState(65) & 0x8000 && player == 1 ||
		GetAsyncKeyState(37) & 0x8000 && player == 2)
	{ 
		movement.x -= speed;
	}

	//Right
	if (GetAsyncKeyState(68) & 0x8000 && player == 1 ||
		GetAsyncKeyState(39) & 0x8000 && player == 2)
	{ 
		movement.x += speed;
	}


	position += movement * deltatime;

	int tileSize = 48;


	if (player == 1) {
		if (position.x > SCRWIDTH / 4) {
			level->cam1offset = position.x - SCRWIDTH / 4;
		}
		else {
			level->cam1offset = 0;
		}
	}
	else {
		if (position.x + tileSize < MAPWIDTH - SCRWIDTH / 4) {

			if (level->cam2offset - level->cam1offset > SCRWIDTH / 2 ||
				level->cam2offset - level->cam1offset < 200) {
				level->cam2offset = position.x + tileSize - SCRWIDTH / 4;
			}
		}
		else {
			level->cam2offset = MAPWIDTH - SCRWIDTH / 2;
		}
	}

	if (level->cam2offset - level->cam1offset <= SCRWIDTH / 2) {
		std::cout << "Merge screen" << std::endl;
	}
	//std::cout << level->cam2offset - level->cam1offset << std::endl;

}
