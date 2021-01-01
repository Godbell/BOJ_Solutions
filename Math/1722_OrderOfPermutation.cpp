#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<__int16> factorial;

int main()
{
	int N, P;
	cin >> N >> P;

	// question 1

	if (P == 1)
	{
		int index;
		cin >> index;

		vector<__int16> answer;

		factorial.push_back(1);
		factorial.push_back(1);
		for (int i = 2; i <= N; i++)
		{
			factorial.push_back(factorial[i - 1] * i);
		}

		for (int i = 1; i <= N; i++)
		{
			if (i < N)
			{
				answer.push_back(
					(static_cast<__int16>(index) / factorial[N - i]) + 1
				);
			}
			else
			{
				int notIncluded = 0;
				for (int targetNumber = 1; targetNumber <= N; targetNumber++)
				{
					bool isIncluded = false;
					for (int index = 1; index <= N; index++)
					{
						if (answer[index] == targetNumber)
						{
							bool isIncluded = true;
							break;
						}
					}

					if (isIncluded == true) continue;
					else
					{
						notIncluded = targetNumber;
						break;
					}
				}
			
				answer.push_back(notIncluded);
			}
		}

		for(__int16 digit : answer)
		{
			cout << digit << " ";
		}

		cout << endl;
	}

	// question 2

	else if (P == 2)
	{
		int answer = 0;
		vector<__int16> number;
		
		number.push_back(0);
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			number.push_back(n);
		}

		factorial.push_back(1);
		factorial.push_back(1);
		for (int i = 2; i <= N; i++)
		{
			factorial.push_back(factorial[i - 1] * i);
		}

		//

		for (int i = 1; i <= N; i++)
		{
			answer += factorial[N - i] * abs(static_cast<__int16>(i) - number[i]);
		}

		if (answer == 0) answer = 1;

		cout << answer;
	}

	return 0;
}