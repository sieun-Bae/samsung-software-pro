//dijk 1:1 >=0
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

typedef struct Info{
	int b,c;
	Info(int bb, int cc) {
		b = bb;
		c = cc;
	}
}Info;
typedef struct Dijk_Info{
	int num, dist;
	Dijk_Info(int nn, int dd) {
		num = nn;
		dist = dd;
	}
}Dijk_Info;
int v,e, start_point, dist[20010];
vector<Info> adj[20010];

struct comp {
	bool operator()(Dijk_Info a, Dijk_Info b) {
		return a.dist > b.dist;
	}
};

void dijk()
{
	priority_queue<Dijk_Info, vector<Dijk_Info>, comp> pq;
	dist[start_point] = 0;
	pq.push(Dijk_Info(start_point,0));
	while (!pq.empty()) {
		Dijk_Info cur = pq.top();
		pq.pop();

		if (dist[cur.num] < cur.dist) continue;
		for (int i=0;i<adj[cur.num].size();i++) {
			Info nxt = adj[cur.num][i];
			int tmp = cur.dist + nxt.c;
			if (tmp < dist[nxt.b]) {
				dist[nxt.b] = tmp;
				pq.push(Dijk_Info(nxt.b, tmp));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &v,&e, &start_point);
	for (int i=0;i<e;i++) {
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back(Info(b,c));
	}
	for (int i=1;i<=v;i++) dist[i] = INF;
	dijk();

	for (int i=1;i<=v;i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}