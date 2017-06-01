/* Amit Bansal - @amitbansal7 */
// Representing a Graph
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
// Breadth first Search in O(V+E)

void BFS(vector <int>adj[],int s,int v)
{
	bool visited[v];
	Mset(visited,0);
	queue <int> Q;
	visited[s] = 1;
	Q.push(s);

	while(!Q.empty())
	{
		int u = Q.front();
		printf("%d ",u);
		Q.pop();

		vector <int> ::iterator it;
		for(it = adj[u].begin();it != adj[u].end();it++)
			if(!visited[*it])
			{
				visited[*it] = 1;
				Q.push(*it);
			}
	}

}

void addEdge(vector <int > adj[],int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int main(int argc, char const *argv[])
{
	int v = 5;

	vector<int > adj[v];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);

	BFS(adj,0,v);

	return 0;
}