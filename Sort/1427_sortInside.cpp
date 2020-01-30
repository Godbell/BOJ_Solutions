#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct rule
{
	bool operator()(int a, int b) const
	{
		return (a > b);
	}	
};

int main()
{
	int	input_number{0};
	vector<int> number;
	
	cin >> input_number;
	while (input_number > 0)
	{
		number.push_back(input_number % 10);
		input_number /= 10;
	}
	
	sort(number.begin(), number.end(), rule());
	
	for (int i = 0 ; i < number.size(); i++)
	{
		cout << number[i];
	}
	
	return (0);
}

