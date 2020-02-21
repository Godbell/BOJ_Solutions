// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <array>
#include <algorithm>
#define NUMBER_OF_HOBBITS 9

using namespace std;

int rule(int a, int b)
{
	return a ? b : a < b;
}

int sum(array<int, NUMBER_OF_HOBBITS> arr)
{
	int result{ 0 };
	for (int i = 0; i < NUMBER_OF_HOBBITS; i++)
		result += arr[i];

	return result;
}

int main()
{
	array<int, NUMBER_OF_HOBBITS> hobbits;
	array<int, NUMBER_OF_HOBBITS> Npermut = { 0,0,0,0,0,0,0,1,1 };

	for (int i = 0; i < NUMBER_OF_HOBBITS; i++)
	{
		cin >> hobbits[i];
	}

	sort(hobbits.begin(), hobbits.end());
	int doubt{sum(hobbits) - 100};

	do
	{
		int s{ 0 };

		for (int i = 0; i < NUMBER_OF_HOBBITS; i++)
		{
		
			if (Npermut[i] == 1)
			{
				s += hobbits[i];
			}
		}

		if (s == doubt)
		{
			for (int k = 0; k < NUMBER_OF_HOBBITS; k++)
			{
				if (Npermut[k] == 1)
				{
					hobbits[k] = 0;
				}
			}

			for (int k = 0; k < NUMBER_OF_HOBBITS; k++)
			{
				if (hobbits[k] != 0)
					cout << hobbits[k] << "\n";
			}
			return 0;
		}
		else
			continue;

	} 
	while (next_permutation(Npermut.begin(), Npermut.end()));

	return 0;
}

