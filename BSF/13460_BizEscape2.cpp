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

set TiltBoard_UP(char **board, set bizSet)
{
	if(bizSet.RED.y <= bizSet.BLUE.y)
	{
		while (FindEnd(board, bizSet.RED, bizSet.BLUE, "UP").y < bizSet.RED.y)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.y)--;
		}
		while (FindEnd(board, bizSet.BLUE, bizSet.RED, "UP").y < bizSet.BLUE.y)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.y)--;
		}
	}
	else if(bizSet.RED.y > bizSet.BLUE.y)
	{
		while (FindEnd(board, bizSet.BLUE, bizSet.RED, "UP").y < bizSet.BLUE.y)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.y)--;
		}
		while (FindEnd(board, bizSet.RED, bizSet.BLUE, "UP").y < bizSet.RED.y)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.y)--;
		}
	}
	return bizSet;	
}

set TiltBoard_DOWN(char **board, set bizSet)
{
	if(bizSet.RED.y <= bizSet.BLUE.y)
	{
		while (bizSet.BLUE.y < FindEnd(board, bizSet.BLUE, bizSet.RED, "DOWN").y)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.y)++;
		}
		while (bizSet.RED.y < FindEnd(board, bizSet.RED, bizSet.BLUE, "DOWN").y)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.y)++;
		}
	}
	else if(bizSet.RED.y > bizSet.BLUE.y)
	{
		while (bizSet.RED.y < FindEnd(board, bizSet.RED, bizSet.BLUE, "DOWN").y)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.y)++;
		}
		while (bizSet.BLUE.y < FindEnd(board, bizSet.BLUE, bizSet.RED, "DOWN").y)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.y)++;
		}
	}
	return bizSet;
}

set TiltBoard_LEFT(char **board, set bizSet)
{
	if(bizSet.RED.x <= bizSet.BLUE.x)
	{
		while (FindEnd(board, bizSet.RED, bizSet.BLUE, "LEFT").x < bizSet.RED.x)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.x)--;
		}
		while (FindEnd(board, bizSet.BLUE, bizSet.RED, "LEFT").x < bizSet.BLUE.x)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.x)--;
		}
	}
	else if(bizSet.RED.x > bizSet.BLUE.x)
	{
		while (FindEnd(board, bizSet.BLUE, bizSet.RED, "LEFT").x < bizSet.BLUE.x)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.x)--;
		}
		while (FindEnd(board, bizSet.RED, bizSet.BLUE, "LEFT").x < bizSet.RED.x)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.x)--;
		}
	}
	return bizSet;
}

set TiltBoard_RIGHT(char **board, set bizSet)
{
	if(bizSet.RED.x <= bizSet.BLUE.x)
	{
		while (bizSet.BLUE.x < FindEnd(board, bizSet.BLUE, bizSet.RED, "RIGHT").x)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.x)++;
		}
		while (bizSet.RED.x < FindEnd(board, bizSet.RED, bizSet.BLUE, "RIGHT").x)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.x)++;
		}
	}
	else if(bizSet.RED.x > bizSet.BLUE.x)
	{
		while (bizSet.RED.x < FindEnd(board, bizSet.RED, bizSet.BLUE, "RIGHT").x)
		{
			if(board[bizSet.RED.x][bizSet.RED.y] == 'O')
			{
				bizSet.redIn = true;
				break;
			}
			(bizSet.RED.x)++;
		}
		while (bizSet.BLUE.x < FindEnd(board, bizSet.BLUE, bizSet.RED, "RIGHT").x)
		{
			if(board[bizSet.BLUE.x][bizSet.BLUE.y] == 'O')
			{
				bizSet.blueIn = true;
				break;
			}
			(bizSet.BLUE.x)++;
		}
	}
	return bizSet;
}

set TiltBoard(char **board, set bizSet, string direction)
{
	set board_after;

	if(direction == "UP")
	{
		return TiltBoard_UP(board, bizSet);
	}
	else if(direction == "DOWN")
	{
		return TiltBoard_DOWN(board, bizSet);
	}
	else if(direction == "LEFT")
	{
		return TiltBoard_LEFT(board, bizSet);
	}
	else if(direction == "RIGHT")
	{
		return TiltBoard_RIGHT(board, bizSet);
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
	
	for (int x = 0 ; x < height ; x++)
		for (int y = 0 ; y < height ; y++)
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
	while(true)
	{
		bool outerBreak = false;
		depth++;
		for(int i = 0 ; i < 4 ; i++)
		{
			dfs.push_back(TiltBoard(board, dfs[0], directions[i]));
			
			if(dfs[dfs.size() - 1].redIn && !(dfs[dfs.size() - 1].blueIn))
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