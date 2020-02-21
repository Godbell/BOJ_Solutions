#include <iostream>
#define ONE_HOUR 60

using namespace std;

int main()
{
	int H{ 0 };
	int M{ 0 };
	int early{ 45 };

	cin >> H >> M;

	if (H > 0)
	{
		if (M < early)
		{
			H--;
			M = ONE_HOUR - (early - M);
		}
		else
			M -= early;
	}
	else
	{
		if (M < early)
		{
			H = 23;
			M = ONE_HOUR - (early - M);
		}
		else
			M -= early;
	}

	cout << H << " " << M << endl;

	return 0;
}

