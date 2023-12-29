#include "headergame.h"

int main(int argc, char const *argv[])
{
    int menu_option;
    int exit_game = 0;
    char caracter_aspect = 'o';

    while (!exit_game)
    {
        menu_option = ft_init_game();
        if (menu_option == 0)
        {
            printf("Starting the game");
        }
        else if (menu_option == 1)
        {
       
        }
        else{
            exit_game = 1;
        }
    }    
    return (0);
}
