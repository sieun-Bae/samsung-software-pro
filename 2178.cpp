#include <iostream>
#define MAX 987654321
using namespace std;

int map[110][110], n, m;
bool visited[110][110];
int result = MAX;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y, int cnt)
{
	//체크인
	
	//목적지인가?
	if (x==(n-1) && y==(m-1)) {
		result = min(result, cnt);
		return;
	}
	//주변 탐색
	for (int i=0;i<4;i++) {
		int tx = x+dx[i];
		int ty = y+dy[i];
		//갈수있는가?
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
		if (map[tx][ty] == 1 && visited[tx][ty] == false) {
			//간다
			visited[x][y] = true;
			dfs(tx, ty, cnt+1);
			visited[x][y] = false;
		}
	}
	//체크아웃
	//visited[x][y] = false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%1d",&map[i][j]);
		}
	}
	
	dfs(0,0,1);
	printf("%d\n", result);
	return 0;
}