//bfs, 

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[9][9];
bool visited[9][9];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
queue< pair<int,int> > q;

void bfs()
{
	while (!q.empty()) {
		//체크아웃
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//목적지인가?

		//갈 수 있는가?
		for (int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) {
				//간다
				//체크인&큐에넣기

				map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

}
void printmap()
{
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	printmap();

	bfs();

	printmap();


	return 0;
}