#include "game.h"

Game::Game() {
	texture.loadFromFile("data/tiles.jpg");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	inputGrid(sgrid);
	inputGrid(grid);
	ramdomBom(grid);
	ramdomNum(grid);
}

void Game::inputGrid(int (*tmp)[COL]) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			tmp[i][j] = 10;
		}
	}
}

void Game::ramdomBom(int (*grid)[COL]) {
	srand(time(NULL));
	int count = 0, x, y;
	while (count < BOM) {
		x = rand() % ROW;
		y = rand() % COL;
		if (grid[x][y] != 9) {
			grid[x][y] = 9;
			++count;
		}
		else continue;
	}
}

void Game::ramdomNum(int (*grid)[COL]) {
	int count_bom, x, y;
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (grid[i][j] != 9) {
				count_bom = 0;
				for (int k = 0; k < 9; k++) {
					x = i + a[k];
					y = j + b[k];
					if (x >= 0 && y >= 0 && x < ROW && y < COL && grid[x][y] == 9) ++count_bom;
				}
				grid[i][j] = count_bom;
			}
		}
	}
}

void Game::DFS(int (*sgrid)[COL], int (*grid)[COL], int row, int col) {
	int x, y;
	for (int i = 0; i < 9; ++i) {
		x = row + a[i];
		y = col + b[i];
		if (x >= 0 && y >= 0 && x < ROW && y < COL && sgrid[x][y] == 10) {
			sgrid[x][y] = grid[x][y];
			if (sgrid[x][y] == 0) DFS(sgrid, grid, x, y);
		}
	}
}

void Game::draw(RenderWindow &window) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			sprite.setTextureRect(IntRect(sgrid[i][j] * WID, 0, WID, WID));
			sprite.setPosition(i * WID, j * WID);
			window.draw(sprite);
		}
	}
}

bool Game::update(Vector2i pos, Event &event, RenderWindow &window) {
	int x = pos.x / WID;
	int y = pos.y / WID;
	if (event.mouseButton.button == Mouse::Left) {
		if (grid[x][y] == 0) DFS(sgrid, grid, x, y);
		if (grid[x][y] > 0 && grid[x][y] < 10 && sgrid[x][y] == 10) sgrid[x][y] = grid[x][y];
		if (grid[x][y] == 9) {
			for (int i = 0; i < ROW; ++i) {
				for (int j = 0; j < COL; ++j) {
					sgrid[i][j] = grid[i][j];
				}
			}
			draw(window);
			window.display();
			return false;
		}
	}
	if (event.mouseButton.button == Mouse::Right) {
		if (sgrid[x][y] == 10) sgrid[x][y] = 11; else
		if (sgrid[x][y] == 11) sgrid[x][y] = 10;
	}
	return true;
}

void Game::playagain() {
	inputGrid(sgrid);
	inputGrid(grid);
	ramdomBom(grid);
	ramdomNum(grid);
}