#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

#define UP 0
#define DOWN 1 
#define LEFT 2 
#define RIGHT 3

using namespace std;

const int x_moveBias[] = {0, 0, -1, 1};
const int y_moveBias[] = {-1, 1, 0, 0};

struct position
{
    int x;
    int y;
};

class Board
{
private:
    //board attributes
    char** board;
    int width;
    int height;
    //biz position
    position blue;
    position red;
    //goal in
    bool blueIn;
    bool redIn;
    //utilities
    position FindEnd(int direction, position STDbiz, position OTHERbiz);
    //tiltboard
    void TiltBoard_UP();
    void TiltBoard_DOWN();
    void TiltBoard_LEFT();
    void TiltBoard_RIGHT();

public:
    Board(int _width, int _height, char** _board);
    ~Board();
    
    void TiltBoard(int direction);
    void PrintBoard() const;

    position getBluePos() const;
    position getRedPos() const;
    void setBluePos(int _x, int _y);
    void setRedPos(int _x, int _y);
    bool isRedIn() const;
    bool isBlueIn() const;
};

int main()
{
    int width{0};
    int height{0};
    char **board;
    cin >> height >> width;

    board = new char* [width];
    for(int i = 0 ; i < width ; i++)
        board[i] = new char [height];

    for (int i = 0 ; i < width ; i++)
    {
        for(int j = 0 ; j < height ; j++)
        {
            cin >> board[i][j];
        }
    }

    Board ROOT_BOARD{width, height, board};

    int depth{0};
    queue<Board> BFS;
    BFS.push(ROOT_BOARD);

    while (depth <= 10)
    {
        depth++;
        for(int i = UP ; i < 4; i++)
        {
            BFS.push(BFS.front());
            BFS.back().TiltBoard(i);
            if (BFS.back().isRedIn() && !(BFS.back().isBlueIn()))
            {
                cout << depth;
                return 0;
            }
        }
        BFS.pop();
    }
    cout << -1;
    return 0;
}

// utility
position Board::FindEnd(int direction, position STDbiz, position OTHERbiz)
{
    int X_BIAS = x_moveBias[direction];
    int Y_BIAS = y_moveBias[direction];
    position end = STDbiz;

    while ((board[end.x + X_BIAS][end.y + Y_BIAS] == '.'
        || board[end.x + X_BIAS][end.y + Y_BIAS] == 'O')
        && !(end.x + X_BIAS == OTHERbiz.x && end.y + Y_BIAS == OTHERbiz.y))
    {
        end.x += X_BIAS;
        end.y += Y_BIAS;
    }
    return end;
}

void Board::TiltBoard_UP()
{
    int direction{UP};
    for(int i = 0 ; i < height ; i++)
    {
        if(red.y == i && !redIn)
        {
            while(red.y < FindEnd(direction, red, blue).y)
            {
                setRedPos(getRedPos().x + x_moveBias[direction], getRedPos().y + y_moveBias[direction]);
                if(board[getRedPos().x][getRedPos().y] == 'O')
                {
                    redIn = true;
                    break;
                }
            }
        }
        if(blue.y == i && !blueIn)
        {
            while(blue.y < FindEnd(direction, blue, red).y)
            {
                setBluePos(getBluePos().x + x_moveBias[direction], getBluePos().y + y_moveBias[direction]);
                if(board[getBluePos().x][getBluePos().y] == 'O')
                {
                    blueIn = true;
                    break;
                }
            }
        }
    }
}

void Board::TiltBoard_DOWN()
{
    int direction{DOWN};
    for(int i = height - 1 ; i > 0 ; i--)
    {
        if(red.y == i && !redIn)
        {
            while(red.y < FindEnd(direction, red, blue).y)
            {
                setRedPos(getRedPos().x + x_moveBias[direction], getRedPos().y + y_moveBias[direction]);
                if(board[getRedPos().x][getRedPos().y] == 'O')
                {
                    redIn = true;
                    break;
                }
            }
        }
        if(blue.y == i && !blueIn)
        {
            while(blue.y < FindEnd(direction, blue, red).y)
            {
                setBluePos(getBluePos().x + x_moveBias[direction], getBluePos().y + y_moveBias[direction]);
                if(board[getBluePos().x][getBluePos().y] == 'O')
                {
                    blueIn = true;
                    break;
                }
            }
        }
    }
}

void Board::TiltBoard_LEFT()
{
    int direction{LEFT};
    for(int i = 0 ; i < width ; i++)
    {
        if(red.y == i && !redIn)
        {
            while(red.x < FindEnd(direction, red, blue).x)
            {
                setRedPos(getRedPos().x + x_moveBias[direction], getRedPos().y + y_moveBias[direction]);
                if(board[getRedPos().x][getRedPos().y] == 'O')
                {
                    redIn = true;
                    break;
                }
            }
        }
        if(blue.y == i && !blueIn)
        {
            while(blue.x < FindEnd(direction, blue, red).x)
            {
                setBluePos(getBluePos().x + x_moveBias[direction], getBluePos().y + y_moveBias[direction]);
                if(board[getBluePos().x][getBluePos().y] == 'O')
                {
                    blueIn = true;
                    break;
                }
            }
        }
    }
}

void Board::TiltBoard_RIGHT()
{
    int direction{RIGHT};
    for(int i = width - 1 ; i > 0 ; i--)
    {
        if(red.y == i && !redIn)
        {
            while(red.x < FindEnd(direction, red, blue).x)
            {
                setRedPos(getRedPos().x + x_moveBias[direction], getRedPos().y + y_moveBias[direction]);
                if(board[getRedPos().x][getRedPos().y] == 'O')
                {
                    redIn = true;
                    break;
                }
            }
        }
        if(blue.y == i && !blueIn)
        {
            while(blue.x < FindEnd(direction, blue, red).x)
            {
                setBluePos(getBluePos().x + x_moveBias[direction], getBluePos().y + y_moveBias[direction]);
                if(board[getBluePos().x][getBluePos().y] == 'O')
                {
                    blueIn = true;
                    break;
                }
            }
        }
    }
}

// public
Board::Board(int _width, int _height, char** _board)
    : width{_width}, height{_height}, blueIn{false}, redIn{false}, board{_board}
{
    for (int i = 0 ; i < _width ; i++)
    {
        for(int j = 0 ; j < _height ; j++)
        {
            if (board[i][j] == 'R')
            {
                setRedPos(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                setBluePos(i, j);
                board[i][j] = '.';
            }
        }
    }
}

Board::~Board()
{
    delete[] board;
}

void Board::TiltBoard(int direction)
{
    if (direction == UP)
    {
        TiltBoard_UP();
    }
    else if (direction == DOWN)
    {
        TiltBoard_DOWN();
    }
    else if (direction == LEFT)
    {
        TiltBoard_LEFT();
    }
    else if (direction == RIGHT)
    {
        TiltBoard_RIGHT();
    }
}

void Board::PrintBoard() const
{
    for(int i = 0; i < width ; i++)
    {
        for(int j = 0 ; j < height ; j++)
        {
            cout << board[i][j];
            if (j == height - 1)
                cout << endl;
        }
    }
    cout << "***" << endl;
}

position Board::getBluePos() const
{
    return blue;
}

position Board::getRedPos() const
{
    return red;
}

void Board::setBluePos(int _x, int _y)
{
    blue.x = _x;
    blue.y = _y;
}

void Board::setRedPos(int _x, int _y)
{
    red.x = _x;
    red.y = _y;
}

bool Board::isBlueIn() const
{
    return blueIn;
}

bool Board::isRedIn() const
{
    return redIn;
}