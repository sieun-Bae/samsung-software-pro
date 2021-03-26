#include <iostream>
#include <vector>
using namespace std;

int n;
int map[500][500];
int cur_x, cur_y;
int dx[9] = {-1,-1,-1,-2,0,1,1,1,2};
int dy[9] = {0,-1,-2,-1,-3,0,-1,-2,-1};
int perc[9] = {1,7,10,2,5,1,7,10,2};
int answer=0;

void move()
{
	//printf("\nmove\n");
	
	//무조건 왼쪽으로
	int nxt_x = cur_x;
	int nxt_y = cur_y-1;
	//printf("cur_x: %d, cur_y: %d\n", cur_x, cur_y);
	//printf("nxt_x: %d, nxt_y: %d\n", nxt_x, nxt_y);
	int y = map[nxt_x][nxt_y];
	int x = map[cur_x][cur_y];
	int tmp=0;
	//printf("y: %d x: %d\n", y, x);
	for (int i=0;i<9;i++) {
		int fx = cur_x+dx[i];
		int fy = cur_y+dy[i];
		tmp += y*perc[i]/100;
		if (1<=fx && fx<=n && 1<=fy && fy<=n) {
			map[fx][fy] += y*perc[i]/100;
		} else {
			answer += y*perc[i]/100;
		}
	}
	
	//alpha 자리
	int ax = cur_x;
	int ay = cur_y-2;
	if (1<=ax && ax<=n && 1<=ay && ay<=n) {
		map[ax][ay] += (y-tmp);
	} else {
		answer += (y-tmp);
	}
	map[nxt_x][nxt_y] = x;
	map[cur_x][cur_y] = 0;
	
	cur_x = nxt_x;
	cur_y = nxt_y;
}

void rotate()
{	
	int tmp[n+1][n+1];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			tmp[i][j] = map[n-j+1][i];
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			map[i][j] = tmp[i][j];
		}
	}
	int mid = n/2 + 1;
	int diff = mid - cur_x;
	cur_x = cur_y;
	cur_y = mid + diff;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	cur_x = n/2+1;
	cur_y = n/2+1;
	//printf("x: %d, y: %d", cur_x, cur_y);
	for (int i=1;i<=n;i++) {
		if (i==n) {
			for (int k=0;k<i-1;k++) 
				move();
		} else {
			for (int j=0;j<2;j++) {
				for (int k=0;k<i;k++)
					move();
				rotate();
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}