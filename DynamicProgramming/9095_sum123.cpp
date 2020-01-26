#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 11> dp;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i = 4; i < dp.size(); i++)
	{
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	
	/* implementation */
	int T{0}, index{0};
	cin >> T;
	
	while(T-- > 0)
	{
		cin >> index;
		cout << dp[index] << endl;
	}
	return 0;
}