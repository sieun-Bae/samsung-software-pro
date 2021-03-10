//로봇청소기, 시뮬레이션, 브루트포스
#include <iostream>
using namespace std;

int n,m,r,c,d; //d: 청소기가 바라보고 있는 방향
int board[55][55]; //1: 벽, 0: 빈 칸, 2: 이미 청소한 곳
//0: 북, 1: 동, 2: 남, 3: 서
int answer=1;
int x,y; //현재 청소기가 있는 좌표
int tx, ty, td; //다음 들여다볼 좌표

void leftf()
{
	if (d == 0) {
		tx = x;
		ty = y-1;
		td = 3;
	} else if (d == 1) {
		tx = (x-1);
		ty = y;
		td = 0;
	} else if (d == 2) {
		tx = x;
		ty = (y+1);
		td = 1;
	} else if (d == 3) {
		tx = x+1;
		ty = y;
		td = 2;
	}
	return;
}
void clean()
{
	int tmp = 0;

	while(true)
	{
		board[x][y] = 2;
		//printf("(%d, %d) dir: %d\n", tx, ty, td);
		
		if (tmp == 4) { //네 방향 모두 청소가 되어있거나 벽인 경우
			//후진
			if (d == 0) { //북
				tx = x+1;
				ty = y;
			} else if (d == 1) { //동
				tx = x;
				ty = y-1;
			} else if (d == 2) { //남
				tx = x-1;
				ty = y;
			} else if (d == 3) { //서
				tx = x;
				ty = y+1;
			}
			//후진 가능한가?
			if (board[tx][ty] == 1) {
				break;
			} else {
				x = tx;
				y = ty;
				tmp = 0;
			}
		}
		leftf();
		if (board[tx][ty] == 0 && tmp <= 3) { //청소할 공간 존재
			x = tx;
			y = ty;
			d = td;
			tmp = 0;
			answer++;
		} else {
			d = td;
			tmp++;
			continue;
		}	

	}
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&r,&c,&d);
	x = r, y = c;
	board[r][c] = 2;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &board[i][j]);
		}
	}
	clean();
	printf("%d\n", answer);
	return 0;
}