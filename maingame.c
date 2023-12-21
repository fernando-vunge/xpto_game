#include "headergame.h"

int main(int argc, char const *argv[])
{
    int menu_option;

    menu_option = ft_init_game();
    if (menu_option == 0)
    {
        printf("Starting the game");
    }
    else if (menu_option == 1)
    {
        printf("Showing the settings");
    }
    else{
        printf("logout the game");
        return (0);
    }
    return (0);
}