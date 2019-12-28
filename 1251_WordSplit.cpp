#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> primary(vector<char>, vector<char>);
void inverseVector(vector<char>&);
template<class T>
void SWAP(T& p_valueA, T& p_valueB)
{
	T f_tmp = p_valueA;
	p_valueA = p_valueB;
	p_valueB = f_tmp;
}

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
		
		if(i > WORD_LENGTH - SPLIT_WAYS - 1)
			permut_word.push_back(1);
		else
			permut_word.push_back(0);
	}

	vector<char> prime = word;
	bool firstRun = true;

	do
	{
		vector<char> l_primeMaybe;
		vector<char> l_tmp;

		for(int i = 0 ; i < WORD_LENGTH ; i++)
		{
			if(permut_word[i] == 0)
			{
				l_tmp.push_back(word[i]);
			}
			else // permut_word[i] == 1
			{
				l_tmp.push_back(word[i]);
				inverseVector(l_tmp);

				for(int j = 0 ; j < l_tmp.size(); j++)
				{
					l_primeMaybe.push_back(l_tmp[j]);			
				}

				l_tmp.clear();
			}
		}

		if(!firstRun)
			prime = primary(prime, l_primeMaybe);
		else
			prime = l_primeMaybe;

		firstRun = false;

	} while(next_permutation(permut_word.begin(), permut_word.end() - 1));

	for(int i = 0 ; i < prime.size() ; i++)
	{	
		cout << prime[i];
	}

	return 0;
}

void inverseVector(vector<char>& p_word)
{
	int f_halfSize = p_word.size() / 2;

	for(int i = 0 ; i < f_halfSize ; i++)
	{
		SWAP<char>(p_word[i], p_word[p_word.size() - 1 - i]);
	}
}

vector<char> primary(vector<char> p_wordA, vector<char> p_wordB)
{
	int f_iteration = p_wordA.size() <= p_wordB.size() ? p_wordA.size() : p_wordB.size();
	
	for(int i = 0 ; i < f_iteration ; i++)
	{
		if(p_wordA[i] > p_wordB[i])
		{
			return p_wordB;
		}
		else if(p_wordA[i] < p_wordB[i])
		{
			return p_wordA;
		}		
	}
	
	if(p_wordA.size() > p_wordB.size())
			{
				return p_wordB;
			}
			else 
				return p_wordA;

	return p_wordA;
}