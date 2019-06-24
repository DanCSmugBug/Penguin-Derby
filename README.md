# Penguin-Derby
A simple turn based racing game designed using basic text, written from scratch in C++

Penguin-Derby is a short game I created in mid May and used as a chance to try and make a new experience using only C++ code.
The bulk of the project was finished within a week, though I eventually implemented changes later to take care of input validation.

The game plays simply. Upon running the main function (found in PenguinDerby.cpp), you are prompted to determine the length of the race
track, as well as the number of players and computers. You can have no more than 8 players/computers total, though you can have any
combination of the two (4 players and 4 computers, 8 players and 0 computers, 8 computers and 0 players, etc).

You then are asked to select one of the three penguin types. The differences between the penguins come down to their Speed Die and
their total Stamina. The speed die is used to determine how far you move forward, and functions much like a standard game die.
Choosing to roll it will randomly generate a number between 1 and the highest value of the speed die (which for the standard Noodle
Penguin is 6). If you choose to spend a Stamina, you can move your maximum speed for that round. You do not regenerate Stamina for
the whole race, so take care not to waste it! Every turn you may determine whether you would like to roll the die or use a Stamina, 
and this happens every round until one (or several) penguins reaches the finish at the end of the round.

All penguins, both player and computer, move at the same time at the end of the round. If multiple penguins reach the finish line at
the same time, then the winner is determined by who went furthest past the finish line.
