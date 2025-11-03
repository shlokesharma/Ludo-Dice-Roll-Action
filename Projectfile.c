#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GOAL 57

int rollDice() {
    return (rand() % 6) + 1;
}

void waitDots() {
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
    }
    printf("\n");
}

int main() {
    char choice;
    int position = -1;
    int dice;
    srand((unsigned)time(NULL));

    printf("\n🎲  Ludo - Dice Roll Action (Single Player) 🎲\n");
    printf("-------------------------------------------------\n");
    printf("Rules:\n");
    printf("1) Need a 6 to move out of HOME.\n");
    printf("2) Rolling a 6 gives an extra turn.\n");
    printf("3) Must land exactly on %d to win.\n", GOAL);
    printf("-------------------------------------------------\n\n");

    do {
        printf("Press R to roll the dice or Q to quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q') {
            printf("\nYou chose to quit. Goodbye!\n");
            break;
        } else if (choice == 'R' || choice == 'r') {
            int extraTurn = 0;
            dice = rollDice();
            printf("\nYou rolled: %d\n", dice);

            if (position == -1) {
                if (dice == 6) {
                    position = 0;
                    printf("✅ You got a 6! You moved out of HOME to position 0.\n");
                    extraTurn = 1;
                } else {
                    printf("❌ You need a 6 to enter the board. Stay at HOME.\n");
                }
            } else {
                if (position + dice > GOAL) {
                    printf("⚠️ Move would overshoot the goal. You stay at position %d.\n", position);
                } else {
                    position += dice;
                    printf("➡️ You moved to position %d.\n", position);
                    if (position == GOAL) {
                        printf("\n🏁 Congratulations! You have reached the GOAL and won the game! 🏆\n");
                        break;
                    }
                    if (dice == 6) {
                        extraTurn = 1;
                        printf("🎉 You rolled a 6! You get an extra turn.\n");
                    }
                }
            }

            while (extraTurn) {
                extraTurn = 0;
                printf("\n-- Extra turn -- Press R to roll extra, or Q to quit: ");
                scanf(" %c", &choice);
                if (choice == 'Q' || choice == 'q') {
                    printf("\nYou chose to quit during extra turn. Goodbye!\n");
                    return 0;
                } else if (choice == 'R' || choice == 'r') {
                    dice = rollDice();
                    printf("\nYou rolled: %d\n", dice);
                    if (position + dice > GOAL) {
                        printf("⚠️ Overshoot. Stay at %d.\n", position);
                    } else {
                        position += dice;
                        printf("➡️ You moved to position %d.\n", position);
                        if (position == GOAL) {
                            printf("\n🏁 Congratulations! You have reached the GOAL and won the game! 🏆\n");
                            return 0;
                        }
                        if (dice == 6) {
                            extraTurn = 1;
                            printf("🎲 Another 6! One more extra turn.\n");
                        }
                    }
                } else {
                    printf("Invalid input. Extra turn skipped.\n");
                }
            }
        } else {
            printf("Invalid input. Please press R or Q.\n");
        }

        printf("\nAnalyzing next step");
        waitDots();
        printf("\nCurrent position: ");
        if (position == -1) printf("HOME\n");
        else printf("%d\n", position);

    } while (1);

    printf("\nThank you for playing Ludo - Dice Roll Action!\n\n");
    return 0;
}
