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
// Adjacency list representation
int main()
{
	int ver = 5;
	vector <int> V[ver+1];
	V[1].push_back(2);
	V[1].push_back(5);

	V[2].push_back(1);
	V[2].push_back(5);
	V[2].push_back(3);
	V[2].push_back(4);

	V[3].push_back(2);
	V[3].push_back(4);

	V[4].push_back(2);
	V[4].push_back(5);
	V[4].push_back(3);

	V[5].push_back(4);
	V[5].push_back(1);
	V[5].push_back(2);

	vector <int> :: iterator it;

	for(int v=1;v<=5;v++)
	{
		printf("\n %d ->",v);
		for(it = V[v].begin();it != V[v].end();it++)
			printf("%d ",*it);
	}
	printf("\n");
}