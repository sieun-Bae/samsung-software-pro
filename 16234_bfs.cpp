#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n,l,r, ans=0;
int map[55][55];
bool visited[55][55];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void init()
{
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			visited[i][j] = false;
		}
	}
}

int main()
{
	bool flag;
	scanf("%d%d%d",&n,&l,&r);
	for (int x=0;x<n;x++) {
		for (int y=0;y<n;y++) {
			scanf("%d", &map[x][y]);
		}
	}
	
	while(true){
		flag=false;
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				if (visited[x][y] == 0) {
					queue< pair<int, int> > q;
					queue< pair<int, int> > locations;
					int sum=0;
					int count=0;

					locations.push(make_pair(x,y));
					q.push(make_pair(x,y));

					while (!q.empty()) {
						int curX = q.front().first;
						int curY = q.front().second;

						visited[curX][curY] = true;
						sum += map[curX][curY];
						count++;

						q.pop();
						
						for (int i=0;i<4;i++) {
							int nx = curX+dx[i];
							int ny = curY+dy[i];
							int tmp = abs(map[nx][ny] - map[curX][curY]);
							if (nx >= 0 && nx < n && ny>=0 && ny<n && !visited[nx][ny] && tmp>=l && tmp<=r) {
								q.push(make_pair(nx,ny));
								locations.push(make_pair(nx,ny));
								visited[nx][ny] = true;
								flag = true;
							}
						}
					}
					int pop = sum/count;
					while (!locations.empty()) {
						int x = locations.front().first;
						int y = locations.front().second;
						locations.pop();
						map[x][y] = pop;
					}
				}
			}
		}
		if (!flag) break;
		else {
			init();
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}