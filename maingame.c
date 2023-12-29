#include "headergame.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int menu_option;
    int exit_game = 0;
    char caracter_aspect = 'o';
    int grid_size = 16;
  
    while (!exit_game)
    {
        menu_option = ft_init_game();
        printf("%d",menu_option);
        if (menu_option == 0)
        {
            printf("starting the game");
            ft_render_game(grid_size,caracter_aspect);    
        }
        else if (menu_option == 1)
        {
            printf("starting the sentings");
        }
        else
            exit_game = 1;
    }
    return (0);
}
