//bfs, 

#include <iostream>
#include <queue>
using namespace std;

int n,m,answer;
int map[8][8];
int temp_map[8][8];

//bool visited[9][9];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
vector< pair<int,int> > virus;

void bfs()
{
	queue< pair<int,int> > q;
	for (int i=0;i<virus.size();i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
	}

	while (!q.empty()) {
		//체크아웃
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//목적지인가? => 완전탐색

		//갈 수 있는가?
		for (int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			//if (temp_map[nx][ny] == 1) continue;
			if (temp_map[nx][ny] == 0) {
				//간다
				//체크인&큐에넣기
				temp_map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int temp_answer = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (temp_map[i][j] == 0)
				temp_answer++;
		}
	}
	answer = max(answer, temp_answer);
}

void wall(int cnt)
{
	if (cnt == 3) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				temp_map[i][j] = map[i][j];
			}
		}

		return bfs();
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(cnt+1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(1);
				map[i][j] = 0;
			}
		}
	}

	printf("%d", answer);

	return 0;
}