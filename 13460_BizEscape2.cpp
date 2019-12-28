#include <iostream>

using namespace std;

struct boardObject
{
	char TYPE = NULL;
	char BIZ = NULL;
	int x = -1;
	int y = -1;

	boardObject* left;
	boardObject* right;
	boardObject* up;
	boardObject* down;

	boardObject* L_end;
	boardObject* R_end;
	boardObject* U_end;
	boardObject* D_end;
};

// directiosn: u, d, l, r

// returns the end tile of each direction
boardObject* searchEnd(boardObject* board, char direction)
{
	if (board->TYPE == '#')
	{
		return board;
	}

	boardObject* End = board;

	if (direction == 'u')
	{
		while ((End->up)->TYPE != '#')
		{
			End = End->up;
		}
		return End;
	}

	else if (direction == 'd')
	{
		while ((End->down)->TYPE != '#')
		{
			End = End->down;
		}
		return End;
	}

	else if (direction == 'r')
	{
		while ((End->right)->TYPE != '#')
		{
			End = End->right;
		}
		return End;
	}

	else if (direction == 'l')
	{
		while ((End->left)->TYPE != '#')
		{
			End = End->left;
		}
		return End;
	}

	return End;
}

void moveBiz(boardObject* board_R, boardObject* board_B, char direction)
{
	if (direction == 'u')
	{
		bool RB{ false };
		bool BR{ false };
		boardObject* tmpBoardUp = board_R;
		boardObject* tmpBoardDown = board_R;

		while ((tmpBoardUp->up)->TYPE != '#')
		{
			if ((tmpBoardUp->up)->BIZ == 'B')
			{
				bool RB = true;
			}

			tmpBoardUp = tmpBoardUp->up;
		}

		while ((tmpBoardDown->down)->TYPE != '#')
		{
			if ((tmpBoardDown->down)->BIZ == 'B')
			{
				bool BR = true;
			}

			tmpBoardDown = tmpBoardDown->down;
		}

		board_R->BIZ = 0;
		board_B->BIZ = 0;

		if (RB)
		{
			(board_R->U_end)->BIZ = 'R';
			((board_R->U_end)->left)->BIZ = 'B';
		}
		else if (BR)
		{
			(board_R->U_end)->BIZ = 'B';
			((board_R->U_end)->left)->BIZ = 'R';
		}
		else
		{
			(board_R->U_end)->BIZ = 'R';
			(board_B->U_end)->BIZ = 'B';
		}
	}
	else if (direction == 'd')
	{
		board_R->BIZ = 0;
		(board_R->D_end)->BIZ = 'R';
	}
	else if (direction == 'r')
	{
		bool RB{ false };
		bool BR{ false };
		boardObject* tmpBoardRight = board_R;
		boardObject* tmpBoardLeft = board_R;

		while ((tmpBoardRight->right)->TYPE != '#')
		{
			if ((tmpBoardRight->right)->BIZ == 'B')
			{
				bool RB = true;
			}

			tmpBoardRight = tmpBoardRight->right;
		}

		while ((tmpBoardLeft->left)->TYPE != '#' && !RB)
		{
			if ((tmpBoardLeft->left)->BIZ == 'B')
			{
				bool BR = true;
			}

			tmpBoardRight = tmpBoardLeft->left;
		}

		board_R->BIZ = 0;
		board_B->BIZ = 0;

		if (RB)
		{
			(board_R->R_end)->BIZ = 'B';
			((board_R->R_end)->left)->BIZ = 'R';
		}
		else if (BR)
		{
			(board_R->R_end)->BIZ = 'R';
			((board_R->R_end)->left)->BIZ = 'B';
		}
		else
		{
			(board_R->R_end)->BIZ = 'R';
			(board_B->R_end)->BIZ = 'B';
		}
	}
	else if (direction == 'l')
	{
		bool RB{ false };
		bool BR{ false };
		boardObject* tmpBoardRight = board_R;
		boardObject* tmpBoardLeft = board_R;

		while ((tmpBoardRight->right)->TYPE != '#')
		{
			if ((tmpBoardRight->right)->BIZ == 'B')
			{
				bool RB = true;
			}

			tmpBoardRight = tmpBoardRight->right;
		}

		while ((tmpBoardLeft->left)->TYPE != '#' && !RB)
		{
			if ((tmpBoardLeft->left)->BIZ == 'B')
			{
				bool BR = true;
			}

			tmpBoardRight = tmpBoardLeft->left;
		}

		board_R->BIZ = 0;
		board_B->BIZ = 0;

		if (RB)
		{
			(board_R->L_end)->BIZ = 'R';
			((board_R->L_end)->left)->BIZ = 'B';
		}
		else if (BR)
		{
			(board_R->L_end)->BIZ = 'B';
			((board_R->L_end)->left)->BIZ = 'R';
		}
		else
		{
			(board_R->L_end)->BIZ = 'R';
			(board_B->L_end)->BIZ = 'B';
		}
	}
}

int main()
{
	int BOARD_WIDTH{ 0 }, BOARD_HEIGHT{ 0 };
	cin >> BOARD_HEIGHT >> BOARD_WIDTH;

	boardObject* Goal;

	/***** SETTING START *****/

	// 2ND Dimension Array Dynamic Allocation
	boardObject** board = new boardObject * [BOARD_WIDTH];
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		board[i] = new boardObject[BOARD_HEIGHT];
	}

	// Setting Current
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			char board_tmp;
			cin >> board_tmp;
			
			// set type '.' when the input is R or B, and indicates the existence of a biz. 
			if (board_tmp != 'R' && board_tmp != 'B')
			{
				board[j][i].TYPE = board_tmp;
				board[j][i].BIZ = 0;

				if (board_tmp == 'O')
					Goal = &(board[j][i]);
			}
			else
			{
				board[j][i].TYPE = '.';
				board[j][i].BIZ = board_tmp;
			}

			board[j][i].x = j;
			board[j][i].y = i;
		}

	// Setting the Relevants
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			// LEFT
			if (j != 0)
			{
				board[j][i].left = &board[j - 1][i];
			}

			// RIGHT
			if (j <= (BOARD_WIDTH - 1) - 1)
			{
				board[j][i].right = &board[j + 1][i];
			}

			// UP
			if (i != 0)
			{
				board[j][i].up = &board[j][i - 1];
			}

			// DOWN
			if (i <= (BOARD_HEIGHT - 1) - 1)
			{
				board[j][i].down = &board[j][i + 1];
			}
		}

	// Setting the Ends
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			// LEFT
			if (j != 0)
			{
				board[j][i].U_end = searchEnd(&board[j][i], 'l');
			}

			// RIGHT
			if (j != BOARD_WIDTH - 1)
			{
				board[j][i].right = searchEnd(&board[j][i], 'r');
			}

			// UP
			if (i != 0)
			{
				board[j][i].up = searchEnd(&board[j][i], 'u');
			}

			// DOWN
			if (i != BOARD_HEIGHT - 1)
			{
				board[j][i].down = searchEnd(&board[j][i], 'd');
			}
		}

	/***** SETTING END *****/

	/***** SOLUTION STARTS *****/

	int cnt{ 0 };

	while (cnt <= 10 || Goal->BIZ != 'R')
	{


		cnt++;
	}

	/***** SOLUTION ENDS *****/

	return 0;
}
