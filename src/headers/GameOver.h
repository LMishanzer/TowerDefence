#include <iostream>
#include <unistd.h>
#include <ncurses.h>

using namespace std;

void GameOver(){
    move(0, 0);
    printw("        ###          ##       ##        ##  #########   \n");
    refresh();
    usleep(100000);
    printw("      ##   ##       ####      ####    ####  ##          \n");
    refresh();
    usleep(100000);
    printw("     ##            ##  ##     ## ##  ## ##  #####       \n");
    refresh();
    usleep(100000);
    printw("     ##   ####    ##    ##    ##  ####  ##  ##          \n");
    refresh();
    usleep(100000);
    printw("      ##   ##    ## #### ##   ##   ##   ##  ##          \n");
    refresh();
    usleep(100000);
    printw("        ###     ##        ##  ##        ##  #########   \n");
    printw("                                                        \n");
    refresh();
    usleep(500000);
    printw("        ###     ##        ##  #########   #####         \n");
    refresh();
    usleep(100000);
    printw("      ##   ##    ##      ##   ##          ##   ##       \n");
    refresh();
    usleep(100000);
    printw("     ##     ##    ##    ##    #####       ##   ##       \n");
    refresh();
    usleep(100000);
    printw("     ##     ##     ##  ##     ##          #####         \n");
    refresh();
    usleep(100000);
    printw("      ##   ##       ####      ##          ##  ##        \n");
    refresh();
    usleep(100000);
    printw("        ###          ##       #########   ##   ##       \n");
    refresh();
    usleep(4000000);
}
