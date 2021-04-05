#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Info {
	int num;
	int x,y;
	int dir;
	Info(int nn, int xx, int yy, int dd) {
		num = nn;
		x = xx;
		y = yy;
		dir = dd;
	}
	Info () {};
}info;

vector <info> ocean[4]; //(num, dir)
vector <info> fish; //(x, y)
int visited[4][4];
info shark;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

bool comp(const info& o1, const info& o2) {
	return o1.num < o2.num;
}

void dfs()
{
	vector<info> temp_ocean[4];
	// 물고기 이동
	for (int i=1;i<=16;i++) {
		
	}
		//1번 물고기부터 이동, 이동 방향에 물고기 있으면 위치 교환
		//이동할 수 없으면 45도 반시계 회전,  
	// 
	// 상어 이동
		//먹은 물고기의 방향으로 선택적으로 이동, 물고기 먹으면 멈춤
		//물고기 없는 칸으로는 이동 불가, 이동할 수 있는 칸 없으면 종료
	if (상어 이동 불가) {

		return;
	}
	//주변 탐색
	for (int i=0;i<4;i++) {
		int nx = shark.x + dx[shark.dir];
		int ny = shark.y + dy[shark.dir];
		if (ocean[nx][ny] != 0 && 0<=nx && nx<n && 0<=ny && ny<n) {
			dfs();
			visited[nx][ny] = true;
			dfs();
			visited[nx][ny] = false;
		}
	}
	
}

int main()
{
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			int num, dir;
			scanf("%d%d", &num, &dir);
			ocean[i].push_back(Info(num, i, j, dir));
			fish.push_back(Info(num, i, j, dir));
		}
	}

	sort(fish.begin(), fish.end(), comp);
	shark = Info(-1, 0, 0, ocean[0][0].dir);

	
	
	for (int i=0;i<16;i++) {
		printf("num: %d, x: %d, y: %d\n", fish[i].num, fish[i].x, fish[i].y);
	}
	
	return 0;
}