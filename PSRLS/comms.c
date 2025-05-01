// File:   comms.c
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  comms.c for Rock-Paper-Scissors-Lizard-Spock game

#include "comms.h"
#include "ir_uart.h"

/**
 * @brief Sends an IR signal representing the player's choice.
 *
 * This function transmits a character choice over the IR UART.
 *
 * @param choice The character representing the player's choice (e.g., '0' for Rock).
 */
void send_ir_signal(char choice) 
{
    return ir_uart_putc(choice); // Send the character over IR
}


/**
 * @brief Receives an IR signal.
 *
 * This function retrieves a character transmitted over the IR UART.
 *
 * @return char The received character, which corresponds to the choice of the other player.
 */
char receive_ir_signal(void) 
{
    return ir_uart_getc(); // Get the character from the IR
}


/**
 * @brief Checks if the IR sensor is ready to receive a signal.
 *
 * This function checks if there is data available to read from the IR UART.
 *
 * @return int Returns 1 (true) if the sensor is ready to receive, 0 (false) otherwise.
 */
int ir_sensor_can_receive(void) 
{
    return ir_uart_read_ready_p(); // Check if there is data available to read
}
