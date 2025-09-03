#include "precomp.h"
#include "GameObject.h"
#include "iostream"

void GameObject::Update()
{
}

void GameObject::Render()
{
	if (sprite != nullptr) {
		sprite->Draw(surface, position.x, position.y);
	}
}
