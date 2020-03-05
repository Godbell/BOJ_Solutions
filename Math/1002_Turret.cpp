#include <iostream>
#include <cmath>

using namespace std;

int distance(int x1, int y1, int x2, int y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int T{0};

    cin >> T;
    while (T-- > 0)
    {
        int x1{0}, y1{0}, r1{0};
        int x2{0}, y2{0}, r2{0};
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        int rSQR{ (r1 + r2) * (r1 + r2) };
        int d{ distance(x1, y1, x2, y2) };

        if (x1 == x2 && y1 == y2) // 동심원
        {
            if (r1 == r2) // 합동
            {
                cout << -1 << endl;
            }
            else // 서로 다른 동심원
            {
                cout << 0 << endl;
            }
        }
        else if (rSQR > d)
        {
            if ((r1 - r2) * (r1 - r2) == d) // 내접
            {
                cout << 1 << endl;
            }
            else if ((r1 - r2) * (r1 - r2) > d) // 포함
            {
                cout << 0 << endl;
            }
            else // 서로 다른 교점 2개
            {
                cout << 2 << endl;
            }
        }
        else if (rSQR == d) // 외접
        {
            cout << 1 << endl;
        }
        else if (rSQR < d) // 밖에서 만나지 않을 때
        {
            cout << 0 << endl;
        }
    }

    return 0;
}