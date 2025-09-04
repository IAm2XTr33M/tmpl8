#pragma once
#include "GameObject.h"
#include "windows.h"

class Player : public GameObject
{
public:
    Player() = default;
    Player(Vector2f pos, int _player){
        player = _player;
        position = pos;
    }
    ~Player();

    void Init() override;
    void Update() override;

    int player = 0;
    float speed = 100.f;

private:
    
};


