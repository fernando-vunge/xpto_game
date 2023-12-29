#include "headergame.h"

int main(int argc, char const *argv[])
{
    int menu_option;
    int exit_game = 0;
    char caracter_aspect = 'o';
    int grid_size = 16;
    char *p_caracter_aspect;
    int *p_grid_size;    

    p_caracter_aspect = &caracter_aspect;
    p_grid_size = &grid_size;
    
    while (!exit_game)
    {
        menu_option = ft_init_game();
        if (menu_option == 0)
        {
            ft_render_game(p_grid_size,p_caracter_aspect);    
        }
        else if (menu_option == 1)
        {
        
        }
        else
            exit_game = 1;
    }
    
    return (0);
}
