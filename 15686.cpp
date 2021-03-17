#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n,m;
int map[55][55];
bool visited[13];
int chicken_cnt = 0;
vector< pair<int, int> > chickens, houses;

int ans=INF;

int distance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first-b.first) + abs(a.second-b.second);
}

void dfs(int idx, int cnt)
{
	//목적지인가?
	if (cnt == m) { //치킨집 최대 m개 다 골랐으면
		//도시 치킨거리 계산
		int tmp=0;
		for (int i=0;i<houses.size();i++) {
			int dist = INF;
			for (int j=0;j<chickens.size();j++) {
				if (visited[j])
					dist = min(dist, distance(houses[i], chickens[j]));
			}
			tmp += dist;
		}
		ans = min(ans, tmp);
	}
	if(idx==chickens.size()) return;
	//선택한경우
	visited[idx] = true;
	dfs(idx+1, cnt+1);
	//선택안한경우
	visited[idx] = false;
	dfs(idx+1, cnt);
}

int main()
{
	scanf("%d%d", &n,&m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d",&map[i][j]);
			if (map[i][j]==1) houses.push_back(make_pair(i,j));
			else if (map[i][j]==2) chickens.push_back(make_pair(i,j));
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}