/***********************************************************************
 *
 *
 * Name        : Tic-tac-toe Projekt
 * Outhor      : Caner Yildiz
 * Date        : 22.01.2021
 * Description : Tic-tac-toe game in C
 *
 *
 * *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Tictactoe.h"
#include <Funktions.c>

char plc[11] = {'o','1','2','3','4','5','6','7','8','9'};
char player_1[16];
char player_2[16];
char game_sign1;
char game_sign2;

// Main Task (30 points)
int main(){
	int game_mode, choice, checkwin_check;
	FILE *filep_1;
	do{
		do{
		printf("Choose Mode:\n1) Human vs Human\n2) Human vs PC\n3) PC vs PC\n9) Exit\n");
		scanf("%d",&game_mode);
			if(game_mode != 1 && game_mode != 2 && game_mode != 3 && game_mode != 9){
				printf("You choused false mode\n Please try again!\n");
			}
		} while(game_mode != 1 && game_mode != 2 && game_mode != 3 && game_mode != 9);
		if(game_mode == 9){
			printf("Program is closed...");
			return 0;
		}
			printf("your choice:\n%d\n",game_mode);
		if(game_mode == 1){
			printf("Enter name of Player 1:");
			scanf("\n%s",player_1);
			printf("Enter name of Player 2:");
			scanf("\n%s",player_2);
			printf("Choose game sign %s:\nX or O\n",player_1);
			scanf("\n%c",&game_sign1);
			printf("your choice:%c \n",game_sign1);

			if(((game_sign1 != 'x') && (game_sign1 != 'X')) && ((game_sign1 != 'o') && (game_sign1 != 'O'))){
				printf("Please try again! Possible options O or X !\n");
				scanf("\n%c",&game_sign1);
				printf("your choice:%c \n",game_sign1);
			}
			if((game_sign1 == 'x') || (game_sign1 == 'X')){
				game_sign2 = 'O';
				printf("Player %s has \"O\"\n",player_2);
			}
			else{
				game_sign2 = 'X';
				printf("Player %s has \"X\"\n",player_2);
			}
			printf("Game starts!\n");
			// The player who starts is randomly selected.
			int player = random_player();
			switch(player){
				case 0: printf("Player %s start\n",player_1);
					break;
				case 1:	printf("Player %s start\n",player_2);
					break;
				default: printf("ERROR in Player starts!\n");
					break;
			}
			printf("enter the place you want to place your sign (1 - 9) or (1,1 - 3,3):\n");
			place();
			do{
				if(player == 0){
					scanf("%d",&choice);

					// The program ensures that only free places are accepted for a sign.

					if(choice == 1 && plc[1] == '1')
						plc[1] = game_sign1;
					else if(choice == 2 && plc[2] == '2')
						plc[2] = game_sign1;
					else if(choice == 3 && plc[3] == '3')
						plc[3] = game_sign1;
					else if(choice == 4 && plc[4] == '4')
						plc[4] = game_sign1;
					else if(choice == 5 && plc[5] == '5')
						plc[5] = game_sign1;
					else if(choice == 6 && plc[6] == '6')
						plc[6] = game_sign1;
					else if(choice == 7 && plc[7] == '7')
						plc[7] = game_sign1;
					else if(choice == 8 && plc[8] == '8')
						plc[8] = game_sign1;
					else if(choice == 9 && plc[9] == '9')
						plc[9] = game_sign1;
					else{
						printf("Invalid move ");
						getchar();
					}
					printf("Player 1 \"%s\" place %c on %d \n", player_1,game_sign1,choice);
					place();
					player ++;

					checkwin_check = checkwin();
				}

				else if(player == 1){
					scanf("%d",&choice);

					if(choice == 1 && plc[1] == '1')
						plc[1] = game_sign2;
					else if(choice == 2 && plc[2] == '2')
						plc[2] = game_sign2;
					else if(choice == 3 && plc[3] == '3')
						plc[3] = game_sign2;
					else if(choice == 4 && plc[4] == '4')
						plc[4] = game_sign2;
					else if(choice == 5 && plc[5] == '5')
						plc[5] = game_sign2;
					else if(choice == 6 && plc[6] == '6')
						plc[6] = game_sign2;
					else if(choice == 7 && plc[7] == '7')
						plc[7] = game_sign2;
					else if(choice == 8 && plc[8] == '8')
						plc[8] = game_sign2;
					else if(choice == 9 && plc[9] == '9')
						plc[9] = game_sign2;
					else{
        				printf("Invalid move ");
        				getchar();
					}
					printf("Player 2 \"%s\" place %c on %d \n", player_2,game_sign2,choice);
					place();
					player --;

					checkwin_check = checkwin();
				}
				else
				printf("Player ERROR!");
			}while(checkwin_check == -1);
			int game_result_check = game_result();
			switch(game_result_check){
				case 1: if((game_sign1 == 'x') || (game_sign1 == 'X')){
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 2: if((game_sign1 == 'o') || (game_sign1 == 'O')){
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 3: printf("Game Over! \n Result is \" Tie Game! \"\n");
				break;
			}
			filep_1 = fopen("tictactoegames.txt","a+");

			if(filep_1 == NULL){
				fprintf(stderr,"fopen was not successful!\n");
				return EXIT_FAILURE;
			}
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[1], plc[2], plc[3]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[4], plc[5], plc[6]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[7], plc[8], plc[9]);
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"%s\n",player_1);
			fprintf(filep_1,"%s\n",player_2);
			int fclose (FILE *file_1);
			if(fclose(filep_1) != 0){
				fprintf(stderr,"fclose was not successful!\n");
				return EXIT_FAILURE;
			}
		clean_table();
		}
		if(game_mode == 2){
			printf("Enter name of Player 1:");
			scanf("\n%s",player_1);
			char player_2[] = {"PC"};
			printf("Choose game sign %s:\nX or O\n",player_1);
			scanf("\n%c",&game_sign1);
			printf("your choice:%c \n",game_sign1);
			if(((game_sign1 != 'x') && (game_sign1 != 'X')) && ((game_sign1 != 'o') && (game_sign1 != 'O'))){
				printf("Please try again! Possible options O or X !\n");
				scanf("\n%c",&game_sign1);
				printf("your choice:%c \n",game_sign1);
			}
			else if((game_sign1 == 'x') || (game_sign1 == 'X')){
				game_sign2 = 'O';
				printf("Player %s has \"O\"\n",player_2);
			}
			else{
				game_sign2 = 'X';
				printf("Player %s has \"X\"\n",player_2);
			}
			printf("Game starts!\n");
			// The player who starts is randomly selected.
			int player = random_player();
			switch(player){
				case 0: printf("Player %s start\n",player_1);
					break;
				case 1:	printf("Player %s start\n",player_2);
					break;
				default: printf("ERROR in Player starts!\n");
					break;
			}
			if(player == 0){
				printf("enter the place you want to place your sign (1 - 9) or (1,1 - 3,3):\n");
				place();
			}
			do{
				if(player == 0){
				scanf("%d",&choice);

				// The program ensures that only free places are accepted for a sign.

				if(choice == 1 && plc[1] == '1')
				plc[1] = game_sign1;
				else if(choice == 2 && plc[2] == '2')
				plc[2] = game_sign1;
				else if(choice == 3 && plc[3] == '3')
				plc[3] = game_sign1;
				else if(choice == 4 && plc[4] == '4')
				plc[4] = game_sign1;
				else if(choice == 5 && plc[5] == '5')
				plc[5] = game_sign1;
				else if(choice == 6 && plc[6] == '6')
				plc[6] = game_sign1;
				else if(choice == 7 && plc[7] == '7')
				plc[7] = game_sign1;
				else if(choice == 8 && plc[8] == '8')
				plc[8] = game_sign1;
				else if(choice == 9 && plc[9] == '9')
				plc[9] = game_sign1;
				else{
        			printf("Invalid move from Player\n");
        			getchar();
				}
				printf("Player\"%s\" place %c on %d \n", player_1,game_sign1,choice);
				place();
				player ++;

				checkwin_check = checkwin();
				}
				else if(player == 1){
					choice = pc_choice();

					if(choice == 1 && plc[1] == '1')
						plc[1] = game_sign2;
					else if(choice == 2 && plc[2] == '2')
						plc[2] = game_sign2;
					else if(choice == 3 && plc[3] == '3')
						plc[3] = game_sign2;
					else if(choice == 4 && plc[4] == '4')
						plc[4] = game_sign2;
					else if(choice == 5 && plc[5] == '5')
						plc[5] = game_sign2;
					else if(choice == 6 && plc[6] == '6')
						plc[6] = game_sign2;
					else if(choice == 7 && plc[7] == '7')
						plc[7] = game_sign2;
					else if(choice == 8 && plc[8] == '8')
						plc[8] = game_sign2;
					else if(choice == 9 && plc[9] == '9')
						plc[9] = game_sign2;
					else{
        				printf("Invalid move from  PC\n");
        				getchar();
					}
					printf("\"%s\" place %c on %d \n", player_2,game_sign2,choice);
					place();
					player --;

					checkwin_check = checkwin();
				}
				else
				printf("Player ERROR!");
			}while(checkwin_check == -1);
			int game_result_check = game_result();
			switch(game_result_check){
				case 1: if((game_sign1 == 'x') || (game_sign1 == 'X')){
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 2: if((game_sign1 == 'o') || (game_sign1 == 'O'))
						{
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 3: printf("Game Over! \n Result is \" Tie Game! \"\n");
				break;
			}
			filep_1 = fopen("tictactoegames.txt","a+");

			if(filep_1 == NULL){
				fprintf(stderr,"fopen was not successful!\n");
				return EXIT_FAILURE;
			}
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[1], plc[2], plc[3]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[4], plc[5], plc[6]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[7], plc[8], plc[9]);
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"%s\n",player_1);
			fprintf(filep_1,"%s\n",player_2);
			int fclose (FILE *file_1);
			if(fclose(filep_1) != 0){
				fprintf(stderr,"fclose was not successful!\n");
				return EXIT_FAILURE;
			}
		clean_table();
		}
		if(game_mode == 3){
			char player_1[] = {"PC_1"};
			char player_2[] = {"PC_2"};

			int game_sign_number;
			srand(time(NULL));
			game_sign_number = rand() % 2;

			//Select random wich Pc has X and O

			game_sign1 = (game_sign_number == 1) ? 'X' : 'O';
			game_sign2 = (game_sign1 == 'X') ? 'O' : 'X';
			printf("Game starts!\nPC_1 has \"%c\"!\nPC_2 has \"%c\"!\n",game_sign1,game_sign2);

			// The player who starts is randomly selected.
			int player = random_player();
			switch(player){
				case 0: printf("Player %s start\n",player_1);
					break;
				case 1:	printf("Player %s start\n",player_2);
					break;
				default: printf("ERROR in Player starts!\n");
					break;
			}
			place();
			do{
				if(player == 0){
					choice = pc_choice();
					// The program ensures that only free places are accepted for a sign.
					if(choice == 1 && plc[1] == '1')
						plc[1] = game_sign1;
					else if(choice == 2 && plc[2] == '2')
						plc[2] = game_sign1;
					else if(choice == 3 && plc[3] == '3')
						plc[3] = game_sign1;
					else if(choice == 4 && plc[4] == '4')
						plc[4] = game_sign1;
					else if(choice == 5 && plc[5] == '5')
						plc[5] = game_sign1;
					else if(choice == 6 && plc[6] == '6')
						plc[6] = game_sign1;
					else if(choice == 7 && plc[7] == '7')
						plc[7] = game_sign1;
					else if(choice == 8 && plc[8] == '8')
						plc[8] = game_sign1;
					else if(choice == 9 && plc[9] == '9')
						plc[9] = game_sign1;
					else{
						printf("Invalid move from %s\n",player_1);
						getchar();
					}
					printf("Player\"%s\" place %c on %d \n", player_1,game_sign1,choice);
					place();
					player ++;
					checkwin_check = checkwin();
				}
				else if(player == 1){
					choice = pc_choice();

					if(choice == 1 && plc[1] == '1')
						plc[1] = game_sign2;
					else if(choice == 2 && plc[2] == '2')
						plc[2] = game_sign2;
					else if(choice == 3 && plc[3] == '3')
						plc[3] = game_sign2;
					else if(choice == 4 && plc[4] == '4')
						plc[4] = game_sign2;
					else if(choice == 5 && plc[5] == '5')
						plc[5] = game_sign2;
					else if(choice == 6 && plc[6] == '6')
						plc[6] = game_sign2;
					else if(choice == 7 && plc[7] == '7')
						plc[7] = game_sign2;
					else if(choice == 8 && plc[8] == '8')
						plc[8] = game_sign2;
					else if(choice == 9 && plc[9] == '9')
						plc[9] = game_sign2;
					else{
						printf("Invalid move from %s\n",player_2);
        				getchar();
					}
					printf("Player\"%s\" place %c on %d \n", player_2,game_sign2,choice);
					place();
					player --;

					checkwin_check = checkwin();
				}
				else
				printf("Pc Players ERROR!");
			}while(checkwin_check == -1);
			int game_result_check = game_result();
			switch(game_result_check){
				case 1: if((game_sign1 == 'x') || (game_sign1 == 'X')){
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 2: if((game_sign1 == 'o') || (game_sign1 == 'O')){
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_1);
						}else
							printf("Game Over! \n Result is \" %s \" won the Game!\n",player_2);
				break;
				case 3: printf("Game Over! \n Result is \" Tie Game! \"\n");
				break;
				default: printf("Game mode 3 game result ERROR!\n");
				break;
			}
			filep_1 = fopen("tictactoegames.txt","a+");

			if(filep_1 == NULL){
				fprintf(stderr,"fopen was not successful!\n");
				return EXIT_FAILURE;
			}
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[1], plc[2], plc[3]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[4], plc[5], plc[6]);
			fprintf(filep_1,"--------|-------|-------\n");
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"    %c   |   %c   |   %c  \n",plc[7], plc[8], plc[9]);
			fprintf(filep_1,"		|		|	\n");
			fprintf(filep_1,"%s\n",player_1);
			fprintf(filep_1,"%s\n",player_2);
			int fclose (FILE *file_1);
			if(fclose(filep_1) != 0){
				fprintf(stderr,"fclose was not successful!\n");
				return EXIT_FAILURE;
			}
		clean_table();
		}
	}while(game_mode != 9);
return 0;
}
