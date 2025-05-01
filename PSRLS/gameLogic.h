// File:   gameLogic.h
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  gameLogic.h for Rock-Paper-Scissors-Lizard-Spock game

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdio.h>

/**
 * @brief Determines the winner between two players in the Rock-Paper-Scissors-Lizard-Spock game.
 *
 * This function compares the player's choice and the opponent's choice, returning the result
 * based on the game rules. It supports five options: Rock, Paper, Scissors, Lizard, and Spock.
 *
 * @param player1_choice The choice of player 1 (e.g., 'R' for Rock, 'P' for Paper, etc.).
 * @param player2_choice The choice of player 2 (opponent), as a character (e.g., 'S' for Scissors, etc.).
 * @return int The result of the game round:
 *         0 for a tie,
 *         1 if player 1 wins,
 *         2 if player 2 wins.
 */
int win(char player1_choice, uint8_t player2_choice);

#endif
