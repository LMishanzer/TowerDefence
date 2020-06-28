#include <unistd.h>
#include <ncurses.h>

// winner label
void Winner(){
    move(0, 0);
    printw(" ##                ##  ##   ##        ##  ##        ##  #########   ######  \n");
    refresh();
    usleep(100000);
    printw("  ##       ##      ##  ##   ## ##     ##  ## ##     ##  ##          ##     ##\n");
    refresh();
    usleep(100000);
    printw("   ##              ##  ##   ##  ##    ##  ##  ##    ##  ######      ##     ##\n");
    refresh();
    usleep(100000);
    printw("    ##    ##  ##   ##  ##   ##   ##   ##  ##   ##   ##  ##          ## ##\n");
    refresh();
    usleep(100000);
    printw("     ##  ##    ##  ##  ##   ##    ##  ##  ##    ##  ##   ##         ##   ##\n");
    refresh();
    usleep(100000);
    printw("      ###       ##     ##   ##        ##  ##        ##  #########   ##      ##\n");
    refresh();
    usleep(4000000);
}
