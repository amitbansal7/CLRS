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

string a;
string b;

lli DP[2002][2002];

lli min3(lli i, lli j, lli k)
{ return min(i, min(j, k)); }

lli solve(int i, int j)
{
	if (DP[i][j] != -1)
		return DP[i][j];

	if (i == 0)
		return DP[i][j] = j;

	else if (j == 0)
		return DP[i][j] = i;

	else if (a[i - 1] == b[j - 1])
		return DP[i][j] = solve(i - 1, j - 1);

	else
		return DP[i][j] = 1 + min3(solve(i - 1, j - 1), solve(i - 1, j), solve(i, j - 1));
}

int main()
{

	cin >> a; cin >> b;
	Mset(DP, -1);
	int al = a.length();
	int bl = b.length();
	printf("%lld\n", solve(al, bl));


}
