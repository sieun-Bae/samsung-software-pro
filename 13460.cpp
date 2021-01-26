//bfs

#include <iostream>
#include <queue>
using namespace std;

//성공: 빨간구슬을 구멍
//실패: 파란구슬 구멍, 빨/파 동시에 구멍
//더이상 구슬 움직일수없을때 그만
//

typedef struct Info{
	int x, y;
	Info() {}
	Info(int xx, int yy) {
		x = xx;
		y = yy;
	}
}Info;

queue<Info> R, B;

int dx = {-1,1,0,0};
int dy = {0,0,-1,1};

int N,M;
int map[10][10];
int visited[10][10];
char buf[15];
Info final;
int count;

void bfs()
{
	//1. 체크아웃

	//2. 목적지인가?
	if (count <= 10 && cur.x == final.x && cur.y == final.y) {
		printf("%d", count);
	}
	if (count > 10) {
		printf("-1\n");
		return;
	}
	//3. 갈 수 있는곳 순회
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			//4. 갈 수 있는가?
			
			//5. 체크인, 간다.(enqueue)
		}
	}
		
		

}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++) {
		scanf("%s", buf);
		for (int j=0;j<M;j++) {
			map[i][j] = buf[j];
			if (map[i][j] == 'B') 
				B.push(Info(i, j));
			else if (map[i][j] == 'R')
				R.push(Info(i, j));
			else if (map[i][j] == '0') {
				final.x = i;
				final.y = j;
			}
		}
	}
	/*
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			printf("%c", map[i][j]);
		}
	}*/

	return 0;
}