#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef struct info {
	int idx;
	int x,y;
	int size;
	info(int ii, int xx, int yy, int ss) {
		idx = ii;
		x = xx;
		y = yy;
		size = ss;
	}
	info() {}
} info;

int n;
info map[21][21];
int visited[21][21];
int answer;

vector<info> fishes;
vector<info> possibleFish;
int fish_num;
int eat_num;
info shark;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int distance(info o1)
{
	return abs(o1.x-shark.x) + abs(o1.y-shark.y);
}

bool isPossible()
{
	for (int i=0;i<fishes.size();i++) {
		if (shark.size > fishes[i].size)
			return true;
	}
	return false;
}

bool cmp(const info& o1, const info& o2)
{
	if (visited[o1.x][o1.y] == visited[o2.x][o2.y]) {
		if (o1.x == o2.x) {
			return o1.y < o2.y;
		} else
			return o1.x < o2.x;
	} else
		return visited[o1.x][o1.y] < visited[o2.x][o2.y];
}

void bfs()
{
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			visited[i][j] = INF;
		}
	}
	queue< info > q;
	q.push(shark);
	visited[shark.x][shark.y] = 0;
	int ss = shark.size;
	while(!q.empty())
	{
		
		//start_point
		int sx = q.front().x;
		int sy = q.front().y;
		//visited[sx][sy] = true;

		q.pop();

		for (int d=0;d<4;d++) {
			int nx = sx+dx[d];
			int ny = sy+dy[d];

			if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
			if (map[nx][ny].size > ss) continue; //상어보다 큰 물고기
			if (visited[nx][ny] != INF) continue;
			//printf("%d: (%d,%d) size: %d\n", map[nx][ny].idx, map[nx][ny].x, map[nx][ny].y, map[nx][ny].size);
				
			if (map[nx][ny].idx != -1 && map[nx][ny].size < ss) { //빈칸이 아닌데 상어보다 크기 작은 물고기
				//printf("possible\n");
				//printf("%d: (%d,%d) size: %d\n", map[nx][ny].idx, map[nx][ny].x, map[nx][ny].y, map[nx][ny].size);
				possibleFish.push_back(map[nx][ny]);
			}
			//빈칸이거나 크기 같은 물고기있는 칸
			q.push(map[nx][ny]);
			visited[nx][ny] = min(visited[nx][ny], visited[sx][sy] + 1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp==9) { //상어 좌표 저장
				shark = info(0, i, j, 2);
				map[i][j] = info(-1,i,j,-1);
				continue;
			}
			if (tmp) { //물고기 크기, 좌표 저장
				fish_num++;
				fishes.push_back(info(fish_num, i,j,tmp));
				map[i][j] = info(fish_num, i, j, tmp);
				continue;
			} 
			//빈칸
			map[i][j] = info(-1,i,j,-1);
		}
	}
	/*printf("%d\n", fish_num);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d: (%d,%d) size: %d ", map[i][j].idx, map[i][j].x, map[i][j].y, map[i][j].size);
		}
		printf("\n");
	}*/
	if (fish_num==0) {
		printf("0\n");
		return 0;
	} 

	while(true) {
		//printf("*\n");
		if (!isPossible()) 
			break;
		if (fishes.size() == 1) { 
			//printf("**\n");
			eat_num++;

			map[fishes[0].x][fishes[0].y] = info(-1,fishes[0].x,fishes[0].y,-1);;
			answer += distance(fishes[0]);
			if (eat_num == shark.size) {
				shark.size++;
				eat_num = 0;
			}
			shark.x = fishes[0].x;
			shark.y = fishes[0].y;

			fishes.clear();
			break;
		}
		//printf("***\n");
		possibleFish.clear();
		bfs();
		//printf("***possible***\n");
		//printf("%d\n", possibleFish.size());
		
		if (possibleFish.size()==0) {
			break;
		}
		/*
		printf("visited!!!!\n");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				printf("%d ", visited[i][j]);
			}
			printf("\n");
		}*/
		sort(possibleFish.begin(), possibleFish.end(), cmp); //거리 작은 순
		/*
		printf("---sort---\n");
		for (int i=0;i<possibleFish.size();i++) {
			printf("%d: (%d,%d) size: %d, distance: %d\n", possibleFish[i].idx, possibleFish[i].x, possibleFish[i].y, possibleFish[i].size, distance(possibleFish[i]));
		}*/
		
		map[possibleFish[0].x][possibleFish[0].y] = info(-1,possibleFish[0].x,possibleFish[0].y,-1);;
		/**************************************/

		answer += visited[possibleFish[0].x][possibleFish[0].y];
		
		eat_num++;
		if (eat_num == shark.size) {
			shark.size++;
			eat_num = 0;
		}
		shark.x = possibleFish[0].x;
		shark.y = possibleFish[0].y;

		for (int i=0;i<fishes.size();i++) {
			if (possibleFish[0].idx == fishes[i].idx) {
				fishes.erase(fishes.begin()+i);
				break;
			}
		}
		/*
		printf("************\n");
		printf("eat_num: %d, shark: (%d, %d), shark_size: %d,  answer: %d\n remain fish: ", eat_num, shark.x, shark.y,shark.size, answer);
		for (int i=0;i<fishes.size();i++) {
			printf("%d ", fishes[i].idx);
		}
		printf("\n");*/
	}

	printf("%d\n", answer);

	return 0;
}