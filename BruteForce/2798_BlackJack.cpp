// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N{ 0 };
	int M{ 0 };
	cin >> N >> M;

	int* cards = new int[N];
	
	int* permut = new int[N];

	for (int i = 0; i < N; i++)
	{
		if (i == N -1 ||
			i == N -2 ||
			i == N -3)
			permut[i] = 1;
		else
			permut[i] = 0;

		cin >> cards[i];
	}

	int sum{ 0 };
	do
	{
		int sumTmp{ 0 };
		for (int i = 0; i < N; i++)
		{
			if (permut[i] == 1)
				sumTmp += cards[i];
		}

		if (sumTmp <= M)
		{
			if (sum < sumTmp)
			{
				sum = sumTmp;
				sumTmp = 0;
			}
			else
			{
				sumTmp = 0;
			}
		}
		else
		{
			sumTmp = 0;
		}
	} 
	while (next_permutation(permut, permut + N));

	cout << sum << "\n";

	return 0;
}
