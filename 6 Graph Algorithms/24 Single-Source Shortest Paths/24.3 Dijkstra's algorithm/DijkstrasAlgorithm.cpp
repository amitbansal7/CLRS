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

void printpath(int parent[],int v)
{
	if(parent[v] != NIL)
		printpath(parent,parent[v]);

	printf("%d ",v);

}
void Dijkstras(vector<pair<int,int> >adj[],int v,int src)
{
	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > >pq;

	int parent[v];
	int dist[v];

	for(int i=0;i<v;i++)
	{
		parent[i] = NIL;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;
	pq.push(make_pair(dist[src],src));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		vector<pair<int,int> >::iterator it;
		for(it = adj[u].begin();it!= adj[u].end();it++)
		{
			int v = (*it).first;
			int w = (*it).second;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.push(make_pair(dist[v],v));
			}
		}
	}

	printf("Vertex   distance from  %d      Path\n",src);
	for(int i=0;i<v;i++)
	{
		printf("%d \t\t%d \t\t",i,dist[i]);
		printpath(parent,i);
		printf("\n");
	}
}

int main()
{
	int v = 5;
	vector<pair<int,int> > adj[v];

	//Figure 24.2 in CLRS
	adj[0].push_back(make_pair(1,3));
	adj[0].push_back(make_pair(3,5));
	adj[1].push_back(make_pair(2,6));
	adj[1].push_back(make_pair(3,2));
	adj[2].push_back(make_pair(4,2));
	adj[3].push_back(make_pair(1,1));
	adj[3].push_back(make_pair(2,4));
	adj[3].push_back(make_pair(4,6));
	adj[4].push_back(make_pair(0,3));
	adj[4].push_back(make_pair(2,7));

	Dijkstras(adj,v,0);


}
