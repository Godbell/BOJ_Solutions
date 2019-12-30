/* 백준 온라인 저지 9506번 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*INPUT*/
    vector<int> Ns;
    int input{0};
    cin >> input;

    while(input != -1)
    {
        Ns.push_back(input);
        cin >> input;
    }
    /*INPUT END*/

    /*DEVIDER GET*/
    for(int i = 0 ; i < Ns.size() ; ++i)
    {
        int n{Ns[i]};
        vector<int> deviders;
        int sum{0};

        for(int l_devider = 1 ; l_devider <= n / 2 ; ++l_devider)
        {
            if(n % l_devider == 0)
            {
                deviders.push_back(l_devider);
                sum += l_devider;
            }
        }

        if(sum == n)
        {
            cout << n << " =";
            for(int j = 0 ; j < deviders.size() - 1 ; j++)
            {
                cout << " " << deviders[j] << " +";
            }
            cout << " " << deviders[deviders.size() - 1] << endl;
        }
        else
        {
            cout << n << " is NOT perfect." << endl;
        }
    }
    /*DEVIDER GET END*/

    return 0;
}