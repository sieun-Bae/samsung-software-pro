#include <iostream>
using namespace std;

int n,l,r, ans;
int nation[55][55];
int pr[55][55];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int prCnt[55];

int main()
{
	scanf("%d%d%d",&n,&l,&r);
	int cnt=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d",&nation[i][j]);
			pr[i][j] = cnt;
			cnt++;
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d ",pr[i][j]);
		}
		printf("\n");
	}
	for (int x=0;x<n;x++) {
		for (int y=0;y<n;y++) {
			for (int d=0;d<4;d++) {
				int nx = x+dx[d];
				int ny = y+dy[d];
				if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
				int tmp = abs(nation[x][y] - nation[nx][ny]);
				if (l<= tmp && tmp<=r) {
					pr[nx][ny] = min(pr[x][y], pr[nx][ny]);
				}
			}
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d ",pr[i][j]);
		}
		printf("\n");
	}
	for (int x=0;x<n;x++) {
		for (int y=0;y<n;y++) {
			prCnt[pr[x][y]]++;
		}
	}
	for (int i=0;i<n;i++) {
		if (prCnt[i] >= 2) ans++;
	}
	printf("%d\n", ans);
	return 0;
}