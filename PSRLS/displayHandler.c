// File:   display.c
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  display functions, for each part of the game

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "playerInput.h"
#include "gameLogic.h"
#include "playerInput.h"

#define PACER_RATE 500       // Frequency at which the pacer runs
#define MESSAGE_RATE 20      // Speed at which messages scroll on the display
#define DISPLAY_DELAY 1000   // Delay for regular messages (adjust as necessary)
#define SCORE_DISPLAY_DELAY 5500  // 3-second delay to display the score

/**
 * @brief Initializes the system and TinyGL display.
 *
 * This function sets up the system, initializes TinyGL with the defined pacer rate,
 * configures the font for display, sets the text speed, and initializes the pacer.
 */
void init(void) 
{
    system_init();
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    pacer_init(PACER_RATE);
}

/**
 * @brief Displays the current score after each round.
 *
 * This function creates a message displaying the current round and the scores of
 * both players, and then it scrolls the message on the screen for a set delay.
 *
 * @param round The current round number.
 * @param player1_score The score of player 1.
 * @param player2_score The score of player 2.
 */
void display_score(int round, int player1_score, int player2_score) 
{
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL); // Set scrolling mode for the text

    // Create a message to display the current score of both players
    char score_message[20]; // Increased size to accommodate the score format
    snprintf(score_message, sizeof(score_message), "ROUND: %d P1:%d P2:%d", round, player1_score, player2_score);

    tinygl_text(score_message); // Display the score

    for (int i = 0; i < SCORE_DISPLAY_DELAY; i++) {  // 3-second delay (adjust based on PACER_RATE)
        pacer_wait();
        tinygl_update();
    }
}

/**
 * @brief Displays a "YOU WIN" message when the player wins.
 */
void display_win(void) 
{
    char winner_str[20];
    sprintf(winner_str,"YOU WIN");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(winner_str);
}

/**
 * @brief Displays a "YOU LOSE" message when the player loses.
 */
void display_lose(void) 
{
    char lose_str[20];
    sprintf(lose_str,"YOU LOSE");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(lose_str);
}

/**
 * @brief Displays a "YOU TIED" message when the game is tied.
 */
void display_tied(void) 
{
    char tied_str[20];
    sprintf(tied_str,"YOU TIED");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(tied_str);
}
