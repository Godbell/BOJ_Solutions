#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class PlanSys
{
public:
	int x;
	int y;
	int r;
	int depth;
	enum class State { NOT_SEARCHING, NOT_VISITED, VISITED };
	State nodeState;
	vector<PlanSys*> adjacents;

	PlanSys(int x_, int y_, int r_)
	{
		x = x_;
		y = y_;
		r = r_;
		depth = 0;
		nodeState = State::NOT_SEARCHING;
	}
};

class graph
{
public:
	vector<PlanSys*> nodes;
	int answer;
	PlanSys* departure;
	PlanSys* arrival;

	graph()
	{
		answer = 0;
		AddSys(new PlanSys(0,0,9999999));
	}

	void AddSys(PlanSys* psys)
	{
		nodes.push_back(psys);
	}

	void AddLink(PlanSys* a, PlanSys* b)
	{
		if (a == NULL || b == NULL)
		{
			return;
		}

		a->adjacents.push_back(b);
		b->adjacents.push_back(a);
	}

	PlanSys* FindMinSys(PlanSys* psys)
	{
		PlanSys* minP = NULL;

		for (PlanSys* p : nodes)
		{
			double d = distance(psys, p);
			if (d < static_cast<double>(p->r) && (minP == NULL || p->r < minP->r))
			{
				minP = p;
			}
		}

		return minP;
	}

	void Start_BFS()
	{
		for (PlanSys* p : nodes)
		{
			p->nodeState = PlanSys::State::NOT_VISITED;
		}

		BFS(departure);

		for (PlanSys* p : nodes)
		{
			p->nodeState = PlanSys::State::NOT_SEARCHING;
		}
	}

	void BFS(PlanSys* psys)
	{
		queue<PlanSys*> psysQ;

		psysQ.push(psys);

		while (psysQ.front() != arrival)
		{
			psysQ.front()->nodeState = PlanSys::State::VISITED;

			for (PlanSys* p : psysQ.front()->adjacents)
			{
				if (p->nodeState != PlanSys::State::VISITED
					&& p->nodeState != PlanSys::State::NOT_SEARCHING)
				{
					p->depth = psysQ.front()->depth + 1;
					psysQ.push(p);
				}
			}

			psysQ.pop();
		}

		answer = psysQ.front()->depth;
	}

	double distance(PlanSys* a, PlanSys* b)
	{
		return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	}
};

int main()
{
	int T;
	cin >> T;

	for (int iter = 0; iter < T; iter++)
	{
		graph* g = new graph();
		
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			g->AddSys(new PlanSys(cx, cy, r));
		}

		g->departure = g->FindMinSys(new PlanSys(x1, y1, 0));
		g->arrival = g->FindMinSys(new PlanSys(x2, y2, 0));
		
		for (int i = 1 ; i < g->nodes.size() ; i++)
		{
			g->AddLink(g->nodes[i], g->FindMinSys(g->nodes[i]));
		}
		g->Start_BFS();
		
		cout << g->answer << endl;
	}

	return 0;
}