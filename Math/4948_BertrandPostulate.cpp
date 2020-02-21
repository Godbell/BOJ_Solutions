#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool primeOrNot(int);
int countHowMany(int, int);

int main()
{
    vector<int> input_numbers;

    int tmp_input;

    cin >> tmp_input;
    while (tmp_input != 0)
    {
        input_numbers.push_back(tmp_input);
        cin >> tmp_input;
    }
    for(int i = 0 ; i < input_numbers.size(); i++)
    {
        cout << countHowMany(input_numbers[i] * 2, input_numbers[i]) << endl;
    }

    return (0);
}

int countHowMany(int num, int begin)
{
    int cnt{0};

    for(int i = begin + 1 ; i <= num ; i++)
    {
        if(primeOrNot(i))
            ++cnt;
    }

    return (cnt);
}

bool primeOrNot(int num)
{
    bool result{true};

    for(int i = 2 ; i <= sqrt(num) ; i++)
    {
        if (num % i == 0)
        {
            result = false;
            return (result);
        }
    }

    return (result);
}