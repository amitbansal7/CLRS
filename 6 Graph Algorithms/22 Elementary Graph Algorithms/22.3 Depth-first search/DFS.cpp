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
//Depth First Search in O(V + E)

void DFS(vector <int>adj[],int s,int visited[])
{
	visited[s] = 1;
	printf("%d ",s);
	vector<int> ::iterator it;
	for(it = adj[s].begin();it != adj[s].end();it++)
		if(!visited[*it])
			DFS(adj,*it,visited);
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
	
	int visited[v];
	Mset(visited,0);
	DFS(adj,0,visited);
	return 0;
}