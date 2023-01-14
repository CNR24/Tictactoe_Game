/*
 * Functions.c
 *
 *  Created on: Jan 22, 2021
 *      Author: osboxes
 */



#include "Tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/** \file
 * \brief This file contains all functions used for the game. */


/**
 * \brief This print out the gamefield in a nicely formatted way.
 *
 * \return This return the gamefiled
 */

// Print out the gamefield in a nicely formatted way.

void place(){
	printf("	|	|	\n");
	printf("    %c   |   %c   |   %c  \n",plc[1], plc[2], plc[3]);
	printf("--------|-------|-------\n");
	printf("	|	|	\n");
	printf("    %c   |   %c   |   %c  \n",plc[4], plc[5], plc[6]);
	printf("--------|-------|-------\n");
	printf("	|	|	\n");
	printf("    %c   |   %c   |   %c  \n",plc[7], plc[8], plc[9]);
	printf("	|	|	\n");
}
/**
 *
 *\brief That looks if one of the players has won the game.
 *<br> That makes it with comparing the playing field
 *\return This returns a 1 if there is a winner, otherwise -1
 *
 */
int checkwin(){
    if (plc[1] == plc[2] && plc[2] == plc[3])
        return 1;

    else if (plc[4] == plc[5] && plc[5] == plc[6])
        return 1;

    else if (plc[7] == plc[8] && plc[8] == plc[9])
        return 1;

    else if (plc[1] == plc[4] && plc[4] == plc[7])
        return 1;

    else if (plc[2] == plc[5] && plc[5] == plc[8])
        return 1;

    else if (plc[3] == plc[6] && plc[6] == plc[9])
        return 1;

    else if (plc[1] == plc[5] && plc[5] == plc[9])
        return 1;

    else if (plc[3] == plc[5] && plc[5] == plc[7])
        return 1;

    else if (plc[1] != '1' && plc[2] != '2' && plc[3] != '3' &&
        plc[4] != '4' && plc[5] != '5' && plc[6] != '6' && plc[7]
        != '7' && plc[8] != '8' && plc[9] != '9')
        return 1;
    else
        return  - 1;
}
/**
 *
 *  \brief That checks who won the game with which sign.
 *
 *  That checks at whether the three fields are side by side, one under the other or cross.
 *  If not one of these, the game ends as a "Tiegame"
 *
 * \return 1 "X or x" won the game.
 * <br>  2 "O or o" won the game.
 * <br>  3 "if all fields chanced and no winner" tiegame.
 * <br>  0 for ERROR
 *
 */
int game_result(){
	if((plc[1] == 'X' && plc[2] == 'X' && plc[3] == 'X') || (plc[1] == 'x' && plc[2] == 'x' && plc[3] == 'x')
	|| (plc[4] == 'X' && plc[5] == 'X' && plc[6] == 'X') || (plc[4] == 'x' && plc[5] == 'x' && plc[6] == 'x')
	|| (plc[7] == 'X' && plc[8] == 'X' && plc[9] == 'X') || (plc[7] == 'x' && plc[8] == 'x' && plc[9] == 'x')
	|| (plc[1] == 'X' && plc[4] == 'X' && plc[7] == 'X') || (plc[1] == 'x' && plc[4] == 'x' && plc[7] == 'x')
	|| (plc[2] == 'X' && plc[5] == 'X' && plc[8] == 'X') || (plc[2] == 'x' && plc[5] == 'x' && plc[8] == 'x')
	|| (plc[3] == 'X' && plc[6] == 'X' && plc[9] == 'X') || (plc[3] == 'x' && plc[6] == 'x' && plc[9] == 'x')
	|| (plc[1] == 'X' && plc[5] == 'X' && plc[9] == 'X') || (plc[1] == 'x' && plc[5] == 'x' && plc[9] == 'x')
	|| (plc[3] == 'X' && plc[5] == 'X' && plc[7] == 'X') || (plc[3] == 'x' && plc[5] == 'x' && plc[7] == 'x'))
		return 1;
	else if((plc[1] == 'O' && plc[2] == 'O' && plc[3] == 'O') || (plc[1] == 'o' && plc[2] == 'o' && plc[3] == '0')
	|| (plc[4] == 'O' && plc[5] == 'O' && plc[6] == 'O') || (plc[4] == 'o' && plc[5] == 'o' && plc[6] == 'o')
	|| (plc[7] == 'O' && plc[8] == 'O' && plc[9] == 'O') || (plc[7] == 'o' && plc[8] == 'o' && plc[9] == 'o')
	|| (plc[1] == 'O' && plc[4] == 'O' && plc[7] == 'O') || (plc[1] == 'o' && plc[4] == 'o' && plc[7] == 'o')
	|| (plc[2] == 'O' && plc[5] == 'O' && plc[8] == 'O') || (plc[2] == 'o' && plc[5] == 'o' && plc[8] == 'o')
	|| (plc[3] == 'O' && plc[6] == 'O' && plc[9] == 'O') || (plc[3] == 'o' && plc[6] == 'o' && plc[9] == 'o')
	|| (plc[1] == 'O' && plc[5] == 'O' && plc[9] == 'O') || (plc[1] == 'o' && plc[5] == 'o' && plc[9] == 'o')
	|| (plc[3] == 'O' && plc[5] == 'O' && plc[7] == 'O') || (plc[3] == 'o' && plc[5] == 'o' && plc[7] == 'o'))
		return 2;
	else if(plc[1] != '1' && plc[2] != '2' && plc[3] != '3' &&
        	plc[4] != '4' && plc[5] != '5' && plc[6] != '6' &&
			plc[7] != '7' && plc[8] != '8' && plc[9] != '9')
		return 3;
   	else
   	printf("Game result ERROR!");
		return 0;
}
/**
 *
 * \brief That give a random number" 0 or 1 ".
 * \return 0 Player 1 start
 * \return 1 Player 2 start
 *
 */
