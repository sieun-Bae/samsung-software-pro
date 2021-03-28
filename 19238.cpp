#include <iostream>
#include <queue>
#define INF 987654
using namespace std;

typedef struct person{
	int idx;
	int sx, sy;
	int ex, ey;
	bool arrived;
	person(int ii, int ssx, int ssy, int eex, int eey) {
		idx = ii;
		sx = ssx;
		sy = ssy;
		ex = eex;
		ey = eey;
		arrived = false;
	}
}person;

int n,m,battery;
int map[21][21];
int visited[21][21];
pair<int, int> car;
vector<person> people;
int visit[410];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int start_x, int start_y)
{
	//최단거리 
	queue< pair<int,int> > q;
	q.push(make_pair(start_x, start_y));
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			visited[i][j] = 0;
		}
	}
	visited[q.front().first][q.front().second] = 0;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (1<=nx && nx<=n && 1<=ny && ny<=n && visited[nx][ny]==0 && map[nx][ny]==0) {
				q.push(make_pair(nx,ny));
				visited[nx][ny] = visited[cur_x][cur_y] +1;
			}
		}
	}
	
	for (int i=1;i<=n;i++) {
		printf("%d | ", i);
		for (int j=1;j<=n;j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &battery);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d", &car.first, &car.second);
	for (int i=0;i<m;i++) {
		int sx,sy,ex,ey;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		people.push_back(person(i, sx, sy, ex, ey));
	}

	while (true) {
		if (m == 0)
			break;
		//승객 선택
		int index=1, miin=987654;
		bfs(car.first, car.second);


		//visited[people.sx][people.sy]가 최소인 승객 -> sx가 작은 -> sy가 작은
		for (int i=0;i<people.size();i++) {
			int ob_sx = people[i].sx;
			int ob_sy = people[i].sy;
			if (visited[ob_sx][ob_sy] < miin && people[i].arrived == false) {
				miin = visited[ob_sx][ob_sy];
				index = people[i].idx;
			} else if (visited[ob_sx][ob_sy] == miin) {
				if (people[index].sx < ob_sx) {
					continue;
				} else if (people[index].sx == ob_sx) {
					if (people[index].sy < ob_sy) {
						continue;
					} else {
						if (people[i].arrived == false)
							index = people[i].idx;
					}
				} else {
					if (people[i].arrived == false)
						index = people[i].idx;
				}
			}
		}
		
		if (visited[people[index].sx][people[index].sy] == 0) {
			battery = 0;
			break;
		}
		
		printf("person: %d, (x,y) = (%d,%d) miin: %d\n", index, people[index].sx, people[index].sy, miin);
		if (battery >= miin) {
			battery -= miin;
			car.first = people[index].sx;
			car.second = people[index].sy;
			printf("m: %d\n", m);
		} else {
			battery = 0;
			break;
		}
		printf("battery: %d\n", battery);
		//해당 승객 출발지점부터 도착지점 거리 계산
		bfs(people[index].sx, people[index].sy);
		int tmp_b = visited[people[index].ex][people[index].ey];
		if (battery >= tmp_b) {
			people[index].arrived = true;
			battery += tmp_b;
			m--;
			car.first = people[index].ex;
			car.second = people[index].ey;
		} else { //연료 부족
			battery = 0;
			break;
		}
		printf("battery: %d\n", battery);
	}
	
	if (battery || m == 0) {
		printf("m: %d\n", m);
		printf("%d\n", battery);
	} else {
		printf("m: %d\n", m);
		printf("-1");
	}

	return 0;
}