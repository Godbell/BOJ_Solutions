#include <iostream>
#include <vector>

using namespace std;

int FindMinInt(vector<int> &arr)
{
    for(int i = 0 ; i < arr.size(); i++)
    {
        if ( arr[i] != -1 )
            return arr[i];
    }

    return -1;
}

int main()
{
    vector<int> sleve;

    int N{0}, K{0};
    int erased{0};
    cin >> N >> K;

    for(int i = 2 ; i <= N ; i++)
        sleve.push_back(i);

    while (FindMinInt(sleve) != -1)
    {
        int P{ FindMinInt(sleve) };
        for(int i = 0 ; i < sleve.size(); i++)
        {
            if( sleve[i] % P == 0 && sleve[i] != -1)
            {
                erased++;
                if (erased == K)
                {
                    cout << sleve[i];
                    return (0);
                }
                sleve[i] = -1;
            }
        }
    }

    return (0);
}