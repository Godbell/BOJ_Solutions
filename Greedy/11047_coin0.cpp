#include <iostream>

using namespace std;

int main()
{
	int N{ 0 };
	int K{ 0 };

	cin >> N >> K;
	int* values = new int[N];
	for (int i = 0; i < N; i++)
		cin >> values[i];

	int coinCNT{ 0 };

	for (int i = 0; i < N; i++)
		while (values[(N - 1) - i] <= K)
		{
			K -= values[(N - 1) - i];
			coinCNT++;
		}

	cout << coinCNT << endl;

    return 0;
}

