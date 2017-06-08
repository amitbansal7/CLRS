/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#include <string>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
#define INF 0x3f3f3f3f
#define TC int testcase; S(testcase); while(testcase--)
#define Pi 3.14159
using namespace std;

// Single source shortest paths in directed acyclic graphs

void DFS(vector <pair<int,int> >adj[],int src,int visited[],stack<int>&S)
{
	visited[src] = 1;
	vector <pair<int,int > >::iterator it;
	for(it = adj[src].begin();it != adj[src].end();it++)
		if(!visited[(*it).first])
			DFS(adj,(*it).first,visited,S);

	S.push(src);
}

void topologicalSorting(vector<pair<int,int> >adj[],int src,int v,stack<int>&S)
{
	int visited[v];
	Mset(visited,0);

	for(int i=0;i<v;i++)
		if(!visited[i])
			DFS(adj,i,visited,S);
}

void SSSPDAG(vector<pair<int,int> > adj[],int src,int v)
{
	stack <int>S;
	topologicalSorting(adj,src,v,S);

	int dist[v];
	int parent[v];

	for(int i=0;i<v;i++)
	{
		parent[v] = NIL;
		dist[v] = INT_MAX;
	}
	dist[src] = 0;

	while(!S.empty())
	{
		int u = S.top();
		S.pop();
		vector <pair<int,int> > ::iterator it;
		for(it = adj[u].begin();it != adj[u].end();it++)
		{
			int v = (*it).first;
			int w = (*it).second;

			if(dist[u]!=INT_MAX && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
			}
		}
	}

	for(int i=0;i<v;i++)
	{
		printf("For %d\n",i);
		printf("Parent is %d\n",parent[i]);
		printf("Distance from %d is %d\n",src,dist[i]);
		printf("\n");
	}
}

int main()
{
	int v = 6;
	vector<pair<int,int> >adj[v];

	adj[0].push_back(make_pair(2,3));
	adj[0].push_back(make_pair(1,5));
	adj[1].push_back(make_pair(3,6));
	adj[1].push_back(make_pair(2,2));
	adj[2].push_back(make_pair(4,4));
	adj[2].push_back(make_pair(3,7));
	adj[2].push_back(make_pair(5,2));
	adj[3].push_back(make_pair(4,-1));
	adj[3].push_back(make_pair(5,1));
	adj[4].push_back(make_pair(5,-2));

	SSSPDAG(adj,0,v);
}
