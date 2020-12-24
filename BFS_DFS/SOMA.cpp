#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool Done(vector<int> &array)
{
    int firstOne = array[0];
    for (int i = 0 ; i < array.size() ; i++)
    {
        if (array[i] != firstOne)
            return false;
    }

    return true;
}

void pollute (vector<int> &array, int key, int begin, int end)
{
    if (begin < 0) begin = 0;
    if (end >= array.size()) end = array.size() - 1;

    for (int i = begin ; i <= end ; i++)
    {
        array[i] = key;
    }
}

int main() 
{
	int N{0};
	int K{0};
	cin >> N >> K;
	vector<int> INPUT;
	
	for (int i = 0 ; i < N ; i++)
	{
		int input;
		cin >> input;
		INPUT.push_back(input);
	}


    int result{0};
    int key = INPUT[0];

    int begin{0};
    int end{begin + K - 1};

    while (!Done(INPUT))
    {
        pollute (INPUT, key, begin, end);
        result ++;

        begin += K - 1;
        end += K - 1;
    }
    cout << result;
    return 0;
}