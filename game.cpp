// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include "string"

Level level(420);



char map[13][32] = {
	{"###############################"},
	{"#SS...........................#"},
	{"#S#.#.#.#.#.#.#.#.#.#.#.#.#.#.#"},
	{"#.............................#"},
	{"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#"},
	{"#.............................#"},
	{"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#"},
	{"#.............................#"},
	{"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#"},
	{"#.............................#"},
	{"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#S#"},
	{"#...........................SS#"},
	{"###############################"},
};




void Game::Init()
{

	level.AddGameObject(new GameObject("bomber assets/background.png",{ 0, 0 }));

	float tilesize = 48.f;
	float offset = tilesize * 2;
	for (int r = 0; r < 13; r++) {
		for (int c = 0; c < 31; c++) {
			char ch = map[r][c];
			Vector2f pos = { c * tilesize , r * tilesize + offset };
			switch (ch) {
				//case '#': level.AddGameObject(new GameObject("bomber assets/Wall.png", pos)); break;
				//case '.': level.AddGameObject(new GameObject("bomber assets/Enemy.png", pos)); break;
				//case 'S': level.AddGameObject(new GameObject("bomber assets/Safe.png",pos)); break;
			}
		}
	}

	level.AddPlayer(new Player({ tilesize, tilesize + offset }), 1);
	level.AddPlayer(new Player({ tilesize * 20, tilesize + offset }), 2);

	level.Init(screen);
}

int frameCount = 0;
float timer = 0;

void Game::Tick(float deltatime)
{
	timer += deltatime / 1000;
	frameCount++;
	if (timer >= 1) {
		std::cout << "FPS: " << frameCount << std::endl;
		timer = 0;
		frameCount = 0;
	}


	level.Update(deltatime / 1000);

	screen->Clear(0x000000);

	level.Render();


}