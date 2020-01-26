/*백준 온라인 저지 1699번*/

#include <iostream>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

int minimunOne(vector<int> p_vector)
{
    int f_minimum = p_vector[0];
    for(int i = 1 ; i < p_vector.size() ; i++)
    {
        if(f_minimum > p_vector[i])
            f_minimum = p_vector[i];
    }

    return f_minimum;
}



int main()
{
    int N{0};
    cin >> N;

    int* dp = new int [1 + N];
    vector<int> squareNums;

    dp[0] = 0;
    int tmp{1};
    while(tmp * tmp <= N)
    {
        squareNums.push_back(tmp * tmp);
        ++tmp;
    }

    for(int i = 0 ; i < squareNums.size() ; ++i)
    {
        dp[squareNums[i]] = 1;

        if(squareNums[i] + 1 <= N)
            dp[squareNums[i] + 1] = 2;
    }

    for(int i = 3 ; i <= N ; i++)
    {
        vector<int> l_waysFrom;
        if(dp[i] == 1)
        {
            continue;
        }

        for(int j = 0 ; j < squareNums.size(); ++j)
        {
            int l2_lastIndex = i - squareNums[j];

            if(l2_lastIndex > 0)
            {
                l_waysFrom.push_back(dp[l2_lastIndex]);
            }
            else break;
        }

        dp[i] = minimunOne(l_waysFrom) + 1;
    }

    cout << dp[N];

    return 0;
}