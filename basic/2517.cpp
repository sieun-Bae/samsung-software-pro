//inversion count

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

typedef struct runner {
	ll value;
	int position;
} runner;

int n;
vector<runner> runners;
vector<int> ranks;

void merge(runner* temp, int s, int m, int e)
{
	int p1 = s;
	int p2 = m+1;
	int k = s;

	while (p1 <= m && p2 <= e) {
		if (runners[p1].value >= runners[p2].value) {
			temp[k++] = runners[p1++];
		} else {
			int cnt = m-p1+1;
			ranks[runners[p2].position] -= cnt;
			temp[k++] = runners[p2++];
		}
	}
	while (p1 <= m) {
		temp[k++] = runners[p1++];
	}
	while (p2 <= e) {
		temp[k++] = runners[p2++];
	}
	for (int i=s;i<=e;i++) {
		//printf("%lld %d", temp[i].value, temp[i].position);
		runners[i] = temp[i];
	}
}
void mergeSort(runner* temp, int s, int e)
{
	if (s<e) {
		int m = (s+e)/2;
		mergeSort(temp, s, m);
		mergeSort(temp, m+1, e);
		merge(temp, s, m, e);
	}
}

int main()
{
	scanf("%d",&n);
	runner temp[n];

	runner tmp;
	for (int i=0;i<n;i++) {
		scanf("%lld", &tmp.value);
		tmp.position = i;
		runners.push_back(tmp);
		ranks.push_back(i+1);
	}
	mergeSort(temp, 0, n-1);

	//출력
	for (int i=0;i<n;i++) printf("%d\n", ranks[i]);
	return 0;
}