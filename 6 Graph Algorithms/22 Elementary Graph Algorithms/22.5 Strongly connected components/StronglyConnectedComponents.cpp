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
//Strongly conected components in O(V+E)

void DFS(vector <int>adj[],int visited[],int s,stack<int>&S,int f)
{
	visited[s] = 1;
	//Printing s for 2nd DFS
	if(!f) printf("%d ",s);
	vector <int>::iterator it;
	for(it = adj[s].begin();it != adj[s].end();it++)
		if(!visited[*it])
			DFS(adj,visited,*it,S,f);

	if(f)//Pushing into stack for 1st DFS
		S.push(s);
}

void SCC(vector <int>adj[],int v)
{
	int visited[v];
	Mset(visited,0);
	stack <int>S;

	for(int i=0;i<v;i++)
		if(!visited[i])
			DFS(adj,visited,i,S,1);

	Mset(visited,0);

	vector <int>adjT[v];
	// Transpose
	vector <int>::iterator it;
	for(int i=0;i<v;i++)
		for(it = adj[i].begin();it != adj[i].end();it++)
			adjT[*it].push_back(i);

	Mset(visited,0);
	while(!S.empty())
	{
		int v = S.top();
		S.pop();

		if(!visited[v])
		{
			//Stack is not used in this DFS
			DFS(adjT,visited,v,S,0);
			printf("\n");
		}
	}
}

int main(int argc, char const *argv[])
{
	int v = 8;

	vector <int> adj[v];

	adj[0].push_back(1);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[1].push_back(2);
	adj[2].push_back(6);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(7);
	adj[4].push_back(0);
	adj[4].push_back(5);
	adj[5].push_back(6);
	adj[6].push_back(5);
	adj[6].push_back(7);
	adj[7].push_back(7);

	SCC(adj,v);
	/*
	output:
	0 4 1
	2 3
	5 6
	7
	*/

	return 0;
}
