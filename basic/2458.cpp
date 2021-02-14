//위상정렬, indegree+outdegree+1 = n
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m,answer, cnt, cnt_rev;
bool visited[510], visited_rev[510];
vector<int> adj[510], rev[510];

void dfs(int cur)
{
	if (visited[cur]) return;
	visited[cur] = true;
	cnt++;
	for (int i=0;i<adj[cur].size();i++) {
		dfs(adj[cur][i]);
	}
}

void dfs_rev(int cur)
{
	if (visited_rev[cur]) return;
	visited_rev[cur] = true;
	cnt_rev++;
	for (int i=0;i<rev[cur].size();i++) {
		dfs_rev(rev[cur][i]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i=1;i<=n;i++) {
		cnt=0;
		memset(visited, 0x00, sizeof(visited));
		dfs(i);

		cnt_rev=0;
		memset(visited_rev, 0x00, sizeof(visited));
		dfs_rev(i);

		if ((cnt+cnt_rev-1) == n) answer++;
	}
	printf("%d", answer);
	return 0;
}