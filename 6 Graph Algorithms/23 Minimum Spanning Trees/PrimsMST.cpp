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

void addEdge(vector<pair<int,int> >adj[],int src,int dest,int weight)
{
	adj[src].push_back(make_pair(dest,weight));
	adj[dest].push_back(make_pair(src,weight));
}

void PrimMST(vector<pair<int,int> >adj[],int src,int v)
{
	priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;

	vector <int>key(v,INF);
	vector <int>Inmst(v,0);
	vector <int>parent(v,-1);

	key[src] = 0;
	pq.push(make_pair(key[src],src));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		vector<pair<int,int> >::iterator it;
		Inmst[u] = true;
		for(it = adj[u].begin();it != adj[u].end();it++)
		{
			int v = (*it).first;
			int w = (*it).second;

			if(Inmst[v] == false && key[v] > w)
			{
				parent[v] = u;
				key[v] = w;
				pq.push(make_pair(key[v],v));
			}
		}
	}

	for(int i=1;i<v;i++)
		printf("%d - %d\n",parent[i],i);

}

int main()
{
	int v=9;
	vector <pair<int,int> >adj[v];

	addEdge(adj,0, 1, 4);
    addEdge(adj,0, 7, 8);
    addEdge(adj,1, 2, 8);
    addEdge(adj,1, 7, 11);
    addEdge(adj,2, 3, 7);
    addEdge(adj,2, 8, 2);
    addEdge(adj,2, 5, 4);
    addEdge(adj,3, 4, 9);
    addEdge(adj,3, 5, 14);
    addEdge(adj,4, 5, 10);
    addEdge(adj,5, 6, 2);
    addEdge(adj,6, 7, 1);
    addEdge(adj,6, 8, 6);
    addEdge(adj,7, 8, 7);

    PrimMST(adj,0,v);
    return 0;
}
