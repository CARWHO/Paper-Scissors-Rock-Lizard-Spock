// File:   comms.h
// Author: Oscar Hutton - 34641212
// Author: Takudzwanashe Gumbo - 48673271
// Date:   02 - October 2024
// Descr:  comms.h for Rock-Paper-Scissors-Lizard-Spock game

#include "ir_uart.h"

#ifndef IR_COMMUNICATION_H
#define IR_COMMUNICATION_H

// fx to send a choice via IR
void send_ir_signal(char choice);

// fx to receive a choice via IR
char receive_ir_signal(void);

// fx to check if IR can receive
int ir_sensor_can_receive(void);

#endif
