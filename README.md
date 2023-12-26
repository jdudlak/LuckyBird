# LuckyBird
Code created by Julia Dudlak and Samir Sanchez Tejada.

Replicated Flappy Bird in C++ for an external Arduino arcade display. 

The waiting screen prompts the user to press and hold the middle button, indicating they are ready to play. Once pressed, gameplay will begin. The bird will travel though a series of pipes with varying openings–the player controls the heigh of the bird via the right(up) and left(down) buttons. The pipes are randomly generated to ensure the opening is always wide enough for the bird to fit through. Each obstacle successfully navigated results in additional points for the player. As the player moves along the course, the pipes spawn more frequently, resulting in the bird "speeding up" and therefore increasing the difficulty of the game. The game will end if a hit, or pipe collision, is detected. Once the game ends, both the user's score and the arcade cabinet's ultimate high score are displayed onto the LED panel. Finally, the user will be reprompted to play the game by pressing and holding the middle button. This game was created using C++ within Arduino IDE.

