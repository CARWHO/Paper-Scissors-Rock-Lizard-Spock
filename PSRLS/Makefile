# File:   Makefile
# Author: Oscar Hutton - 34641212
# Author: Takudzwanashe Gumbo - 48673271
# Date:   02 - October 2024
# Descr:  Makefile for testing playerInput in the Rock-Paper-Scissors-Lizard-Spock game

# Definitions
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../utils -I../fonts -I../drivers -I../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm

# Default target
all: gameTest.out

# Compile: create object files from C source files
gameLogic.o: gameLogic.c gameLogic.h
	$(CC) -c $(CFLAGS) $< -o $@

displayHandler.o: displayHandler.c displayHandler.h
	$(CC) -c $(CFLAGS) $< -o $@

mainGame.o: mainGame.c mainGame.h
	$(CC) -c $(CFLAGS) $< -o $@

comms.o: comms.c comms.h
	$(CC) -c $(CFLAGS) $< -o $@

playerInput.o: playerInput.c playerInput.h
	$(CC) -c $(CFLAGS) $< -o $@

# Compile system and driver object files
system.o: ../drivers/avr/system.c ../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../drivers/avr/pio.c ../drivers/avr/pio.h ../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../drivers/display.c ../drivers/avr/system.h ../drivers/display.h ../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../drivers/ledmat.c ../drivers/avr/pio.h ../drivers/avr/system.h ../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../utils/font.c ../drivers/avr/system.h ../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../drivers/navswitch.c ../drivers/avr/delay.h ../drivers/avr/pio.h ../drivers/avr/system.h ../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../utils/tinygl.c ../drivers/avr/system.h ../drivers/display.h ../utils/font.h ../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../utils/pacer.c ../drivers/avr/system.h ../drivers/avr/timer.h ../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../drivers/avr/timer.c ../drivers/avr/system.h ../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

timer0.o: ../drivers/avr/timer0.c ../drivers/avr/system.h ../drivers/avr/timer0.h
	$(CC) -c $(CFLAGS) $< -o $@

usart1.o: ../drivers/avr/usart1.c ../drivers/avr/system.h ../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

ir_uart.o: ../drivers/avr/ir_uart.c ../drivers/avr/system.h ../drivers/avr/ir_uart.h
	$(CC) -c $(CFLAGS) $< -o $@

prescale.o: ../drivers/avr/prescale.c ../drivers/avr/system.h ../drivers/avr/prescale.h
	$(CC) -c $(CFLAGS) $< -o $@


# Link: create ELF output file from object files
gameTest.out: mainGame.o playerInput.o displayHandler.o comms.o gameLogic.o system.o pio.o display.o ledmat.o font.o navswitch.o tinygl.o pacer.o timer.o ir_uart.o usart1.o timer0.o prescale.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@

# Target: clean project
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex

# Target: program project
.PHONY: program
program: gameTest.out
	$(OBJCOPY) -O ihex gameTest.out gameTest.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash gameTest.hex; dfu-programmer atmega32u2 start
