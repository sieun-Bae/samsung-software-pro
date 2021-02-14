//mst, sort, union-find, kruskal algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef struct Info {
	int a,b,c;
	Info(int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
	}
}Info;
int n, m;
int pr[1010];
vector<Info> edge;

int findf(int a)
{
	if (pr[a]==a) return a;
	pr[a] = findf(pr[a]);
	return pr[a];
}

void unionf(int a, int b)
{
	a = findf(a);
	b = findf(b);
	pr[a] = b;
}
bool cmp(const Info& o1, const Info& o2) {
	return o1.c < o2.c;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<=n;i++) {
		pr[i] = i;
	}

	int a,b,c;
	for (int i=0;i<m;i++) {
		scanf("%d%d%d", &a, &b, &c);
		edge.push_back(Info(a,b,c));
	}
	sort(edge.begin(), edge.end(), cmp);

	ll ans=0;
	for (int i=0;i<m;i++) {
		int a = edge[i].a;
		int b = edge[i].b;
		int c = edge[i].c;
		if (findf(a) != findf(b)) {
			ans += c;
			unionf(a, b);
		}
	}
	printf("%lld", ans);
	return 0;
}