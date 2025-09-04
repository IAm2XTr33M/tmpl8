#include "precomp.h"
#include "GameObject.h"
#include "iostream"
#include "level.h"

void GameObject::Update()
{
}

void GameObject::Render()
{
	if (sprite != nullptr) {
		//Change pos based on offset camera
		sprite->Draw(surfaceL, position.x - level->cam1offset, position.y);
		sprite->Draw(surfaceR, position.x - level->cam2offset, position.y);
	}
}
