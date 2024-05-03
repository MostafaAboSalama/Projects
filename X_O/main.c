#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int turn = 1;

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void printMatrix(char matrix[3][3]);
int update(char matrix[3][3], int index, char ch);
void moves();
char check_board_for_winner(char matrix[3][3]);
void reset_game();

int main()
{
    while (1)
    {
        for (int i = 0; i < 9; i++)
        {
            moves();
            if (turn > 4)
            {
                char winner = check_board_for_winner(matrix);
                if (winner != ' ')
                {
                    if (winner == 'X')
                        {
                            printf("Player X wins!\n");
                            exit(1);
                        }
                    else if (winner == 'O')
                    {
                         printf("Player O wins!\n");
                         exit(1);
                    }

                }
            }
        }

            printf("The game ends in a draw! Let's open a new game\n\n");
            reset_game();
    }

    return 0;
}

void printMatrix(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'O' || matrix[i][j] == 'X')
                printf("%c  ", matrix[i][j]);
            else
                printf("%c  ", matrix[i][j]);
        }
        printf("\n\n");
    }
}

int update(char matrix[3][3], int index, char ch)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == '0' + index)
            {
                matrix[i][j] = ch;
                return 1;
            }
        }
    }
    return 0;
}

void moves()
{
    int index;
    printMatrix(matrix);
    if (turn % 2 == 1)
    {
        printf("\n'X' MOVE : ");
        scanf("%d", &index);
        printf("\n");
        if (update(matrix, index, 'X') == 1)
            turn++;
        else
        {
            printf("Choose an EMPTY Index!!\n");
            moves();
        }
    }
    else
    {
        printf("\n'O' MOVE : ");
        scanf("%d", &index);
        printf("\n");
        if (update(matrix, index, 'O') == 1)
            turn++;
        else
        {
            printf("Choose an EMPTY Index!!\n");
            moves();
        }
    }
}

char check_board_for_winner(char matrix[3][3])
{
    // rows
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
        {
            return matrix[i][0];
        }
    }

    // columns
    for (int j = 0; j < 3; j++)
    {
        if (matrix[0][j] == matrix[1][j] && matrix[0][j] == matrix[2][j])
        {
            return matrix[0][j];
        }
    }

    // diagonals
    if ((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) ||
        (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]))
    {
        return matrix[1][1];
    }

    if (turn == 9)
    {
        return 255;
    }

    return ' ';
}

void reset_game()
{
    turn = 1;
    char index = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = index++;
        }
    }
   // main();
}
