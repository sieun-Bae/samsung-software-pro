//단절점

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool ans[10010], visit_order[10010];
int v,e, cnt, num=1;
vector<int> adj[10010];
int getMin(const int a, const int b) {
	if (a>b) return b;
	else return a;
}
//dfs
int dfs(int parent, int cur, bool isRoot)
{
	int min_visit_order = 200000;
	int chlcnt = 0;
	visit_order[cur] = num;
	num++;

	for (int i=0;i<adj[cur].size();i++) {
	//부모 아닌데
		int nxt = adj[cur][i];
	//	다음 노드가 부모이면
		if (nxt == parent) continue;
	//	이미 탐색했다면
		if (visit_order[nxt]) {
			min_visit_order = getMin(visit_order[nxt], min_visit_order);
		}
	//	아직 탐색하지 않았다면
		else {
			int tmp = dfs(cur, nxt, 0);
			min_visit_order = getMin(min_visit_order, tmp);
			if (isRoot != true && tmp >= visit_order[cur]) {
				ans[cur] = true;
			}
			chlcnt++;
		}
	//		low < visit_order[cur]라면 단절점
	}
	//부모인데
	if (isRoot) {
	//	자식 2개이상이면 단절점
		if (chlcnt >= 2) ans[cur] = true;
	}
	return getMin(min_visit_order, visit_order[cur]);
}
int main()
{
	scanf("%d%d", &v, &e);
	int a,b;
	for (int i=0;i<e;i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1;i<=v;i++) {
		if (visit_order[i] == 0) dfs(0, i, 1);
	}
	//출력
	for (int i=1;i<=v;i++) {
		if (ans[i]) cnt++;
	}
	printf("%d\n", cnt);
	for (int i=1;i<=v;i++) {
		if (ans[i]) printf("%d ", i);
	}
	return 0;
}