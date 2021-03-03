//주사위굴리기
#include <iostream>
using namespace std;

int n,m,x,y,k, cmd, tmp;
int board[25][25];
int dice[7], curE=0, curN=0, bottom=0;

int curX=0,curY=0;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
void roll(int cmd)
{
	int nx = curX + dx[cmd];
	int ny = curY + dy[cmd];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
	//현재 바닥과 현재 동쪽, 현재 북쪽을 기준으로 주사위 굴리기, 현재 북쪽 그대로
	//동쪽 이동하면 현재 동쪽 -> 바닥, 현재 동쪽 -> 현재 바닥의 반대 (현재 위)
	//서쪽 이동하면 현재 동쪽의 반대편 -> 바닥, 현재 동쪽 -> 바닥
	//북쪽 이동하면 이외 pair 중 작/큰 -> 바닥, 현재 동쪽 -> 그대로
	//남쪽 이동하면 이외 pair 중 작/큰 -> 바닥, 현재 동쪽 -> 그대로
	switch(cmd){
		case 1: //동쪽
			tmp = bottom;
			bottom = curE;
			curE = 7-tmp;
			break;
		case 2: //서
			tmp = bottom;
			bottom = 7-curE;
			curE = tmp;
			break;
		case 3: //북
			tmp = bottom; 
			bottom = curN;
			curN = 7-tmp;
			break;
		case 4: //남
			tmp = bottom;
			bottom = 7-curN;
			curN = tmp;
			break;
	}
	if (board[nx][ny] == 0) board[nx][ny] = dice[bottom];
	else {
		dice[bottom] = board[nx][ny];
		board[nx][ny] = 0; 
	}
	printf("%d\n", dice[7-bottom]);
	curX = nx;
	curY = ny;
}
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &board[i][j]);
		}
	}
	bottom = 6;
	curE = 3;
	curN = 2;
	curX = x;
	curY = y;
	for (int i=0;i<k;i++) {
		scanf("%d", &cmd);
		roll(cmd);
	}
	return 0;
}