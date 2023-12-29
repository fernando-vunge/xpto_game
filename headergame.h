#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <stdlib.h>

int	show_info = 1;
int	ft_game(int *p_grid_size, char *p_caracter);
int	ft_init_game(void);	
char	getch(void);
void	init_char_grid(char *(p_grid)[], int size, char fill);

char getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

void	init_char_grid(char *(p_grid)[], int size, char fill){
	int row = 0;
	int columm = 0;

	while (row < size)
	{
		while (columm < size)
		{
			p_grid[row][columm++] = fill;
		}
		row++;
	}
}

int	ft_init_game(void){	
	const char *menu_options[3] = {"Start Game", "Settings", "Exit Game"};
	int selected_conditions[3] = {0, 1, 0};
	int selected_index = 1;
	int indexer;
	char button_clicked;

	
	while ((int)button_clicked != 32)
	{
		system("clear");
		printf("< ------- Wellcome to XPTO Game ------- >\n\n");
		indexer = 0;
		while (indexer < 3)
		{
			printf("\t%s%s%s\n", (selected_conditions[indexer] ? "<- ":"   "), menu_options[indexer], (selected_conditions[indexer] ? " ->":"   "));
			indexer++;
		}
		printf("< ------------------------------------- >\n");
		if (show_info)
		{
			printf("\n< ------------------------------------- >\n");
			printf("|\t w -> cima     (up)    \t\t|\n|\t s -> baixo    (down)  \t\t|\n|\t a -> esquerda (left)  \t\t|\n|\t d -> direita  (rigth) \t\t|\n|\t space -> selecionar  (select)  |\n");
			printf("< ------------------------------------- >\n");
			show_info = 0;
		}
		button_clicked = getch();
		selected_conditions[selected_index] = 0;
		{
			if (button_clicked == 'w' || button_clicked == 'W') selected_index = selected_index - 1;
			else if (button_clicked == 's' || button_clicked == 'S') selected_index = selected_index + 1;
		}
		{
			if (selected_index < 0) selected_index = 2;
			else if(selected_index > 2) selected_index = 0;
		}
		selected_conditions[selected_index] = 1;
	}
	return (selected_index);
}

int	ft_game(int *p_grid_size, char *p_caracter){
	char grid[*p_grid_size][*p_grid_size];
	char caracter = *p_caracter;
	int perdeu = 0;
	int venceu = 0;
	int columm_num = 0;
	int row_num = 0;

	init_char_grid(grid,*p_grid_size,'_');
	while (!perdeu && !venceu)
	{
		while (row_num < *p_grid_size)
		{
			while (columm_num < *p_grid_size)
			{
				printf("\t%c",grid[row_num][columm_num++]);
			}
			printf("\n");
			row_num++;
		}
		
	}
	
	return (0);
}