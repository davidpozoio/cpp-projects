#include <ncurses.h>
#include <chrono>
#include <thread>

void delay(std::chrono::milliseconds milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void printY()
{
    int i = 0;

    while (true)
    {
        if (i == 3)
        {
            break;
        }
        mvprintw(2, 1, "y");
        refresh();
        delay((std::chrono::milliseconds)500);
        mvprintw(2, 1, "0");
        refresh();
        delay((std::chrono::milliseconds)500);
        i++;
    }
}

int main()
{
    int i = 0;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    cbreak();
    timeout(0);

    std::thread yPrint(printY);

    while (true)
    {
        if (i == 3)
        {
            break;
        }
        mvprintw(1, 1, "x");
        refresh();
        delay((std::chrono::milliseconds)1000);
        mvprintw(1, 1, "h");
        refresh();
        delay((std::chrono::milliseconds)1000);
        i++;
    }

    refresh();
    yPrint.join();
    delay((std::chrono::milliseconds)1000);
    endwin();
}