#include <iostream>
#include <vector>
using namespace std;

int n,x,y,d,g;
int map[110][110];
int ans=0;
vector<int> dir_info;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void funcf()
{
	int s = dir_info.size();
	for (int i=(s-1);i>=0;i--) {
		int nd = (dir_info[i]+1)%4;
		dir_info.push_back(nd);
		x += dx[nd];
		y += dy[nd];
		map[x][y] = 1;
	}
	return;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d%d",&y,&x,&d,&g);
		dir_info.clear();
		//0th generation
		map[x][y] = 1;
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		dir_info.push_back(d);
		for (int j=0;j<g;j++) {
			funcf();			
		}
	}
	//정사각형 갯수 구하기
	for (int i=1;i<101;i++) {
		for (int j=1;j<101;j++) {
			if (map[i][j]==1 && map[i-1][j]==1 && map[i-1][j-1]==1 && map[i][j-1]==1) ans++;
		}	
	}
	printf("%d\n", ans);
	return 0;
}