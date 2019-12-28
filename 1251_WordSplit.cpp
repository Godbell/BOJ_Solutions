#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> primary(vector<char>, vector<char>);

int main()
{
	string i_word;
	cin >> i_word;
	int WORD_LENGTH = i_word.length();
	int SPLIT_WAYS = 3;

	vector<char> word;
	vector<int> permut_word;

	for(int i = 0 ; i < WORD_LENGTH ; i++)
	{
		word.push_back(i_word[i]);
		
		if(i < SPLIT_WAYS)
			permut_word.push_back(1);
		else
			permut_word.push_back(0);
	}

	vector<char> prime;
	while(next_permutation(permut_word.begin(), permut_word.end()))
	{
		vector<char> l_tmp;
		for(int i = 0 ; i < WORD_LENGTH ; i++)
		{
			if(permut_word[i] == 1)
			{
				l_tmp.push_back(word[i]);
				prime = primary(prime, l_tmp);
				l_tmp.clear();
			}
			else
			{
				l_tmp.push_back(word[i]);
			}
			
		}
	}

	for(int i = 0 ; i < prime.size() ; i++)
	{
		cout << prime[i];
	}

	return 0;
}

vector<char> primary(vector<char> p_wordA, vector<char> p_wordB)
{
	int f_iteration = p_wordA.size() <= p_wordB.size() ? p_wordA.size() : p_wordB.size();
	
	for(int i = 0 ; i < f_iteration ; i++)
	{
		if(p_wordA[i] > p_wordB[i])
		{
			return p_wordA;
		}
		else if(p_wordA[i] < p_wordB[i])
		{
			return p_wordB;
		}
	}

	return p_wordA;
}