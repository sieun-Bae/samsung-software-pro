#include <iostream>
#include <vector>
using namespace std;

int n, u, v;
vector<int> adj[1000010];
vector<int> child[1000010];
bool visited[1000010];
int dp[1000010][2];

void makeChild(int cur) {
	visited[cur] = true;
	for (int i=0;i<adj[cur].size();i++) {
		int nxt = adj[cur][i];
		if (!visited[nxt]) {
			child[cur].push_back(nxt);
			makeChild(nxt);
		}
	}
}
int dfs(int cur, int state)
{
	if (dp[cur][state]!=0) return dp[cur][state];
	if (state == 0) {
		for (int i=0;i<child[cur].size();i++) {
			int nxt = child[cur][i];
			dp[cur][state] += dfs(nxt, 1);
		}
	} else {
		for (int i=0;i<child[cur].size();i++) {
			int nxt = child[cur][i];
			dp[cur][state] += min(dfs(nxt, 0), dfs(nxt,1));
		}
		dp[cur][state]++;
	}
	return dp[cur][state];
}

int main()
{
	scanf("%d", &n);
	for (int i=0;i<(n-1);i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	makeChild(1);
	printf("%d", min(dfs(1,0), dfs(1,1)));
	return 0;
}