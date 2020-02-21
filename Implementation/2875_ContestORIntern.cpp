	// ConsoleApplication1.cpp : Defines the entry point for the console application.
	//

	#include <iostream>

	using namespace std;

	int main()
	{
		int N{ 0 }, M{ 0 }, K{ 0 };
		cin >> M >> N >> K;

		/*
		8 2 4

		7 2 
		
		*/

		while (K > 0)
		{
			if (M / 2 + M % 2 > N)
			{
				--M;
				--K;
			}
			else if (M / 2 + M % 2 < N)
			{
				--N;
				--K;
			}
			else
			{
				if (K >= 2)
				{
					K -= 2;
					--M;
					--N;
				}
				else
				{
					--K;
					--M;
				}
			}
		}

		int teamCNT{ 0 };
		while (M >= 2 && N >= 1)
		{
			++teamCNT;
			M -= 2;
			N -= 1;
		}

		cout << teamCNT;

		return 0;
	}

