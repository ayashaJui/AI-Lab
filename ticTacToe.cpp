#include<bits/stdc++.h>
using namespace std;

int row, col;
char board[3][3] = {{'1', '2', '3'},{'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int draw = 0;

void display()
{
    cout << endl << "\tPlayer1: [X]" << endl;
    cout << "\tPlayer2: [O]" << endl << endl << endl;
    for(int i=0; i<3; i++){
        if(i != 0)
        {
            cout << "\t    ------------------" << endl;
        }
        cout << "\t\t";
        for(int j=0; j<3; j++){
            cout << board[i][j];
            if(j != 2)
            {
                cout << " | " ;
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

void player_turn()
{
    if(turn == 'X')
    {
        cout << "\tPlayer1 [X] turn: " << endl << endl;

	}

	if(turn == 'O')
    {
        cout << "\tPlayer2 [O] turn: " << endl << endl;

	}

	cout << "\tEnter row(starts at 1): ";
    cin >> row;
    row--;
    cout << "\tEnter column(starts at 1): ";
    cin >> col;
    col--;

	if(row >= 3 || col >= 3 || row < 0 || col < 0)
    {
        cout << endl << "\tInvalid Choice!!" << endl << endl;
        return;
	}

	if(turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'X';
		turn = 'O';

	}
	else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		turn = 'X';
	}
	else
	{
		cout << endl << "\tAlready Filled!!Try Another one" << endl << endl;
	}

}

int gameOver()
{
    ///checking row and col
    for(int i=0; i<3; i++){
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
           {
               return 0;
           }
    }

    ///checking diagonally
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
    {
        return 0;
    }

    ///check if there is any field not filled
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 1;
            }
        }
    }

    draw = 1;
	return 0;
}

int main()
{
    cout << endl << "\t\tTic Tac Toe" << endl;
    cout << "\t----------------------------------" << endl << endl;

    while(gameOver() == 1)
    {
        display();
        player_turn();
    }

    display();

    if(turn == 'X' && draw == 0)
    {
        cout << endl << "\tPalyer2 [O] Wins the Game!!" << endl;
    }
	else if(turn == 'O' && draw == 0)
    {
        cout << endl << "\tPalyer1 [X] Wins the game!!" << endl;
    }
	else
    {
        cout << endl << "\tMatch Draw!!" << endl;
    }

	return 0;
}
