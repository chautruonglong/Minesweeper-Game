#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <time.h>

#define WID 32
#define BOM 100
#define ROW 20
#define COL 20

const int a[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int b[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

using namespace sf;

class Game {
private:
	Texture texture;
	Sprite sprite;
	int grid[ROW][COL];
	int sgrid[ROW][COL];
public:
	Game();
	void draw(RenderWindow& window);
	bool update(Vector2i pos, Event &event, RenderWindow &window);
	void playagain();
private:
	void inputGrid(int (*tmp)[COL]);
	void ramdomBom(int (*grid)[COL]);
	void ramdomNum(int (*grid)[COL]);
	void DFS(int (*sgrid)[COL], int (*grid)[COL], int row, int col);
};

#endif // _GAME_H_