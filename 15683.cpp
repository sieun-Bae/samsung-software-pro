#include <iostream>
#include <vector>
#define MAX 98765
using namespace std;

typedef struct cctv{
	int type;
	int x;
	int y;
	cctv(int tt, int xx, int yy) {
		type = tt;
		x = xx;
		y = yy;
	}
}cctv;

int map[9][9];
int n,m;
int answer = MAX;
int cnt = 0;
vector<cctv> camera;

void move(int dir, int x, int y)
{
	switch(dir)
	{
		case 0: //북
			for (int i=(x-1);i>=0;i--) {
				if (map[i][y] == 6) break;
				if (map[i][y] == 0) map[i][y] = -1;
			}
			break;
		case 1: //동
			for (int i=(y+1);i<m;i++) {
				if (map[x][i] == 6) break;
				if (map[x][i] == 0) map[x][i] = -1;
			}
			break;
		case 2: //남
			for (int i=(x+1);i<n;i++) {
				if (map[i][y] == 6) break;
				if (map[i][y] == 0) map[i][y] = -1;
			}
			break;
		case 3: //서
			for (int i=(y-1);i>=0;i--) {
				if (map[x][i] == 6) break;
				if (map[x][i] == 0) map[x][i] = -1;
			}
			break;
	}
}

void dfs(int step)
{
	//목적지인가?
	if (step == cnt) {
		int tmp=0;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (map[i][j] == 0) {
					tmp++;
				}
			}
		}
		answer = min(answer, tmp);
		return;
	}

	int cctv = camera[step].type;
	int x = camera[step].x;
	int y = camera[step].y;

	//체크인
	int map2[9][9];
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			map2[i][j] = map[i][j];
		}
	}
	//주변 탐색
	switch(cctv) {
		case 1:
			//체크아웃
			for (int dir=0;dir<4;dir++) {
				move(dir, x, y);
				dfs(step+1);
				for (int i=0;i<n;i++) {
					for (int j=0;j<m;j++) {
						map[i][j] = map2[i][j];
					}
				}
			}
			break;
		case 2:
			for (int dir=0;dir<2;dir++) {
				move(dir, x, y);
				move(dir+2, x, y);

				dfs(step+1);
				for (int i=0;i<n;i++) {
					for (int j=0;j<m;j++) {
						map[i][j] = map2[i][j];
					}
				}
			}
			break;
		case 3:
			for (int dir=0;dir<4;dir++) {
				move(dir, x, y);
				move((dir+1)%4, x, y);
				
				dfs(step+1);
				for (int i=0;i<n;i++) {
					for (int j=0;j<m;j++) {
						map[i][j] = map2[i][j];
					}
				}
			}
			break;
		case 4:
			for (int dir=0;dir<4;dir++) {
				move(dir, x, y);
				move((dir+1)%4, x, y);
				move((dir+2)%4, x, y);
				
				dfs(step+1);
				for (int i=0;i<n;i++) {
					for (int j=0;j<m;j++) {
						map[i][j] = map2[i][j];
					}
				}
			}
			break;
		case 5:
			for (int dir=0;dir<4;dir++) {
				move(dir, x, y);
			}
			dfs(step+1);
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					map[i][j] = map2[i][j];
				}
			}
			break;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]!=0 && map[i][j]!=6) { //cctv이면
				camera.push_back(cctv(map[i][j], i, j));
				cnt++;
			}
		}
	}
	dfs(0);
	printf("%d\n", answer);

	return 0;
}