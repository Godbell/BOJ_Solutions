/* 백준 온라인 저지 2863번: 이게 분수? */

#include <iostream>
#include <array>

using namespace std;

void turnTable(array<array<int,2>,2>&);
template<class T>
void SWAP(T& p_valueA, T& p_valueB)
{
	T f_tmp = p_valueA;
	p_valueA = p_valueB;
	p_valueB = f_tmp;
}

int main()
{
    array<array<double,2>,2> table;

    //i : 열, j : 행
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            cin >> table[i][j];
    
    array<double,4> record;
    for(int i = 0 ; i < record.size() ; i++)
    {
        record[i] = table[0][0] / table[1][0] + table[0][1] / table[1][1];
    }

    int minRec{0};
    int minRot{0};

    for(int i = 0 ; i < record.size() ; i++)
    {
        if(record[i] < minRot)
        {
            minRec = record[i];
            minRot = i;
            break;
        }
    }

    cout << minRot;

    return 0;
}

void turnTable(array<array<double,2>,2>& p_table)
{
    SWAP<double>(p_table[0][1], p_table[1][1]);
    SWAP<double>(p_table[0][0], p_table[0][1]);
    SWAP<double>(p_table[0][0], p_table[1][0]);
}