    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    void SP1(int Asize, int k, vector<int>& dfs, int depth, int& last_breadth);
    void SP2(int Asize, vector<int> ks, vector<int>& dfs, int depth, int& last_breadth);
    bool repetition(vector<int>& dfs);

    int main()
    {
        int N{0};
        cin >> N;

        int nbrOfSP{0};
        cin >> nbrOfSP;

        vector<int> dfs;
        for(int i = 0 ; i < N ; i++)
        {
            dfs.push_back(0);
        }

        if(nbrOfSP == 1)
        {
            int K{0};
            cin >> K;

            int last_b{1};
            SP1(N, K, dfs, 0, last_b);

            for(int i = 0 ; i < dfs.size() ; i++)
            {
                cout << dfs[i] << " ";
            }
        }
        else
        {
            vector<int> Ks;
            for(int i = 0 ; i < N ; i++)
            {
                int input{0};
                cin >> input;

                Ks.push_back(input);
                
            }

            int last_b{1};
            SP2(N, Ks, dfs, 0, last_b);
            cout << last_b;
        }

        return 0;
    }

    void SP1(int Asize, int k, vector<int>& dfs, int depth, int& last_breadth)
    {
        if (depth == 0)
        {
            dfs[depth]++;
            
            SP1(Asize, k, dfs, depth + 1, last_breadth);
        }
        else if (depth > 0 && depth < Asize)
        {        
            dfs[depth]++;
            while (repetition(dfs))
            {
                dfs[depth] ++;
            }
            if (dfs[depth] > Asize)
            {
                dfs[depth] = 0;
                SP1(Asize, k, dfs, depth - 1, last_breadth);
            }
            else
                SP1(Asize, k, dfs, depth + 1, last_breadth);
        }
        else if (depth >= Asize)
        {
            dfs[depth]++;

            while (repetition(dfs))
            {
                dfs[depth]++;
            }
            if (last_breadth < k)
            {
                dfs[depth] = 0;
                last_breadth++;
                SP1(Asize, k, dfs, depth - 1, last_breadth);
            }
        }
    }

    void SP2(int Asize, vector<int> ks, vector<int>& dfs, int depth, int& last_breadth)
    {
        if (depth == 0)
        {
            dfs[depth]++;
            
            SP2(Asize, ks, dfs, depth + 1, last_breadth);
        }
        else if (depth > 0 && depth < Asize)
        {        
            dfs[depth]++;
            while (repetition(dfs))
            {
                dfs[depth] ++;
            }
            if (dfs[depth] > Asize)
            {
                dfs[depth] = 0;
                SP2(Asize, ks, dfs, depth - 1, last_breadth);
            }
            else
                SP2(Asize, ks, dfs, depth + 1, last_breadth);
        }
        else if (depth >= Asize)
        {
            dfs[depth]++;

            while (repetition(dfs))
            {
                dfs[depth]++;
            }
            if (dfs != ks)
            {
                dfs[depth] = 0;
                last_breadth++;
                SP2(Asize, ks, dfs, depth - 1, last_breadth);
            }
        }
    }

    bool repetition(vector<int>& vect)
    {
        bool isRepeated{false};
        vector<int> table;
        
        for(int i = 0 ; i < vect.size() ; i++)
        {
            for (int j = 0 ; j < table.size() ; j++)
            {
                if (vect[i] == table[j] && vect[i] != 0)
                {
                    isRepeated = true;
                    return isRepeated;
                }
            }

            table.push_back(vect[i]);
        }

        return isRepeated;
    }