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
boardObject& searchEnd(boardObject& board, char direction) 
{
	switch (direction)
	{
		if (board.TYPE == '#')
		{
			boardObject invalidBoard;
			return invalidBoard;
		}

		boardObject End = board;

	case 'u':
		while ((End.up)->TYPE != '#')
		{
			End = *(End.up);
		}
		return End;

	case 'd':
		while ((End.down)->TYPE != '#')
		{
			End = *(End.down);
		}
		return End;

	case 'r':
		while ((End.right)->TYPE != '#')
		{
			End = *(End.right);
		}
		return End;

	case 'l':
		while ((End.left)->TYPE != '#')
		{
			End = *(End.left);
		}
		return End;
	}
}

int main()
{
	int BOARD_WIDTH{ 0 }, BOARD_HEIGHT{ 0 };
	cin >> BOARD_HEIGHT >> BOARD_WIDTH;

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
				board[j][i].BIZ = NULL;
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
				*(board[j][i].left) = board[j-1][i];
			}

			// RIGHT
			if (j != BOARD_WIDTH - 1)
			{
				*(board[j][i].right) = board[j + 1][i];
			}

			// UP
			if (i != 0)
			{
				*(board[j][i].up) = board[j][i - 1];
			}

			// DOWN
			if (i != BOARD_HEIGHT - 1)
			{
				*(board[j][i].down) = board[j][i + 1];
			}
		}

	// Setting the Ends
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			// LEFT
			if (j != 0)
			{
				*(board[j][i].U_end) = searchEnd(board[j][i], 'l');
			}

			// RIGHT
			if (j != BOARD_WIDTH - 1)
			{
				*(board[j][i].right) = searchEnd(board[j][i], 'r');
			}

			// UP
			if (i != 0)
			{
				*(board[j][i].up) = searchEnd(board[j][i], 'u');
			}

			// DOWN
			if (i != BOARD_HEIGHT - 1)
			{
				*(board[j][i].down) = searchEnd(board[j][i], 'd');
			}
		}

	/***** SETTING END *****/

	/***** SOLUTION STARTS *****/



	/***** SOLUTION ENDS *****/

	return 0;
}