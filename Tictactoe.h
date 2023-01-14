/*
 * Tictactoe.h
 *
 *  Created on: Jan 22, 2021
 *      Author: Caner Yildiz
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

	// Variables
	extern char plc[11];
	extern char player_1[16];
	extern char player_2[16];
	extern char game_sign1;
	extern char game_sign2;

	// Functions
    void place();
	int checkwin();
	int game_result();
	int random_player();
	int pc_choice();
	void clean_table();


#endif /* TICTACTOE_H_ */
