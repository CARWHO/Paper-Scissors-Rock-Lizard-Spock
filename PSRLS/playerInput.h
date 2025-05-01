// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  playerInput.h for Rock-Paper-Scissors-Lizard-Spock game

#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "navswitch.h"

/**
 * @brief Function to get the player's choice based on navswitch input.
 *
 * This function continuously checks the navswitch direction and assigns
 * the player's choice based on their input. The function supports
 * multiple options such as Rock, Paper, Scissors, Lizard, and Spock,
 * indicated by navswitch directions.
 *
 * @return The character representing the player's choice:
 *         'R' for Rock,
 *         'P' for Paper,
 *         'S' for Scissors,
 *         'L' for Lizard,
 *         'K' for Spock.
 */
int get_player_choice(void);

#endif
