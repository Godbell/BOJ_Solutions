#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Construction
{
public:
	int number;
	int etime;
	int cumultime;
	int entrance_degree;
	vector<Construction*> parents;
	vector<Construction*> children;
	enum class NodeState { NOT_SEARCHING, NOT_VISITED, VISITED };
	NodeState nodeState;

	Construction(int number, int etime)
	{
		this->number = number;
		this->etime = etime;
		this->cumultime = 0;
		this->entrance_degree = 0;
		this->nodeState = NodeState::NOT_SEARCHING;
	}

	void SetCumulTime()
	{
		cumultime = etime;

		if (parents.size() > 0)
		{
			int maxCumulTime = 0;
			for (Construction* parent : parents)
			{
				if (parent->cumultime > maxCumulTime)
				{
					maxCumulTime = parent->cumultime;
				}
			}

			cumultime += maxCumulTime;
		}
	}

	int parentSize()
	{
		return entrance_degree;
	}
};

class Tree
{
public:
	vector<Construction*> nodes;
	int arrival;
	int answer;

	Tree()
	{
		this->arrival = 0;
		this->answer = 0;
	}

	void AddConstruction(Construction* vertex)
	{
		nodes.push_back(vertex);
	}

	void AddLink(int parent, int child)
	{
		Construction* A = FindConstruction(parent);
		Construction* B = FindConstruction(child);

		if (A == NULL || B == NULL) return;

		A->children.push_back(B);
		B->parents.push_back(A);
		B->entrance_degree++;
	}

	Construction* FindConstruction(int number)
	{
		for (Construction* node : nodes)
		{
			if (node->number == number)
			{
				return node;
			}
		}

		return NULL;
	}

	void SetArrival(int arrival)
	{
		this->arrival = arrival;
	}

	void StartBFS()
	{
		for (Construction* node : nodes)
		{
			node->nodeState = Construction::NodeState::NOT_VISITED;
		}

		answer =	Topological_Sort();

		for (Construction* node : nodes)
		{
			node->nodeState = Construction::NodeState::NOT_SEARCHING;
		}
	}

	int Topological_Sort()
	{
		Construction* current = NULL;

		do
		{
			for (Construction* node : nodes)
			{
				if (node->nodeState == Construction::NodeState::NOT_VISITED && node->entrance_degree == 0)
				{
					current = node;
				}
			}

			//

			if (current == NULL) return -1;
			else
			{
				current->nodeState = Construction::NodeState::VISITED;
				current->SetCumulTime();
				for (Construction* node : current->children)
				{
					node->entrance_degree--;
				}
			}
		}	while (current->number != arrival);

		return current->cumultime;
	}
};

int main() 
{
	int T = 0;
	cin >> T;

	for (int iter = 0; iter < T; iter++)
	{
		Tree* tree = new Tree();

		int N, K;
		cin >> N >> K;

		for (int i = 0; i < N; i++)
		{
			int etime;
			cin >> etime;
			
			tree->AddConstruction(new Construction(i + 1, etime));
		}

		for (int i = 0; i < K; i++)
		{
			int s, d;
			cin >> s >> d;

			tree->AddLink(s, d);
		}

		int arrival;
		cin >> arrival;

		tree->SetArrival(arrival);
		tree->StartBFS();
	
		cout << tree->answer << endl;
	}

	return 0;
}