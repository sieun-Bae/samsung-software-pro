//bellman-ford, 최단경로, <0, 1:1
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef struct Info{
	int b;
	ll c;
	Info(int bb, int cc){
		b = bb;
		c = cc;
	}
}Info;

int n,m;
ll dist[510];
vector<Info> adj[510];
bool hasCycle = false;

void bell()
{
	dist[1] = 0;
	for (int i=0;i<n;i++) { //v-1번
		for (int j=1;j<=n;j++) { //e개의 간선 모두 확인
			for (int k=0;k<adj[j].size();k++) {
				Info nxt = adj[j][k];
				if (dist[j]!=INF && j!=nxt.b && dist[j] + nxt.c < dist[nxt.b]) {
					if (i==(n-1)) hasCycle = true;
					dist[nxt.b] = dist[j] + nxt.c;
				}
			}
		}
	}

}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<m;i++) {
		int a,b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		adj[a].push_back(Info(b, c));
	}
	for (int i=1;i<=n;i++) dist[i] = INF;
	hasCycle = false;
	bell();

	if (hasCycle) printf("-1\n");
	else {
		for (int i=2;i<=n;i++) {
			if (dist[i] == INF) printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}
	return 0;
}