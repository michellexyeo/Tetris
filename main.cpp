#include "blocks.h"
#include "manager.h"
#include "scoremaster.h"
#include <iostream>
#include <ncurses.h>
#include <panel.h>

namespace {
	void draw_borders(WINDOW *screen) {
  		int x, y, i;
  		getmaxyx(screen, y, x);
  		// 4 corners
		wattron(screen, COLOR_PAIR(2));
  		mvwprintw(screen, 0, 0, "+");
  		mvwprintw(screen, y - 1, 0, "+");
  		mvwprintw(screen, 0, x - 1, "+");
		mvwprintw(screen, y - 1, x - 1, "+");
		// sides
		for (i = 1; i < (y - 1); i++) {
			mvwprintw(screen, i, 0, "|");
			mvwprintw(screen, i, x - 1, "|");
		}
		// top and bottom
		for (i = 1; i < (x - 1); i++) {
			mvwprintw(screen, 0, i, "-");
			mvwprintw(screen, y - 1, i, "-");
		}
		wattroff(screen, COLOR_PAIR(2));
	}
} // namespace anon

int main() {
	Scoremaster scoremaster;
	Manager manager;
    // FINDME enable double buffering?  
	// ticking..
	
	// Set up ncurses 	
	//WINDOW* win = initscr();				
	WINDOW* windows[3];  
	PANEL* panels[3];
	initscr();
	cbreak();
	keypad(stdscr, TRUE);	
	noecho();			
	if (!has_colors()) {
		endwin();
		std::cout << "Terminal doesn't support colour." << std::endl;
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	// Create main screen and score screen	
	windows[0] = newwin(LINES-7, COLS-100, 4, 10);
	windows[1] = newwin(12, 30, 4, COLS-50);
	windows[2] = newwin(3, COLS, 0, 0); 
	draw_borders(windows[0]);
	draw_borders(windows[1]);
	wattron(windows[2], A_BOLD | A_BLINK);
	wattron(windows[2], COLOR_PAIR(2));
    mvwprintw(windows[2], 0, 0, "***Tetris***");
	wattroff(windows[2], COLOR_PAIR(2));
	wattroff(windows[2], A_BOLD | A_BLINK);
	panels[0] = new_panel(windows[0]);
	panels[1] = new_panel(windows[1]);
	panels[2] = new_panel(windows[2]);
	wattron(windows[1], COLOR_PAIR(3));
	mvwprintw(windows[1], 1, 1, "Score:");
	mvwprintw(windows[1], 2, 1, std::to_string(scoremaster.getScore()).c_str());
	wattron(windows[1], COLOR_PAIR(3));
	
	update_panels();
	doupdate();
	int ch = getch();
	while (ch != 'q') {
		ch = getch();

	}
	endwin();			
	return 0;
}
