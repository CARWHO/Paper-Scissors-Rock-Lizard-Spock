// File:   playerInput.c
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  Sends and Receives IR data and checks if inputs are valid

#include "playerInput.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "gameLogic.h"
#include "comms.h"

#define WAIT_RATE 1000  // Define wait rate for pacer

/**
 * @brief Handles player input via navswitch, sends IR signal, and receives opponent's choice.
 * @return Result of the comparison between player and opponent's choices.
 */
int get_player_choice(void)
{

    ir_uart_init();  // Initialize the IR communication

    static char choices[] = {'R', 'P', 'S', 'L', 'K'};  // Array of choices: Rock, Paper, Scissors, Lizard, Spock
    int current_choice_index = 0;  // Track the current option index
    char final_choice = '\0';  // Final choice of the player
    int result = 0;  // Result of comparison (1: player wins, 2: opponent wins, 0: tie)
    bool ir_sent = 0;  // Flag to check if IR signal has been sent
    bool ir_received = 0;  // Flag to check if IR signal has been received
    uint8_t opp_choice = '\0';  // Opponent's choice

    // Continuous loop to handle player input and IR communication
    while (1) {
        navswitch_update();  // Update navswitch state

        if (ir_sent == 0) {
            // Cycle through the options when NAVSWITCH_NORTH is pressed
            if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
                current_choice_index = (current_choice_index + 1) % 5;  // Cycle through the 5 options
            }

            // Display the current choice on the screen
            char choice_str[2];
            choice_str[0] = choices[current_choice_index];  // Get current option
            choice_str[1] = '\0';
            tinygl_text(choice_str);  // Display the selected option

            tinygl_update();  // Update TinyGL display
            pacer_wait();  // Maintain timing with pacer
        }

        // Confirm the choice when NAVSWITCH_PUSH is pressed
        if (navswitch_push_event_p(NAVSWITCH_PUSH) && ir_sent == 0) {
            final_choice = choices[current_choice_index];  // Store the final choice
            send_ir_signal(final_choice);  // Send the choice via IR signal
            tinygl_clear();  // Clear the display
            tinygl_text("...");  // Show waiting message
            tinygl_update();
            ir_sent = 1;  // Set flag indicating choice has been sent
        }

        // Check if the IR sensor has received a valid signal
        if (ir_sensor_can_receive() && ir_received == 0) {
            opp_choice = receive_ir_signal();  // Receive the opponent's choice
            if (opp_choice == 'R' || opp_choice == 'P' || opp_choice == 'S' || opp_choice == 'L' || opp_choice == 'K') {
                ir_received = 1;  // Set flag indicating a valid choice has been received
            } else {
                opp_choice = '\0';  // Reset opponent choice if invalid
                ir_received = 0;  // Reset received flag
            }
        }

        // Once both signals are sent and received, determine the result
        if (ir_sent == 1 && ir_received == 1) {
            result = win(final_choice, opp_choice);  // Compare player and opponent choices
            return result;  // Return the result of the game round
        }
    }
}
