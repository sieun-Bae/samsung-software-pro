// heap, greedy
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct jewelry {
	int m, v;
	jewelry(int mm, int vv) {
		m = mm;
		v = vv;
	}
} jewelry;

struct cmpValue {
	bool operator()(const jewelry& o1, const jewelry& o2) {
		return o1.v < o2.v;
	}
};

int n,k;
vector<int> bags;
vector<jewelry> jewelries;
bool cmpWeight(const jewelry& o1, const jewelry& o2) {
	return o1.m < o2.m;
}

int main()
{
	scanf("%d%d", &n, &k);
	int m, v;
	for (int i=0;i<n;i++) {
		scanf("%d%d", &m, &v);
		jewelries.push_back(jewelry(m, v));
	}
	int temp;
	for (int i=0;i<k;i++) {
		scanf("%d", &temp);
		bags.push_back(temp);
	}
	sort(jewelries.begin(), jewelries.end(), cmpWeight);
	sort(bags.begin(), bags.end());

	priority_queue <jewelry, vector<jewelry>, cmpValue > pq;
	int jIdx=0;
	ll ans=0;
	for (int i=0;i<k;i++) {
		while (jIdx < n && jewelries[jIdx].m <= bags[i]) {
			pq.push(jewelries[jIdx++]);
		}
		if (!pq.empty()) {
			ans += pq.top().v;
			pq.pop();
		}
	}
	printf("%lld", ans);
	return 0;
}