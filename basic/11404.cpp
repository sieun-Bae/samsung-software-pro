//floyd-warshall n:m <0
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, dist[110][110];

void floyd()
{
	for (int j=1;j<=n;j++) {
		for (int i=1;i<=n;i++) {
			for (int k=1;k<=n;k++) {
				if (dist[i][j] == INF || dist[j][k] == INF) continue;
				if (dist[i][j] + dist[j][k] < dist[i][k]) {
					dist[i][k] = dist[i][j] + dist[j][k];
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (i!=j) dist[i][j] = INF;
		}
	}
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		if (c<dist[a][b]) dist[a][b] = c;
	}
	floyd();

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (dist[i][j] == INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}