#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Info {
	int num;
	int x,y;
	int dir;
	bool eaten;
	Info(int nn, int xx, int yy, int dd) {
		num = nn;
		x = xx;
		y = yy;
		dir = dd;
		eaten = false;
	}
	Info () {};
}info;

int ocean[4][4]; //(num, dir)
info fish[17]; //(x, y)

info shark;

int dx[9] = {0,-1,-1,0,1,1,1,0,-1}; // 위, 왼위, 왼, 왼아래, 아래, 오아래, 오, 오위
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

int answer = -1;

bool comp(const info& o1, const info& o2) {
	return o1.num < o2.num;
}
//tmp_ocean, tmp_fish, shark, total+tmp
void dfs(int ocean[4][4], info fish[17], info shark, int total)
{
	answer = max(answer, total);
	// 물고기 이동
	for (int i=1;i<=16;i++) {
		//if (fish[i].eaten) continue;
		int cx = fish[i].x;
		int cy = fish[i].y;
		int dir = fish[i].dir;
		if (dir==0) continue;
		//printf("nth: %d x: %d y: %d dir: %d\n", i, cx, cy, fish[i].dir);
		int dirCnt = 0;
		int nx = cx+dx[dir];
		int ny = cy+dy[dir];
		for (dirCnt=0;dirCnt<8;dirCnt++) {
			//int dir = fish[i].dir;
			nx = cx+dx[dir];
			ny = cy+dy[dir];
			//1번 물고기부터 이동, 이동 방향에 물고기 있으면 위치 교환
			//printf("nth: %d nx: %d ny: %d dir: %d shark.x: %d shark.y: %d\n", i, nx, ny, dir, shark.x, shark.y);
			if (shark.x == nx && shark.y == ny) {
				fish[i].dir = (dir==8)?1:dir+1;
				dir = fish[i].dir;
				continue;
			}
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) { 
				fish[i].dir = (dir==8)?1:dir+1;
				dir = fish[i].dir;
				continue;
			} 
			//갈 수 있으면
			break;
		}
		if (dirCnt == 8) continue;
		int a = ocean[nx][ny];
		if (a) {
			fish[a].x = cx;
			fish[a].y = cy;
			ocean[cx][cy] = a;
		} else {
			ocean[cx][cy] = 0; 
		}
		
		ocean[nx][ny] = i;
		fish[i].x = nx;
		fish[i].y = ny;
	} 
	// 상어 이동
	int cx = shark.x;
	int cy = shark.y;
	int dir = shark.dir;

		//먹은 물고기의 방향으로 선택적으로 이동, 물고기 먹으면 멈춤
		//물고기 없는 칸으로는 이동 불가, 이동할 수 있는 칸 없으면 종료
	
	for (int i=1;i<=3;i++) { //최대 3번 이동가능
		int tmp_ocean[4][4];
		info tmp_fish[17];
		//fishes 백업
		for (int idx=0;idx<=16;idx++) {
			tmp_fish[idx] = fish[idx];
		}
		for (int j=0;j<4;j++) {
			for (int k=0;k<4;k++) {
				tmp_ocean[j][k] = ocean[j][k];
			}
		}
		//주변 탐색
		int nx = cx + dx[dir]*i;
		int ny = cy + dy[dir]*i;
		//갈 수 있으면
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (tmp_ocean[nx][ny] == 0) continue;
		//간다
		shark.x = nx;
		shark.y = ny;
		
		int score = tmp_ocean[nx][ny];
		tmp_ocean[nx][ny] = 0;

		shark.dir = tmp_fish[score].dir;
		tmp_fish[score].eaten = true;
		tmp_fish[score].dir = 0;
		dfs(tmp_ocean, tmp_fish, shark, total+score);
	}
}

int main()
{
	//fish[0] = Info(0,-1,-1,0);
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			int num, dir;
			scanf("%d%d", &num, &dir);
			if (i == 0 && j == 0) { //상어
				shark = Info(num, 0, 0, dir);
				continue;
			}
			ocean[i][j] = num;
			fish[num] = Info(num, i, j, dir);
		}
	}
	/*
	for (int i=0;i<=16;i++) {
		printf("num: %d, x: %d, y: %d, dir: %d eaten: %d\n", fish[i].num, fish[i].x, fish[i].y, fish[i].dir, fish[i].eaten);
	}*/
	//printf("%d\n", shark.num);
	dfs(ocean, fish, shark, shark.num);
	/*
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			printf("%d ", ocean[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", answer);
	return 0;
}