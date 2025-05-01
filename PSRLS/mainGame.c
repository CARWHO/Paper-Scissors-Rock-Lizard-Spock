// File:   mainGame.c
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  while-loop of switch cases which run the game

#include <stdio.h>
#include "gameLogic.h"
#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "playerInput.h"
#include "displayHandler.h"

typedef enum {
    CHOOSING,   // State where players are making their choices
    RESULT,     // State where the result of choices is processed
    DISPLAY     // State to display current scores and round number
} GameState;

int main(void)
{

    init();  // Initialize system peripherals and display

    int player1_score = 0;  // Score counter for player 1
    int player2_score = 0;  // Score counter for player 2
    const int rounds = 4;   // Number of rounds in the game
    int round_number = 1;   // Track the current round
    int result = 0;         // Result of player choices
    GameState state = CHOOSING;  // Initial state: players choose their actions

    // Main game loop - runs for the specified number of rounds
    while (round_number < rounds) {
        switch (state) {
            case CHOOSING: {
                result = get_player_choice();  // Get the player's choices
                state = RESULT;  // Move to RESULT state to process the outcome
                break;
            }
            case RESULT: {
                if (result == 1) {
                    player1_score++;  // Increment player 1's score if they won
                } else if (result == 2) {
                    player2_score++;  // Increment player 2's score if they won
                }
                state = DISPLAY;  // Move to DISPLAY state to show the scores
                break;
            }
            case DISPLAY: {
                display_score(round_number,player1_score, player2_score);  // Show current scores
                round_number++;  // Proceed to the next round
                state = CHOOSING;  // Return to CHOOSING state for the next round
                break;
            }
        }
        pacer_wait();  // Sync with system clock
        tinygl_update();  // Update the display
    }

    // Display final result once all rounds are complete
    if (player1_score > player2_score) {
        display_win();  // Display player 1 victory
    } else if (player1_score < player2_score) {
        display_lose();  // Display player 2 victory
    } else {
        display_tied();  // Display tie if both scores are equal
    }

    // Infinite loop to keep displaying the final result
    while(1) {
        pacer_wait();
        tinygl_update();
    }
}
