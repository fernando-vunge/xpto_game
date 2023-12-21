#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_init_game(void);
void	
char	getch(void);

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