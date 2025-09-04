// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include "string"

Level level(420);


Sprite background = Sprite(new Surface("bomber assets/background.png"), 1);

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

Sprite leftScreen = Sprite(new Surface(SCRWIDTH / 2, SCRHEIGHT), 1);
Sprite rightScreen = Sprite(new Surface(SCRWIDTH / 2, SCRHEIGHT), 1);
Surface* leftSurface;
Surface* rightSurface;


void Game::Init()
{

	leftScreen.Draw(screen, 0, 0);

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

	level.AddGameObject(new Player({ tilesize, tilesize + offset }, 1));
	level.AddGameObject(new Player({ tilesize * 20, tilesize + offset }, 2));

	leftSurface = leftScreen.GetSurface();
	rightSurface = rightScreen.GetSurface();

	level.Init(leftSurface, rightSurface);
}

void Game::Tick(float deltatime)
{
	level.Update(deltatime / 1000);

	screen->Clear(0x000000);
	leftSurface->Clear(0x000000);
	rightSurface->Clear(0x000000);

	background.Draw(leftSurface, 0 - level.cam1offset, 0);
	background.Draw(rightSurface, 0 - level.cam2offset, 0);

	level.Render();

	leftScreen.Draw(screen, 0, 0);
	rightScreen.Draw(screen, SCRWIDTH / 2, 0);
}