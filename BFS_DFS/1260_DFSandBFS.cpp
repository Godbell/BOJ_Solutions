#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct NODE
{
    int number{0};
    vector<NODE*> connectedWith;
};

struct 
{
    bool operator() (NODE* a, NODE* b)
    {
        bool result = (a->number) < (b->number);
        return result;
    }
}   rules;

NODE DepthFisrt(NODE node, int depth)
{

}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    vector<NODE> nodes;

    NODE empty{-1};
    nodes.push_back(empty);

    for (int i = 1 ; i <= N ; i++)
    {
        NODE node{i};
        nodes.push_back(node);
    }

    for (int i = 0 ; i < M ; i++)
    {
        int inputNum, inputLink;
        cin >> inputNum >> inputLink;

        nodes[inputNum].connectedWith.push_back(&nodes[inputLink]);
        nodes[inputLink].connectedWith.push_back(&nodes[inputNum]);
    }

    for (int i = 1 ; i <= N ; i++)
    {
        sort(nodes[i].connectedWith.begin(), nodes[i].connectedWith.end(), rules);
    }

    // dfs

    // bfs
    queue<NODE> BFS;
    vector<NODE> visited;

    BFS.push(nodes[V]);
    visited.push_back(nodes[V]);

    while (visited.size() < nodes.size())
    {
        for (int i = 0 ; i < BFS.front().connectedWith.size() ; i++)
        {
            bool alreadyVisited{false};
            // 이미 가봤는지 검사
            for (int j = 0 ; j < visited.size() ; j++)
            {
                if (visited[j].number == BFS.front().connectedWith[i]->number)
                {
                    visited.push_back(*(BFS.front().connectedWith[i]));
                    alreadyVisited = true;
                    break;
                }
            }
            if (!alreadyVisited)
            {
                visited.push_back(*(BFS.front().connectedWith[i]));
                BFS.push(*BFS.front().connectedWith[i]);
            }
        }

        if (BFS.size() > 0)
            BFS.pop();
    }

    for (int i = 0 ; i < visited.size() ; i++)
    {
        cout << visited[i].number << " ";
    }

    return 0;
}