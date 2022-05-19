#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Play(int bet); 

int cash = 100;
int main()
{

    printf("**Welcome to Virtual casino**\n\n");  
    printf("Total cash = $%d\n",cash);
    int bet;
    while (cash > 0)
    {
        printf("What's your bet? $");
        scanf("%d",&bet);   // This save the amount the player want to bet into the address of variable "bet"
        if(bet == 0 || bet > cash) break;
        Play(bet);
        printf("\n**************************************\n");
    }
    
}

void Play(int bet)
{
    char C[3] = {
        'J','K','Q'
    };
    printf("Shuffling.....");
    srand(time(NULL));
    int i;
    for(i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x]; C[x] = C[y];
        C[y] = temp; 
    }
    int Playersguess;
    printf("What's the positioin of qeen - 1,2 or 3?");
    scanf("%d", &Playersguess);
    if (C[Playersguess - 1] == 'Q')
    {
        cash += 3*bet;
        printf("You Win ! Result  = \"%c %c %c\" Total Cash= %d\n",C[0],C[1],C[2],cash);
    }
    else {
        cash -=bet;
        printf("You lose ! Result  = \"%c %c %c\" Total Cash= %d\n",C[0],C[1],C[2],cash);
    }
}