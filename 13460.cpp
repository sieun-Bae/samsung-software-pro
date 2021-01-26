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

int result=0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int N,M;
int map[11][11];
bool visited[11][11][11][11];
char buf[15];

int bfs()
{
	visited[R.front().x][R.front().y][B.front().x][B.front().y] = true;
	while (!R.empty()) {
		int Rsize = R.size();
		while(Rsize--) {
			//1. 체크아웃
			Info Rcur = R.front();
			R.pop();

			Info Bcur = B.front();
			B.pop();

			//2. 목적지인가?
			if (map[Rcur.x][Rcur.y] == 'O') {
				return result;
			}

			//3. 갈 수 있는곳 순회
			for (int i=0;i<4;i++) {
				//4. 갈 수 있는가?
				int tempR=0, tempB=0;
				Info Rnxt=Rcur, Bnxt=Bcur;
				while (map[Rnxt.x+dx[i]][Rnxt.y+dy[i]] != '#' && map[Rnxt.x][Rnxt.y] != 'O') {
					Rnxt.x += dx[i];
					Rnxt.y += dy[i];
					tempR++;
				}
				while (map[Bnxt.x+dx[i]][Bnxt.y+dy[i]] != '#' && map[Bnxt.x][Bnxt.y] != 'O') {
					Bnxt.x += dx[i];
					Bnxt.y += dy[i];
					tempB++;
				}
				//겹치면 
				if (Rnxt.x == Bnxt.x && Rnxt.y == Bnxt.y) {
					if (map[Rnxt.x][Rnxt.y] == 'O') continue;
					if (tempR > tempB) {
						Rnxt.x -= dx[i];
						Rnxt.y -= dy[i];
					} else {
						Bnxt.x -= dx[i];
						Bnxt.y -= dy[i];
					}
				}
				//5. 체크인, 간다.(enqueue)
				if (visited[Rnxt.x][Rnxt.y][Bnxt.x][Bnxt.y]) continue;
				R.push(Rnxt);
				B.push(Bnxt);
				visited[Rnxt.x][Rnxt.y][Bnxt.x][Bnxt.y] = true;
			}
			
		}
		if (result == 10) 
			return -1;
		result++;
	}
	return -1;
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++) {
		scanf("%s", buf);
		for (int j=0;j<M;j++) {
			map[i][j] = buf[j];
			if (map[i][j] == 'B') 
				B.push(Info(i, j)), map[i][j] = '.';
			else if (map[i][j] == 'R')
				R.push(Info(i, j)), map[i][j] = '.';
		}
	}
	printf("%d\n", bfs());

	return 0;
}