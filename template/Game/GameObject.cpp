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
		float cam1 = level->cam1offset;
		float cam2 = level->cam2offset;

		sprite->Draw(surfaceL, position.x - cam1, position.y);
		sprite->Draw(surfaceR, position.x - cam2, position.y);
	}
}
