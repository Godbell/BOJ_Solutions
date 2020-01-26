#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int min_value(vector<int>);

int main()
{
	int n{0}, k{0};
	cin >> n >> k;
	vector<int> coin_value;
	array<int, 10000 + 1> dp;
	
	for(int i = 0 ; i < dp.size() ; i++)
	{
		dp[i] = 0;
	}
	for(int i = 0 ; i < n ; i++)
	{
		int input_value{0};
		cin >> input_value;
		coin_value.push_back(input_value);
	}
	sort(coin_value.begin(), coin_value.end());
	dp[coin_value[0]] = 1;
	
	for(int i = 1 ; i <= k; i++)
	{
		for(int j = coin_value.size() - 1 ; j >= 0 ; j--)
		{
			if(i > coin_value[j])
			{
				dp[i] += dp[i - coin_value[j]];
			}
		}
	}
	
	for(int i = 0 ; i <= k ; i++)
		cout << "dp[" << i << "]: " << dp[i] << endl;
	
	cout << "dp[k]: " << dp[k] << endl;
	
	return 0;
}