int random_player(){
	int i;
	srand(time(NULL));
	i = rand() % 2;
	return i;
}
/**
 *
 * \brief This is the intelligent system and allows the PC play the game.
 * \return This returns a 1 if there is a winner, otherwise -1
 *
 */
int pc_choice(){
	// Look for first choice the middle field and the corner and let it be random
	if ((plc[5] == '5') && (plc[1] == '1') && (plc[3] == '3') && (plc[7] == '7') && (plc[9] == '9')){
		int random_2 = 0;
		while((random_2 != 5)&&(random_2 != 1)&&(random_2 != 3)&&(random_2 != 7)&&(random_2 != 9)){
		srand(time(NULL));
		random_2=rand() % 9;
		random_2 ++;
		}
	return random_2;
	}
// Check if the opposing team player's two options are side by side
	/*	like; 	x x .
	 * 		  	. . .
	 * 		    . . .
	 * */
	else if((plc[1] == game_sign1) && (plc[2] == game_sign1) && (plc[3] == '3'))
		return 3;
	else if((plc[2] == game_sign1) && (plc[3] == game_sign1) && (plc[1] == '1'))
		return 1;
	else if((plc[4] == game_sign1) && (plc[5] == game_sign1) && (plc[6] == '6'))
		return 6;
	else if((plc[5] == game_sign1) && (plc[6] == game_sign1) && (plc[4] == '4'))
		return 4;
	else if((plc[7] == game_sign1) && (plc[8] == game_sign1) && (plc[9] == '9'))
		return 9;
	else if((plc[8] == game_sign1) && (plc[9] == game_sign1) && (plc[7] == '7'))
		return 7;
//Check to see if the opposing team player's two options are under the other
	/*	like;	 x . .
		 * 	 	 x . .
		 * 	  	 . . .
		 * */
	else if((plc[1] == game_sign1) && (plc[4] == game_sign1) && (plc[7] == '7'))
		return 7;
	else if((plc[4] == game_sign1) && (plc[7] == game_sign1) && (plc[1] == '1'))
		return 1;
	else if((plc[2] == game_sign1) && (plc[5] == game_sign1) && (plc[8] == '8'))
		return 8;
	else if((plc[5] == game_sign1) && (plc[8] == game_sign1) && (plc[2] == '2'))
		return 2;
	else if((plc[3] == game_sign1) && (plc[6] == game_sign1) && (plc[9] == '9'))
		return 9;
	else if((plc[6] == game_sign1) && (plc[9] == game_sign1) && (plc[3] == '3'))
		return 3;
//Check if there is a free field between the PC's two options
	/*	like;	 o . .
		 * 	 	 . . .
		 * 	 	 o . .
		 * */
	else if((plc[1] == game_sign2) && (plc[7] == game_sign2) && (plc[4] == '4'))
		return 4;
	else if((plc[2] == game_sign2) && (plc[8] == game_sign2) && (plc[5] == '5'))
		return 5;
	else if((plc[3] == game_sign2) && (plc[9] == game_sign2) && (plc[6] == '6'))
		return 6;
	else if((plc[1] == game_sign2) && (plc[3] == game_sign2) && (plc[2] == '2'))
		return 2;
	else if((plc[4] == game_sign2) && (plc[6] == game_sign2) && (plc[5] == '5'))
		return 5;
	else if((plc[7] == game_sign2) && (plc[9] == game_sign2) && (plc[8] == '8'))
		return 8;
//Check if the opposing team player's two options are cross-over
	/*	like;    x . .
		 * 	  	 . . .
		 * 	     . . x
		 * */
	else if((plc[1] == game_sign1) && (plc[5] == game_sign1) && (plc[9] == '9'))
		return 9;
	else if((plc[5] == game_sign1) && (plc[9] == game_sign1) && (plc[1] == '1'))
		return 1;
	else if((plc[3] == game_sign1) && (plc[5] == game_sign1) && (plc[7] == '7'))
		return 7;
	else if((plc[7] == game_sign1) && (plc[5] == game_sign1) && (plc[3] == '3'))
		return 3;
//Check to see if there is a free field between the opposing team player's two options
	/*	like;    x . .
		 * 	  	 . . .
		 * 	     . . x
		 * */
	else if((plc[1] == game_sign1) && (plc[7] == game_sign1) && (plc[4] == '4'))
		return 4;
	else if((plc[2] == game_sign1) && (plc[8] == game_sign1) && (plc[5] == '5'))
		return 5;
	else if((plc[3] == game_sign1) && (plc[9] == game_sign1) && (plc[6] == '6'))
		return 6;
	else if((plc[1] == game_sign1) && (plc[3] == game_sign1) && (plc[2] == '2'))
		return 2;
	else if((plc[4] == game_sign1) && (plc[6] == game_sign1) && (plc[5] == '5'))
		return 5;
	else if((plc[7] == game_sign1) && (plc[9] == game_sign1) && (plc[8] == '8'))
		return 8;
//Check if PC has two fields side by side
	/*	like;    o o !
		 * 	  	 ! o o
		 * 	     . . .
		 * */
	else if((plc[1] == game_sign2) && (plc[2] == game_sign2) && (plc[3] == '3'))
		return 3;
	else if((plc[2] == game_sign2) && (plc[3] == game_sign2) && (plc[1] == '1'))
		return 1;
	else if((plc[4] == game_sign2) && (plc[5] == game_sign2) && (plc[6] == '6'))
		return 6;
	else if((plc[5] == game_sign2) && (plc[6] == game_sign2) && (plc[4] == '4'))
		return 4;
	else if((plc[7] == game_sign2) && (plc[8] == game_sign2) && (plc[9] == '9'))
		return 9;
	else if((plc[8] == game_sign2) && (plc[9] == game_sign2) && (plc[7] == '7'))
		return 7;
//Check if PC has two fields under to other
	/*	like;    o . .
		 * 	  	 . . .
		 * 	     o . .
		 * */
	else if((plc[1] == game_sign2) && (plc[4] == game_sign2) && (plc[7] == '7'))
		return 7;
	else if((plc[4] == game_sign2) && (plc[7] == game_sign2) && (plc[1] == '1'))
		return 1;
	else if((plc[2] == game_sign2) && (plc[5] == game_sign2) && (plc[8] == '8'))
		return 8;
	else if((plc[5] == game_sign2) && (plc[8] == game_sign2) && (plc[2] == '2'))
		return 2;
	else if((plc[3] == game_sign2) && (plc[6] == game_sign2) && (plc[9] == '9'))
		return 9;
	else if((plc[6] == game_sign2) && (plc[9] == game_sign2) && (plc[3] == '3'))
		return 3;
	//Check if PC has two fields cross-over
	/*	like;    o . .
		 * 	  	 . . .
		 * 	     . . o
		 * */
	else if((plc[1] == game_sign2) && (plc[5] == game_sign2) && (plc[9] == '9'))
		return 9;
	else if((plc[5] == game_sign2) && (plc[9] == game_sign2) && (plc[1] == '1'))
		return 1;
	else if((plc[3] == game_sign2) && (plc[5] == game_sign2) && (plc[7] == '7'))
		return 7;
	else if((plc[7] == game_sign2) && (plc[5] == game_sign2) && (plc[3] == '3'))
		return 3;
	//Check to see if there is a free field between the opposing team player's two options
	/*	like;    x . x
		 * 	  	 . . .
		 * 	     x . x
		 * */
	else if((plc[1] == game_sign2) && (plc[7] == game_sign2) && (plc[4] == '4'))
		return 4;
	else if((plc[2] == game_sign2) && (plc[8] == game_sign2) && (plc[5] == '5'))
		return 5;
	else if((plc[3] == game_sign2) && (plc[9] == game_sign2) && (plc[6] == '6'))
		return 6;
	else if((plc[1] == game_sign2) && (plc[3] == game_sign2) && (plc[2] == '2'))
		return 2;
	else if((plc[4] == game_sign2) && (plc[6] == game_sign2) && (plc[5] == '5'))
		return 5;
	else if((plc[7] == game_sign2) && (plc[9] == game_sign2) && (plc[8] == '8'))
		return 8;
	// PC try to make win field like "x x x or o o o" if three boxes are empty next to each other or one of them is a X or O.
	/*	like;    x x !
		 * 	  	 1  .
		 * 	     . .
		 * */
	else if(((plc[1] == game_sign1) || (plc[1] == game_sign2)) && ((plc[2] == '2') && (plc[3] == '3')))
		return 2;
	else if(((plc[2] == game_sign1) || (plc[2] == game_sign2)) && ((plc[1] == '1') && (plc[3] == '3')))
		return 1;
	else if(((plc[3] == game_sign1) || (plc[3] == game_sign2)) && ((plc[2] == '2') && (plc[1] == '1')))
		return 1;
	else if(((plc[4] == game_sign1) || (plc[4] == game_sign2)) && ((plc[5] == '5') && (plc[6] == '6')))
		return 5;
	else if(((plc[5] == game_sign1) || (plc[5] == game_sign2)) && ((plc[6] == '6') && (plc[4] == '4')))
		return 6;
	else if(((plc[6] == game_sign1) || (plc[6] == game_sign2)) && ((plc[5] == '5') && (plc[4] == '4')))
		return 4;
	else if(((plc[7] == game_sign1) || (plc[7] == game_sign2)) && ((plc[8] == '8') && (plc[9] == '9')))
		return 9;
	else if(((plc[8] == game_sign1) || (plc[8] == game_sign2)) && ((plc[7] == '7') && (plc[9] == '9')))
		return 7;
	else if(((plc[9] == game_sign1) || (plc[9] == game_sign2)) && ((plc[7] == '7') && (plc[8] == '8')))
		return 7;
	// PC try to get coner fields
	/*	like;    	 o . o
			 * 	  	 . . .
			 * 	     o . o
			 * */

	else if((plc[1] != 'X') && (plc[1] != 'x') && (plc[1] != 'O') && (plc[1] != 'o'))
		return 1;
	else if((plc[3] != 'X') && (plc[3] != 'x') && (plc[3] != 'O') && (plc[3] != 'o'))
		return 3;
	else if((plc[7] != 'X') && (plc[7] != 'x') && (plc[7] != 'O') && (plc[7] != 'o'))
		return 7;
	else if((plc[9] != 'X') && (plc[9] != 'x') && (plc[9] != 'O') && (plc[9] != 'o'))
		return 9;
//Place best option next to your last field
	else{
			int fnum;
			//random field number
			do{
				srand(time(NULL));
				fnum = rand() % 9;
				fnum ++;
			}while((plc[fnum] == '1') || (plc[fnum] == '2') || (plc[fnum] == '3')
				|| (plc[fnum] == '4') || (plc[fnum] == '5') || (plc[fnum] == '6')
				|| (plc[fnum] == '7') || (plc[fnum] == '8') || (plc[fnum] == '9'));

		return fnum;
		}
	}
/**
 *
 * \brief This is a function, used to reset the playing field.
 * \return This function return nothing.
 *
 */
void clean_table(){
	plc[0] = 'o';
	plc[1] = '1';
	plc[2] = '2';
	plc[3] = '3';
	plc[4] = '4';
	plc[5] = '5';
	plc[6] = '6';
	plc[7] = '7';
	plc[8] = '8';
	plc[9] = '9';
}






