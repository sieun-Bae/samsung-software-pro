//DFS와 BFS
#include <iostream>
#include <queue>
using namespace std;

int n,m,v;
int adj[1010][1010];
bool visited[1010];

void dfs(int s)
{
	int i=0;
	//1. 체크인
	printf("%d ", s);
	visited[s] = true;
	//3. 연결된 곳 순회
	for (i=1;i<=n;i++) {
		//4. 갈 수 있는가?
		if (!visited[i] && adj[s][i]) {
			//5. 간다.
			dfs(i);
			//6. 체크아웃
		}
	} 
	//2. 목적지인가?
	if (i==n) return;

}

void bfs()
{
	queue<int> q;

	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
	//1. dequeue
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		//2. 목적지인가?
		//3. 연결된 곳 순회
		for (int i=1;i<=n;i++) {
		//4. 갈 수 있는가?
			if (!visited[i] && adj[cur][i]) {
			//5. enqueue & 체크인	
				visited[i] = true;
				q.push(i);
			}
		}

	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &v);
	for (int i=0;i<m;i++) {
		int s,e;
		scanf("%d%d", &s, &e);
		adj[s][e] = 1;
		adj[e][s] = 1;
	}

	dfs(v);
	for (int i=0;i<=n;i++) {
		visited[i] = false;
	}
	printf("\n");
	bfs();

	return 0;
}