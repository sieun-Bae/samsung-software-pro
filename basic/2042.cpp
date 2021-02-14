//indexTree

#include <iostream>
using namespace std;

typedef long long ll;
ll n,m,k;

ll makeTree(ll idxTree[], ll nums[], ll node, ll left, ll right)
{
	if (left == right) {
		if (left <= n) {
			idxTree[node] = nums[left];
			return idxTree[node];
		} else {
			idxTree[node] = 0;
			return idxTree[node];
		}
	}
	ll mid = (left+right)/2;
	idxTree[node] = makeTree(idxTree, nums, node*2, left, mid) + makeTree(idxTree, nums, node*2+1, mid+1, right);
	return idxTree[node];
}

ll query(ll idxTree[], ll node, ll left, ll right, ll qLeft, ll qRight)
{
	if (qLeft <= left && right <= qRight) {
		return idxTree[node];
	} else if (qRight < left || right < qLeft) {
		return 0;
	} else {
		ll mid = (left+right)/2;
		ll temp = query(idxTree, node*2, left, mid, qLeft, qRight) + query(idxTree, node*2+1, mid+1, right, qLeft, qRight);
		return temp;
	}
}

void update(ll idxTree[], ll node, ll left, ll right, ll idx, ll diff)
{
	if (left <= idx && idx <= right) {
		idxTree[node] += diff;
		if (left != right) {
			ll mid = (left+right)/2;
			update(idxTree, node*2, left, mid, idx, diff);
			update(idxTree, node*2+1, mid+1, right, idx, diff);
		}
	}
}

int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	ll s=1;
	while (s<n) {
		s*=2;
	}
	ll idxTree[2*s];
	ll nums[n+1];
	nums[0] = 0;
	for (ll i=1;i<=n;i++) {
		scanf("%lld", &nums[i]);
	}

	makeTree(idxTree, nums, 1, 1, s);

	for (ll i=0; i<m+k; i++) {
		ll a,b,c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a==1) {
			ll idx = b;
			ll diff = c - query(idxTree, 1, 1, s, idx, idx);
			update(idxTree, 1, 1, s, idx, diff);
		} else if (a==2) {
			printf("%lld\n", query(idxTree, 1, 1, s, b, c));
		}
	}
	return 0;
}