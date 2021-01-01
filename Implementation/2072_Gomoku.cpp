#include <iostream>
#include <vector>

using namespace std;

class Stone
{
public:
	enum class StoneType {EMPTY = -1, WHITE = 2, BLACK = 3};

	StoneType currentState;
	int x;
	int y;

	Stone(int x, int y)
	{
		this->x = x;
		this->y = y;
		currentState = StoneType::EMPTY;
	}
};

class Board
{
public:
	enum class Dir{ RIGHT = 1,  LEFT = -1, UP = 1, DOWN = -1, NEUTRAL = 0};

	int width;
	int height;
	vector<vector<Stone*>> board;

	Board()
	{
		width = 19;
		height = 19;

		board.resize(width);
		for (int i = 0; i < width; i++)
		{
			board[i].resize(height);
		}

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				board[i][j] = new Stone(i, j);
			}
		}
	}

	bool CheckStoneArrNum(Stone* stone)
	{
		Stone::StoneType stoneType = stone->currentState;
		int inARow = 0;
		int maxInARow = 0;

		// 1. check down-up
		for (int i = 0; i < height; i++)
		{
			if (board[stone->x][i]->currentState == stoneType)
			{
				inARow++;
				if (inARow > maxInARow) maxInARow = inARow;
			}
			else
			{
				inARow = 0;
			}
		}

		if (maxInARow == 5) return true;
		inARow = 0;
		maxInARow = 0;

		// 2. check leftup-rightdown ( y = -x + n => n = x + y)
		int x = 0;
		int y = stone->x + stone->y;
		while (0 <= x && x < width && 0 <= y  && y < height)
		{
			if (board[x][y]->currentState == stoneType)
			{
				inARow++;
				if (inARow > maxInARow) maxInARow = inARow;
			}
			else
			{
				inARow = 0;
			}

			x += 1;
			y += -1;
		}

		if (maxInARow == 5) return true;
		inARow = 0;
		maxInARow = 0;

		// 3. check left-right
		for (int i = 0; i < width; i++)
		{
			if (board[i][stone->y]->currentState == stoneType)
			{
				inARow++;
				if (inARow > maxInARow) maxInARow = inARow;
			}
			else
			{
				inARow = 0;
			}
		}

		if (maxInARow == 5) return true;
		inARow = 0;
		maxInARow = 0;

		// 4. check leftdown-leftup

		if (stone->x > stone->y)
		{
			x = stone->x - stone->y;
			y = 0;
		}
		else if (stone->x < stone->y)
		{
			x = 0;
			y = stone->y - stone->x;
		}
		else
		{
			x = 0;
			y = 0;
		}

		while (0 <= x && x < width && 0 <= y && y < height)
		{
			if (board[x][y]->currentState == stoneType)
			{
				inARow++;
				if (inARow > maxInARow) maxInARow = inARow;
			}
			else
			{
				inARow = 0;
			}
			x += 1;
			y += 1;
		}

		if (maxInARow == 5) return true;
		inARow = 0;
		maxInARow = 0;

		// nothing fulfilled;

		return false;
	}
};

int main()
{
	int N;
	cin >> N;

	Board* board = new Board();
	bool isGameEnded = false;

	for (int i = 1; i < N + 1; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if (isGameEnded == true) continue;

		if (i % 2 == 0)
		{
			board->board[x -1][y -1]->currentState = Stone::StoneType::WHITE;
		}
		else
		{
			board->board[x -1][y -1]->currentState = Stone::StoneType::BLACK;
		}

		if (board->CheckStoneArrNum( board->board[x -1][y - 1] ))
		{
			cout << i << endl;
			isGameEnded = true;
		}
	}

	if (isGameEnded == false)
	{
		cout << -1 << endl;
	}

	return 0;
}