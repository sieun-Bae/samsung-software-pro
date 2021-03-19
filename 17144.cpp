#include <iostream>
using namespace std;

int r, c, t, ans;
int map[55][55];
int machine=0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void mungi()
{
	//완전탐색 -> 기존 map 저장, 새로운 map에 업데이트, 기존 map 새로운 map으로 업데이트
	int tmp[55][55];
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			tmp[i][j] = map[i][j];
		}
	}
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if (tmp[i][j]>0) {
				int cnt=0;
				for (int d=0;d<4;d++) {
					int nx = i+dx[d];
					int ny = j+dy[d];
					if (1<=nx && nx<=r && 1<=ny && ny<=c && (tmp[nx][ny]!=-1)) {
						cnt++;
						map[nx][ny] += (tmp[i][j]/5);
					}
				}
				int k = tmp[i][j]/5;
				map[i][j] -= cnt*k;
			}
		}
	}
}

void gongi()
{
	int rr = machine;
	//좌표 이동
	for (int p=rr;p>1;p--) map[p][1] = map[p-1][1];
	map[rr][1] = -1;
	for (int p=1;p<c;p++) map[1][p] = map[1][p+1];
	for (int p=1;p<rr;p++) map[p][c] = map[p+1][c];
	for (int p=c;p>2;p--) map[rr][p] = map[rr][p-1];
	map[rr][2] = 0;
	rr++;
	
	for (int p=rr;p<r;p++) map[p][1] = map[p+1][1];
	map[rr][1] = -1;
	for (int p=1;p<c;p++) map[r][p] = map[r][p+1];
	for (int p=r;p>rr;p--) map[p][c] = map[p-1][c];
	for (int p=c;p>2;p--) map[rr][p] = map[rr][p-1];
	map[rr][2] = 0;
}

int main()
{
	scanf("%d %d %d", &r,&c,&t);
	machine = -1;
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				if (machine == -1) {
					machine = i;
				}
			}
		}
	}
	for (int time=0;time<t;time++) {
		mungi();
		gongi();
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++) {
			if (map[i][j]>0) ans+=map[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}