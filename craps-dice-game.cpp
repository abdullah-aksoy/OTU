#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main(void)
{
    int dice1, dice2, sum = 0, playerScore = 0, pcScore = 0;
    char enter, process;
    bool loop = true;

    do {
        system(CLEAR); // for Linux/Mac, use "clear"

        printf("\t\t\t\t\t\t----------Craps Dice Game----------\n\n");
        printf("In Craps, the player, also known as the shooter, wins if the sum of the two dice is\n"); 
        printf("7 or 11 on the first roll. If the sum is 2, 3, or 12 on the first roll, the shooter loses.\n");

        srand(time(NULL));

        printf("\nPress the enter to throw first dice: ");
        scanf("%c", &enter);
        dice1 = rand() % 6 + 1;
        printf("First dice: %d\n", dice1);

        printf("Press the enter to throw second dice: ");
        scanf("%c", &enter);
        dice2 = rand() % 6 + 1;
        printf("Second dice: %d\n", dice2);

        sum = dice1 + dice2;
        printf("\nSum: %d\n", sum);

        int point=0;

        if ((sum == 7) || (sum == 11)) {
            printf("Congratulations. Your sum is %d, you win!\n", sum);
            playerScore++;
        } else if ((sum == 2) || (sum == 3) || (sum == 12)) {
            printf("You lost\n");
            pcScore++;
        } else {
            point = sum;
            printf("Your point is %d\n", point);

            do {
                printf("Press the enter to roll the dice again: ");
                scanf("%c", &enter);
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;
                sum = dice1 + dice2;
                printf("First dice: %d, Second dice: %d, Sum: %d\n", dice1, dice2, sum);
            } while ((sum != point) && (sum != 7));

            if (sum == point) {
                printf("Congratulations. Your sum is %d, you win!\n", sum);
                playerScore++;
            } else {
                printf("You lost\n");
                pcScore++;
            }
        }

        printf("\nPlayer Score: %d\n", playerScore);
        printf("PC Score:%d\n",pcScore);

        do {
            printf("\nWould you like to play again\n[y] Yes\t\t [n] No\n");
            scanf(" %c%c", &process, &enter);
            if ((process == 'y') || (process == 'Y')) {
                loop = true;
            } else if ((process == 'n') || (process == 'N')) {
                loop = false;
                if(playerScore > pcScore) {
                    printf("You win the game\n");
                    printf("\nPlayer Score: %d\n", playerScore);
                    printf("PC Score:%d\n",pcScore);
                } else if(playerScore < pcScore) {
                    printf("You lost the game\n");
                    printf("\nPlayer Score: %d\n", playerScore);
                    printf("PC Score:%d\n",pcScore);
                } else {
                    printf("Game is draw\n");
                    printf("\nPlayer Score: %d\n", playerScore);
                    printf("PC Score:%d\n",pcScore);
                }
            } else {
                loop = false;
                system(CLEAR);
                printf("Wrong input\n");
            }
        } while (((process != 'y') && (process != 'Y')) && ((process != 'n') && (process != 'N')));

    } while (loop);

    return 0;
}