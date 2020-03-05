#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 1 + 40> memo_0;
    array<int, 1 + 40> memo_1;

    for(int i = 0 ; i < 1 + 40 ; i++)
    {
        memo_0[i] = 0;
        memo_1[i] = 0;
    }
    
    memo_0[0] = 1;
    memo_0[1] = 0;
    memo_0[2] = 1;

    memo_1[0] = 0;
    memo_1[1] = 1;
    memo_1[2] = 1;

    for(int i = 3 ; i < 1 + 40 ; ++i)
    {
        memo_0[i] = memo_0[i-1] + memo_0[i-2];
        memo_1[i] = memo_1[i-1] + memo_1[i-2];
    }

    //

    int T{0};
    cin >> T;

    int inputIndex{0};
    while (T-- > 0)
    {
        cin >> inputIndex;
        cout << memo_0[inputIndex] << " " << memo_1[inputIndex] << endl;
    }

    return 0;
}