// File:   gameLogic.c
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  gameLogic.c for Rock-Paper-Scissors-Lizard-Spock game

#include "gameLogic.h"

/**
 * @brief Determines the outcome of the game based on player and opponent choices.
 *
 * This function compares the player's choice with the opponent's choice
 * according to the rules of Rock-Paper-Scissors-Lizard-Spock. It returns:
 * - 0 if the round is a tie,
 * - 1 if the player wins, and
 * - 2 if the opponent wins.
 *
 * @param player_choice The player's selected move (R, P, S, L, or K).
 * @param opponent_choice The opponent's selected move (R, P, S, L, or K).
 * @return An integer representing the result of the match:
 *         0 for a tie, 1 for a player win, 2 for an opponent win.
 */
int win(char player_choice, uint8_t opponent_choice)
{
    if (player_choice == opponent_choice) {
        return 0; // It's a tie
    }

    // Player wins conditions
    if ((player_choice == 'R' && (opponent_choice == 'S' || opponent_choice == 'L')) ||
        (player_choice == 'P' && (opponent_choice == 'R' || opponent_choice == 'K')) ||
        (player_choice == 'S' && (opponent_choice == 'P' || opponent_choice == 'L')) ||
        (player_choice == 'L' && (opponent_choice == 'P' || opponent_choice == 'K')) ||
        (player_choice == 'K' && (opponent_choice == 'R' || opponent_choice == 'S'))) {
        return 1; // Player wins
    } else {
        return 2; // Opponent wins
    }
}
