#include "game.h"

int main() {
	RenderWindow window(VideoMode(640, 640), "MINESWEEPER");
	Event event;
	Game game;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::MouseButtonPressed) {
				game.update(Mouse::getPosition(window), event, window);
			}
		}
		window.clear();
		game.draw(window);
		window.display();
	}
}