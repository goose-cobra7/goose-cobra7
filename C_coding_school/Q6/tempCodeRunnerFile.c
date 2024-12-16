#include <stdio.h>
#define TURN 20
#include <stdlib.h> 
#include <time.h>
int main()
{
    int array[TURN];
    srand(time(NULL)); //create random seed for rand()
    for (int i = 0; i < TURN; i++) //create random array
    {
        array[i] = rand() % 100 + 1;
        if (array[i] == 0) //number is zero (invalid)
        {
            i--;
            continue; 
        } 
    }
    /*for (int i = 0; i < TURN; i++)
    {
        printf("%d ", array[i]);
    }*/ 
    //debug tool
    int turn_desider = 1; // deside which turn is it 1 for player 1 , -1 for player 2
    int left_side = 0; // left side
    int other_side_counter = TURN-1; //right side
    int player1_score = 0, player2_score = 0; //score
    for (int i = 0; i < TURN; i++)
    {
        int temp;
        int element = left_side; 
        /*the reason for the element creation is to be able to run on each of the array
        element without intirefence (like if i use to run on "int left_side")
        element can be also thoght as "int temp" for temperery*/
        while (element < other_side_counter+1)//prints all elememt still in the game
        {
            printf("%d ", array[element]);
            element++;
        }
        printf("\n");
        
        if (turn_desider == 1) //player 1 turns
        {
            printf("player 1: select one of the array edges: press 1 for %d or 2 for %d", array[left_side], array[other_side_counter]);
            scanf(" %d", &temp);
            if (temp == 1) //choose the left side
            {
                player1_score += array[left_side];
                left_side++;
                turn_desider = -1;//switch turn to player 2
            }else if (temp == 2) //choose the right
            {
                player1_score += array[other_side_counter];
                other_side_counter--;
                turn_desider = -1;//switch turn to player 2
            }else{
                printf("ERROR: invalid input\n"); //entered number which is nut 1 or 2
                i--;//reset the turn
            }
            temp = 100;
        }else if (turn_desider == -1) //payer 2 turns
        {
            printf("player 2: select one of the array edges: press 1 for %d or 2 for %d", array[left_side], array[other_side_counter]);
            scanf(" %d", &temp);
            if (temp == 1) //choose the left side
            {
                player2_score += array[left_side];
                left_side++;
                turn_desider = 1;//switch turn to player 1
            }else if (temp == 2) //choose the right side
            {
                player2_score += array[other_side_counter];
                other_side_counter--;
                turn_desider = 1; //switch turn to player 1
            }else{
                printf("ERROR: invalid input\n");//entered number which is nut 1 or 2
                i--; //reset the turn
            }
            
            temp = 100;
        }
        
       
    }
    if (player1_score > player2_score) // player 1 wins
    {
        printf("Player 1 wins with a score of %d", player1_score);
    }else if (player2_score > player1_score) // player 2 wins
    {
        printf("Player 2 wins with a score of %d", player2_score);
    }else{ //draw
        printf("It's a draw with scores of %d",player2_score);
    }
    
    
    return 0;
}
