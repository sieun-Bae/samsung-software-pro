#include <iostream>
#include <cstring>
using namespace std;

int n,q;
int ice=0;
int map[64][64];
int visited[64][64];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y)
{
	visited[x][y] = 1; 
	int tmp_ice = 1;
	for (int i=0;i<4;i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (visited[nx][ny]==0 && 0<=nx && nx<n && 0<=ny && ny<n && map[nx][ny] > 0) {
			tmp_ice += dfs(nx,ny);
		}
	}
	return tmp_ice;
}

void rotatef(int r, int c, int l)
{
	int temp[64][64];
	for (int i=0;i<l;i++) {
		for (int j=0;j<l;j++) {
			temp[i][j] = map[r+l-1-j][c+i];
		}
	} 
	for (int i=0;i<l;i++) {
		for (int j=0;j<l;j++) {
			map[r+i][c+j] = temp[i][j];
		}
	}
}

void rotate(int l)
{
	//printf("rotate..\n");
	l = (1<<l);
	for (int i=0;i<n;i+=l) {
		for (int j=0;j<n;j+=l) {
			rotatef(i,j,l);
		}
	}
}

void melt()
{
	//printf("melt..\n");
	bool chkMelt[64][64];
	memset(chkMelt, false, sizeof(chkMelt));
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (map[i][j]==0) continue;
			int tmp=0;
			for (int d=0;d<4;d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (0<=nx && nx<n && 0<=ny && ny<n && map[nx][ny] > 0) {
					tmp++;
				}
			}
			if (tmp < 3) chkMelt[i][j] = true;
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if(chkMelt[i][j])
				map[i][j]--;
		}
	}
}

int main()
{
	scanf("%d%d", &n,&q);
	n = (1<<n);

	//printf("n: %d\n",n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for (int i=0;i<q;i++) {
		int l=0;
		scanf("%d", &l);
		rotate(l);
		melt();
	}
	/*
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/
	//출력
	int total=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			total += map[i][j];
		}
	}
	printf("%d\n", total);
	
	ice = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (map[i][j] > 0 && visited[i][j] == 0) {
				ice = max(ice, dfs(i,j));
			}
		}
	}
	printf("%d\n", ice);
	return 0;
}