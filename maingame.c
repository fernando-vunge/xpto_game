#include "headers/headergame.h"

int main(int argc, char const *argv[])
{
	int menu_options;

	menu_options= ft_init_game();
	if (menu_options == 0)
	{
		ft_render_game(6,'_');	
	}
	return (0);
}
