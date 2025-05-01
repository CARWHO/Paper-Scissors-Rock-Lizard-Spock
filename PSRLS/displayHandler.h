// File:   displayHandler.h
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  displayHandler.h for Rock-Paper-Scissors-Lizard-Spock game

#ifndef DISPLAYHANDLER_H
#define DISPLAYHANDLER_H

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "playerInput.h"

/**
 * @brief Initializes the system and display configurations for the game.
 *
 * This function sets up the system initialization, TinyGL display settings, font,
 * and pacer for controlling display updates.
 */
void init(void);

/**
 * @brief Displays the score for the current round.
 *
 * @param round The current round number.
 * @param player1_score The score of player 1.
 * @param player2_score The score of player 2.
 */
void display_score(int round, int player1_score, int player2_score);

/**
 * @brief Displays a "YOU WIN" message.
 */
void display_win(void);

/**
 * @brief Displays a "YOU LOSE" message.
 */
void display_lose(void);

/**
 * @brief Displays a "YOU TIED" message.
 */
void display_tied(void);

#endif
