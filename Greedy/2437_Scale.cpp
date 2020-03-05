#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int N{ 0 };
    cin >> N;

    vector<int> weights;
    int max{0};

    for(int i = 0 ; i < N ; i++)
    {
        int userInput{ 0 };
        cin >> userInput;

        weights.push_back(userInput);
        max += userInput;
    }

    vector<int> *greedy = new vector<int> [1 + max];

    for(int i = 0 ; i < weights.size() ; i++)
    {
        vector<int> tmp_weights = weights;
        greedy[tmp_weights[i]] = tmp_weights;
        greedy[tmp_weights[i]].erase( greedy[tmp_weights[i]].begin() + i);
    }

    //

    int index{ 1 };
    while (greedy[index].size() != 0)
    {
        for(int i = 0 ; i < greedy[index].size() ; i++)
        {
            if (index + greedy[index][i] <= max)
            {
                vector<int> tmp_weights = greedy[index];
                greedy[index + greedy[index][i]] = tmp_weights;
                greedy[index + greedy[index][i]].erase( greedy[index + greedy[index][i]].begin() + i);
            }
        }
        index++;
    }

    cout << index;
    return (0);
}