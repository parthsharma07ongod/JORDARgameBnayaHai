#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

/*to remove flicker*/
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
    srand(time(0));

    int x = 1;              // player position (0 to 2)
    int step1 = 0;           // obstacle 1 vertical movement
    int obstaclePos1 = rand() % 3;   // 0,1,2 lane
    int step2 = -5;              // obstacle 2 vertical movement
    int obstaclePos2 = rand()%3;
    int score=0;
    int lives=3;
    int gameOver=0;
    while(obstaclePos2==obstaclePos1){     //obstacles not in same lane
            obstaclePos2=rand()%3;
        }

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            int ch = getch();

            if(ch==224){
                ch=getch();
            }

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
		// system("cls");
		clear_screen_fast();
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step1 || i == step2) {

                if (i == step1 && obstaclePos1 == 0) printf("| *        |\n");
                else if (i == step1 && obstaclePos1 == 1) printf("|     *    |\n");
                else if (i == step1 && obstaclePos1 == 2) printf("|        * |\n");

                else if(i == step2 && obstaclePos2 == 0) printf("| *        |\n");
                else if(i == step2 && obstaclePos2 == 1) printf("|     *    |\n");
                else if(i == step2 && obstaclePos2 == 2) printf("|        * |\n");

                else printf("|           |\n");

            } 
            else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| ^         |\n");
        else if (x == 1)
            printf("|     ^     |\n");
        else if (x == 2)
            printf("|        ^  |\n");
            if(lives>0)

        // ---- COLLISION ----
        if ((step1 == 10 && x == obstaclePos1) || (step2 == 10 && x == obstaclePos2)) {
        	Sleep(500);
            lives--;
            if(lives<=0){
                lives=0;
                gameOver=1;
            }
            if(!gameOver){
            step1=0;
            obstaclePos1=rand()%3;

            step2=-5;
            obstaclePos2=rand()%3;
            }
        }
                printf("\n\n\n\nScore: %d | Lives: %d\n",score,lives);
            if(gameOver){
                printf("\nGame Over! Such a noob >.<\n");
                printf("Your Final Score: %d\n",score);
                break;
            }

        Sleep(120);

        // Obstacle 1
        step1++;
        if (step1 > 10) {
            step1 = 0;
            obstaclePos1 = rand() % 3; // new lane
            score++;
        }
        // Obstacle 2
        step2++;
        if(step2 > 10){
            step2 = -5;
            obstaclePos2 = rand()%3;
            score++;
            while(obstaclePos2==obstaclePos1){
            obstaclePos2=rand()%3;
            }
        }
        
    }

    return 0;
}
