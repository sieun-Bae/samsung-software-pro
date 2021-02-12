//parametric search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll> trees;

ll calc(ll value)
{
	ll result=0;
	for (int i=0;i<n;i++) {
		if (trees[i]>value) result += trees[i]-value;
	}
	return result;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	ll temp;
	for (int i=0;i<n;i++) {
		scanf("%lld", &temp);
		trees.push_back(temp);
	}
	sort(trees.begin(), trees.end());
	ll s=0, e=trees.back(), mid;
	ll ans=0;
	while (true) {
		mid = (s+e)/2;
		ll sum = calc(mid);

		if (sum==m) {
			ans = mid;
			break;
		} else if (sum < m) {
			e = mid-1;
		} else {
			ans = mid;
			s = mid+1;
		}
		if (s > e) break;
	}
	printf("%lld", ans);
	return 0;
}