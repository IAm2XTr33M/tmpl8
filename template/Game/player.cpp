#include "precomp.h"
#include "player.h"
#include "iostream"


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
	if (GetAsyncKeyState(87) & 0x8000 || 
		GetAsyncKeyState(38) & 0x8000 ) 
	{ 
		movement.y -= speed;
	}

	//Down
	if (GetAsyncKeyState(83) & 0x8000 ||
		GetAsyncKeyState(40) & 0x8000 )
	{ 
		movement.y += speed;
	}

	//Left
	if (GetAsyncKeyState(65) & 0x8000 ||
		GetAsyncKeyState(37) & 0x8000 )
	{ 
		movement.x -= speed;
	}

	//Right
	if (GetAsyncKeyState(68) & 0x8000 || 
		GetAsyncKeyState(39) & 0x8000 )
	{ 
		movement.x += speed;
	}

	position += movement * deltatime;
}
