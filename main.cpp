#include "blocks.h"
#include <iostream>
#include <ncurses.h>

int main() {
    // FINDME enable double buffering?  
	// ticking..

	// Set up ncurses 	
	WINDOW* win = initscr();				
	cbreak();
	keypad(stdscr, TRUE);	
	noecho();			
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	attron(COLOR_PAIR(2));
	attron(A_BOLD | A_BLINK);
    mvwprintw(win, 0, 0, "Tetris");
	attroff(A_BOLD | A_BLINK);
	for (size_t i=0; i<COLS; ++i) {
		mvwprintw(win, 1, i, "-");		
	}
	attroff(COLOR_PAIR(2));
	refresh();			
	getch();
	endwin();			

	return 0;
}
