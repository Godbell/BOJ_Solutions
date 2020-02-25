#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N{ 0 };
    cin >> N;

    int primeFactor{2};

    while (N != 1)
    {
        bool isFactorPrime{ true };
        for(int i = primeFactor ; i <= sqrt(primeFactor) ; i++)
        {
            if (primeFactor % i == 0)
            {
                isFactorPrime = false;
            }
        }
        
        while (isFactorPrime && N % primeFactor == 0)
        {
            N /= primeFactor;
            cout << primeFactor << endl;
        }

        primeFactor++;
    }

    return (0);
}