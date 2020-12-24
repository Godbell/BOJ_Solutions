#include <iostream>
#include <cmath>

using namespace std;

int SquareMod(int x, int n, int m)
{
    if (n == 1)
    {
        return x % m;
    }
    else
    {
        return (SquareMod(x, n - 1, m) * SquareMod(x, 1, m)) % m;
    }
}

int main()
{
    cout << SquareMod(5, 3, 7) << endl;

    return 0;
}

