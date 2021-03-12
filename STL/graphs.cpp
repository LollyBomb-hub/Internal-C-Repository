#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define	GE		graph_edge
#define V		vector
#define Q		queue
#define min(x,y)	x > y ? y : x

typedef struct
{
	int self, dest, cost;
} graph_edge;

V<int> color;
V<int> time_in, time_out;
int dfs_timer = 0;

V<int> search_best_way(V<GE> edges, int count, int max_value, int from)
{
	// Bellman - Ford algorithm
	max_value++;
	V<int> d(count, max_value);
	d[from] = 0;
	for(;;)
	{
		bool any = false;
		for(int j = 0; j < edges.size(); ++j)
		{
			if(d[edges[j].self] < max_value)
			{
				if (d[edges[j].dest] > d[edges[j].self] + edges[j].cost)
				{
					d[edges[j].dest] = min(d[edges[j].dest], d[edges[j].self] + edges[j].cost);
					any = true;
				}
			}
		}
		if(!any) break;
	}
	return d;
}

V<int> wide_search(V<V<int>> graph, int s)
{
	int n = graph.size();
	Q<int> q;
	q.push(s);
	V<bool> used(n);
	V<int> d(n), p(n);
	used[s] = true;
	p[s] = -1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(size_t i = 0; i < graph[v].size(); i++)
		{
			int to = graph[v][i];
			if(!used[to])
			{
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
	return p;
}

void depth_search(V<V<int>> graph, int v)
{
	time_in[v] = dfs_timer++;
	color[v] = 1;
	for(V<int>::iterator i = graph[v].begin(); i != graph[v].end(); ++i)
		if(color[*i] == 0)
			depth_search(graph, *i);
	color[v] = 2;
	time_out[v] = dfs_timer++;
	return;
}

int main(void)
{
	return 0;
}
