#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N{ 0 };
    vector<string> words;
    int numberOfGroupWord{ 0 };
    
    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        string userInput;
        cin >> userInput;

        words.push_back(userInput);
    }
    
    for(int testCases{0} ; testCases < N ; testCases++)
    {
        string currentString{ words[testCases] };
        bool isGroupWord{true};

        vector<char> groups;
        char curChecking{'#'};

        for(int i = 0 ; i < currentString.size() ; i++)
        {
            for(int j = 0 ; j < groups.size() ; j++)
            {
                if (currentString[i] == groups[j] && currentString[i] != curChecking)
                {
                    isGroupWord = false;
                    break;
                }
            }

            groups.push_back(currentString[i]);
            curChecking = currentString[i];
        }

        if (isGroupWord)
                numberOfGroupWord++;
    }

    cout << numberOfGroupWord;

    return (0);
}