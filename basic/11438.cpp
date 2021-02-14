//lca, bit, graph
#include <iostream>
#include <vector>
using namespace std;

int n,m, depth[100010], an[100010][18];
vector<int> adj[100010];
bool visited[100010];

void dfs(int parent, int cur, int param_depth) //자료수집 depth, parent
{
	if (visited[cur]) return;
	visited[cur] = true;
	depth[cur] = param_depth;
	an[cur][0] = parent;
	for (int i=0;i<adj[cur].size();i++) {
		dfs(cur, adj[cur][i], param_depth+1);
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (depth[a] != depth[b]) {
		int diff = depth[a] - depth[b];
		for (int i=0, j=1; i<=17; i++, j*=2) {
			if (diff & j) {
				a = an[a][i];
			}
		}
	}
	if (a==b) return a;
	for (int i=17;i>=0;i--) {
		if (an[a][i] != an[b][i]) {
			a = an[a][i];
			b = an[b][i];
		}
	}
	return an[a][0];
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1,1);

	for (int i=1;i<=17;i++) {
		for (int j=1;j<=n;j++) {
			int tmp = an[j][i-1];
			an[j][i] = an[tmp][i-1];
		}
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a,b));
	}
	return 0;
}