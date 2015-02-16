#include "blocks.h"
#include "manager.h"
#include "scoremaster.h"
#include <iostream>
#include <ncurses.h>

int main() {
	Scoremaster scoremaster;
    // FINDME enable double buffering?  
	// ticking..
	
	// Set up ncurses 	
	WINDOW* win = initscr();				
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

	attron(COLOR_PAIR(2));
	attron(A_BOLD | A_BLINK);
    mvwprintw(win, 0, 0, "***Tetris***");
	attroff(A_BOLD | A_BLINK);
	for (size_t i=0; i<COLS; ++i) {
		mvwprintw(win, 1, i, "-");		
	}
	attroff(COLOR_PAIR(2));

	// Draw main screen	
	for (size_t i=10; i<(COLS-110); ++i) {
		mvwprintw(win, 3, i, "-");
		mvwprintw(win, LINES-3, i, "-");
	}
	for (size_t j=4; j<(LINES-3); ++j) {
		mvwprintw(win, j, 10, "|");
		mvwprintw(win, j, COLS-111, "|");
	}

	// Draw score screen
	for (size_t i=(COLS-80); i<(COLS-50); ++i) {
		mvwprintw(win, 3, i, "-");
		mvwprintw(win, 15, i, "-");
	}
	for (size_t j=4; j<15; ++j) {
		mvwprintw(win, j, COLS-80, "|");
		mvwprintw(win, j, COLS-51, "|");
	}
	mvwprintw(win, 5, COLS-79, "Score:");
	mvwprintw(win, 6, COLS-79, std::to_string(scoremaster.getScore()).c_str());
	

	refresh();			
	getch();
	endwin();			

	return 0;
}
