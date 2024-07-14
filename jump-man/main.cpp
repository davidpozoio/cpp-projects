#include <ncurses.h>
#include <chrono>
#include "include/player/player.h"
#include "include/utils/utils.h"

int main()
{
    const int EXIT_KEY = 27;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    cbreak();
    timeout(0);
    nodelay(stdscr, true);

    Player player;
    player.print();

    while (true)
    {
        int key = getchar();

        if (key == EXIT_KEY)
        {
            break;
        }

        player.print();

        Utils::delay((std::chrono::milliseconds)100);
        clear();
    }

    Utils::delay((std::chrono::milliseconds)1000);

    endwin();
}