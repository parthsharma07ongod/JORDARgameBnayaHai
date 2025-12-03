🚗  Console Car Dodging Game (C Language)
========================================

This is a simple console-based dodging game written in C.  
The player controls "^" and must avoid falling "*" obstacles.  
The game runs directly in the terminal and does not require any graphics libraries.

----------------------------------------
🎮  How to Play
----------------------------------------

Your player symbol: ^  
Falling obstacles: *

Controls:
⬅️  Left Arrow  – Move left  
➡️  Right Arrow – Move right  

Your goal is to avoid colliding with obstacles for as long as possible.

----------------------------------------
✨  Features Implemented
----------------------------------------

✔️  Score System  
The score increases whenever both obstacles move past the player safely.

✔️  Lives System  
- Game starts with 3 lives  
- Collision reduces 1 life  
- At 0 lives, the game ends and shows the final score

✔️  Multiple Obstacles  
- Two obstacles fall at the same time  
- Their lanes are assigned randomly  
- They may appear in the same lane or in different lanes  
- Their timings are offset to make gameplay more challenging

----------------------------------------
🧠  How the Game Works
----------------------------------------

1. The program reads arrow key input in each loop  
2. Two obstacles move down step-by-step  
3. Collision is checked at the bottom row  
4. Score and lives update accordingly  
5. The screen redraws with the new frame  
6. When lives reach zero, Game Over is displayed

This keeps the game smooth and easy to understand even for beginners.
