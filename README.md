![Schematic](./Schematic.png)

# Rock Paper Scissors Lizard Spock

The Big Bang Theory version of rock-paper-scissors, running on an ATmega32U2. Built this for an embedded systems course.

Two players, three rounds, winner displayed on LEDs.

## Rules

Same as the show:
- Scissors cuts Paper, decapitates Lizard
- Paper covers Rock, disproves Spock
- Rock crushes Scissors, crushes Lizard
- Lizard eats Paper, poisons Spock
- Spock vaporizes Rock, smashes Scissors

## Hardware

Custom PCB with:
- ATmega32U2 microcontroller
- 5 input buttons per player
- LED display for score/winner
- Debounced inputs (learned this the hard way after ghost inputs ruined a demo)

Player 1 is always "you" from the board's perspective - LEDs show P1/P2 win states accordingly.
