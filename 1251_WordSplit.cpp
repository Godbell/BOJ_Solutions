#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string word;
	cin >> word;

	int WORD_LENGTH = word.length();
	int* splitPoint = new int [WORD_LENGTH];

	for (int i = 0; i < WORD_LENGTH; i++)
	{
		if (i < 3)
			splitPoint[i] = 1;
		else
			splitPoint[i] = 0;
	}

	while (next_permutation(splitPoint, splitPoint + WORD_LENGTH - 1))
	{
		
	}

	return 0;
}