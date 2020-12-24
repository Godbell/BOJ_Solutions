#include <iostream>
#include <vector>

using namespace std;

int maxlower_index(vector<int>* arr, int val)
{
	int begin = 0;
	int end = arr->size() - 1;
	int key = 0;

	while (begin <= end)
	{
		key = arr->at((begin + end) / 2);

		if (arr->at((begin + end) / 2) > val)
		{
			end = (begin + end) / 2 - 1;
		}
		else if (arr->at((begin + end) / 2) < val)
		{
			begin = (begin + end) / 2 + 1;
		}
		else
		{
			break;
		}
	}

	if (begin == 0)
		return begin;
	else return begin - 1;
}

int LIS_Length(vector<int> arr)
{
	int length = arr.size();

	vector<int>* minEnds = new vector<int>(2000);
	for (int i = 0; i < 2000; i++)
	{
		if (i == 0) minEnds->at(i) = 0;
		else minEnds->at(i) = 99999;
	}

	for (int i = 0; i < length; i++)
	{
		int lbi = maxlower_index(minEnds, arr[i]);
		if (minEnds->at(lbi + 1) > arr[i])
		{
			minEnds->at(lbi + 1) = arr[i];
		}
	}

	for (int i = 0; i < 2000; i++)
	{
		if (minEnds->at(i) == 99999)
		{
			return i - 1;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> A;

	for (int i = 0; i < N; i++)
	{
		int a_i;
		cin >> a_i;
		A.push_back(a_i);
	}

	cout << LIS_Length(A) << endl;
}

// 10 20 10 30 10 15 20 25 10 20