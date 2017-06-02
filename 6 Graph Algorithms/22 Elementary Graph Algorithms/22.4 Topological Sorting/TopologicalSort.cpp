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
//Topological Sort using depth first search

void DFS(vector <int>adj[],int s,int visited[],stack <int>&S)
{
	visited[s] = 1;
	vector<int> ::iterator it;
	for(it = adj[s].begin();it != adj[s].end();it++)
		if(!visited[*it])
			DFS(adj,*it,visited,S);

	S.push(s);
}

void TopologicalSort(vector <int>adj[],int v)
{
	stack <int> S;
	int visited[v];
	Mset(visited,0);

	for(int i=1;i<v;i++)
		if(!visited[i])
			DFS(adj,i,visited,S);

	while(!S.empty())
	{
		printf("%d ",S.top());
		S.pop();
	}
}

int main(int argc, char const *argv[])
{
	int v = 10;

	vector<int > adj[v];

	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(7);
	adj[6].push_back(8);
	adj[6].push_back(7);
	adj[7].push_back(9);
	adj[8].push_back(9);
	TopologicalSort(adj,v);
	//output - 6 8 5 2 3 7 9 1 4
	return 0;
}