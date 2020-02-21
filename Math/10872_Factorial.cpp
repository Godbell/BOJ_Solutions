#include <iostream>

using namespace std;

int factorial(int a)
{
	if (a == 0 || a == 1)
	{
		return 1;
	}
	else
	{
		return a * factorial(a - 1);
	}
}

int main()
{
	int N{ 0 };

	cin >> N;
	cout << factorial(N);

	return 0;
}

