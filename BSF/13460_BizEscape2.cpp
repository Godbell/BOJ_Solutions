#include <iostream>
#include <vector>
#include <string>

using namespace std;

string directions[] = {"UP", "DOWN", "LEFT", "RIGHT"};

struct position
{
	int x;
	int y;
};

struct set
{
	position RED;
	position BLUE;
	bool redIn;
	bool blueIn;
};

position FindEnd(char **board, position biz, position other, string direction)
{
	int cur_biz_x = biz.x;
	int cur_biz_y = biz.y;
	position end;

	if(direction == "UP")
	{
		while(board[cur_biz_x][cur_biz_y] == '.')
		{
			if(board[cur_biz_x][cur_biz_y - 1] == '#'
				|| ((cur_biz_y - 1 == other.y) && cur_biz_x == other.x))
			{
				end.x = cur_biz_x;
				end.y = cur_biz_y;
				return end;
			}
			--cur_biz_y;
		}
	}
	else if(direction == "DOWN")
	{
		while(board[cur_biz_x][cur_biz_y] == '.')
		{
			if(board[cur_biz_x][cur_biz_y + 1] == '#'
				|| ((cur_biz_y + 1 == other.y) && cur_biz_x == other.x))
			{
				end.x = cur_biz_x;
				end.y = cur_biz_y;
				return end;
			}
			++cur_biz_y;
		}
	}
	else if(direction == "LEFT")
	{
		while(board[cur_biz_x][cur_biz_y] == '.')
		{
			if(board[cur_biz_x - 1][cur_biz_y] == '#'
				|| ((cur_biz_x - 1 == other.x) && cur_biz_y == other.y))
			{
				end.x = cur_biz_x;
				end.y = cur_biz_y;
				return end;
			}
			--cur_biz_x;
		}
	}
	else if(direction == "RIGHT")
	{
		while(board[cur_biz_x][cur_biz_y] == '.')
		{
			if(board[cur_biz_x + 1][cur_biz_y] == '#'
				|| ((cur_biz_x + 1 == other.x) && cur_biz_y == other.y))
			{
				end.x = cur_biz_x;
				end.y = cur_biz_y;
				return end;
			}
			++cur_biz_x;
		}
	}
}

set TiltBoard_UP(char **board, position r, position b, string direction)
{
	set board_after;
	if(r.y <= b.y)
	{
		while (FindEnd(board, r, b, "UP").y < r.y)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.y)--;
		}
		while (FindEnd(board, b, r, "UP").y < b.y)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.y)--;
		}
	}
	else if(r.y > b.y)
	{
		while (FindEnd(board, b, r, "UP").y < b.y)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.y)--;
		}
		while (FindEnd(board, r, b, "UP").y < r.y)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.y)--;
		}
	}
	board_after.RED = r;
	board_after.BLUE = b;
	return board_after;	
}

set TiltBoard_DOWN(char **board, position r, position b, string direction)
{
	set board_after;
	if(r.y <= b.y)
	{
		while (b.y < FindEnd(board, b, r, "DOWN").y)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.y)++;
		}
		while (r.y < FindEnd(board, r, b, "DOWN").y)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.y)++;
		}
	}
	else if(r.y > b.y)
	{
		while (r.y < FindEnd(board, r, b, "DOWN").y)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.y)++;
		}
		while (b.y < FindEnd(board, b, r, "DOWN").y)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.y)++;
		}
	}
	board_after.RED = r;
	board_after.BLUE = b;
	return board_after;
}

set TiltBoard_LEFT(char **board, position r, position b, string direction)
{
	set board_after;
	if(r.x <= b.x)
	{
		while (FindEnd(board, r, b, "LEFT").x < r.x)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.x)--;
		}
		while (FindEnd(board, b, r, "LEFT").x < b.x)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.x)--;
		}
	}
	else if(r.x > b.x)
	{
		while (FindEnd(board, b, r, "LEFT").x < b.x)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.x)--;
		}
		while (FindEnd(board, r, b, "LEFT").x < r.x)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.x)--;
		}
	}
	board_after.RED = r;
	board_after.BLUE = b;
	return board_after;
}

set TiltBoard_RIGHT(char **board, position r, position b, string direction)
{
	set board_after;
	if(r.x <= b.x)
	{
		while (b.x < FindEnd(board, b, r, "RIGHT").x)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.x)++;
		}
		while (r.x < FindEnd(board, r, b, "DOWN").x)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.x)++;
		}
	}
	else if(r.x > b.x)
	{
		while (r.x < FindEnd(board, r, b, "DOWN").x)
		{
			if(board[r.x][r.y] == 'O')
			{
				board_after.redIn = true;
				break;
			}
			(r.x)++;
		}
		while (b.x < FindEnd(board, b, r, "DOWN").x)
		{
			if(board[b.x][b.y] == 'O')
			{
				board_after.blueIn = true;
				break;
			}
			(b.x)++;
		}
	}
	board_after.RED = r;
	board_after.BLUE = b;
	return board_after;
}

set TiltBoard(char **board, position r, position b, string direction)
{
	set board_after;

	if(direction == "UP")
	{
		return TiltBoard_UP(board, r, b, "UP");
	}
	else if(direction == "DOWN")
	{
		return TiltBoard_DOWN(board, r, b, "DOWN");
	}
	else if(direction == "LEFT")
	{
		return TiltBoard_LEFT(board, r, b, "LEFT");
	}
	else if(direction == "RIGHT")
	{
		return TiltBoard_LEFT(board, r, b, "RIGHT");
	}
}

int main()
{
	int width{0}, height{0};
	cin >> height >> width;
	set BIZ_SET;
	BIZ_SET.blueIn = false;
	BIZ_SET.redIn = false;

	char **board = new char*[width];
	for (int i = 0 ; i < width ; i++)
		board[i] = new char[height];
	
	for (int y = 0 ; y < height ; y++)
		for (int x = 0 ; x < width ; x++)
		{
			cin >> board[x][y];
			if(board[x][y] == 'R')
			{
				BIZ_SET.RED.x = x;
				BIZ_SET.RED.y = y;
				board[x][y] = '.';
			}
			else if(board[x][y] == 'B')
			{
				BIZ_SET.BLUE.x = x;
				BIZ_SET.BLUE.y = y;
				board[x][y] = '.';
			}
		}

	vector<set> dfs;
	int depth = 0;
	dfs.push_back(BIZ_SET);
	while(depth < 10)
	{
		bool outerBreak = false;
		depth++;
		for(int i = 0 ; i < 4 ; i++)
		{
			dfs.push_back(TiltBoard(board, dfs[0].RED, dfs[0].BLUE, directions[i]));
			if(dfs[dfs.size() - 1].redIn && !dfs[dfs.size() - 1].blueIn)
			{
				outerBreak = true;
				break;
			}
		}
		if(outerBreak) break;
		dfs.erase(dfs.begin());
	}

	if(depth <= 10)
		cout << depth;
	else
		cout << -1;
	
	return 0;
}