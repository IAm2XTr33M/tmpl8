#pragma once
#include "GameObject.h"
#include "windows.h"

class Player : public GameObject
{
public:
    Player() = default;
    Player(Vector2f pos){
        position = pos;
    }
    ~Player();

    void Init() override;
    void Update() override;

    float speed = 100.f;

private:
    
};


