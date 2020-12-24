#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct gs
{
    // attributes
    int location{-1};   // a
    int fillAmount{-1}; // b
    int fuelLeft{1};
    int depth{0};
    int City{-1};
};

struct 
{
    bool operator() (gs a, gs b) const
    {
        return (a.fillAmount > b.fillAmount);
    }
} rules;

int main()
{
    int N{0};
    cin >> N;

    vector<gs> gsList;

    for (int i = 0 ; i < N ; i++)
    {
        int a{0}, b{0}; 
        cin >> a >> b;
        gs input{a, b, 0, 0};

        gsList.push_back(input);
    }

    int L{0}, P{0};
    cin >> L >> P;

    gs city{L, -1, -1, 0, 1};
    gsList.push_back(city);

    //

    vector<gs> TREE;
    gs current{0, P, 0, 0};
    TREE.push_back(current);

    int treecnt{0};
    vector<gs> lastcanGoto;
    while (current.City != 1)
    {
        vector<gs> canGoto;
        for (int i = 0 ; i < gsList.size() ; i++)
        {
            gs tmp = gsList[i];
            int distance = tmp.location - current.location;

            if (tmp.location > current.location
                && distance <= current.fuelLeft + current.fillAmount)
            {
                tmp.depth = current.depth + 1;
                tmp.fuelLeft = current.fuelLeft + current.fillAmount - distance;
                canGoto.push_back(tmp);
            }
        }

        if (canGoto.size() == 0)
        {
            lastcanGoto.erase(lastcanGoto.begin());
            continue;
        }
        else
        {
            lastcanGoto = canGoto;
        }
        
        sort(canGoto.begin(), canGoto.end(), rules);
        TREE.push_back(canGoto[0]);

        if (current.City != 1 && current.depth > N)
        {
            cout << -1;
            return 0;
        }

        treecnt++;
        current = TREE[treecnt];
        
    }

    cout << current.depth - 1;

    //
    
    return 0;
}