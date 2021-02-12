//부분합 조합 만들어놓고, two pointer
//빈도 (조합 갯수 찾기 (동률))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
ll t;
ll a[1010], b[1010];
vector<ll> subA, subB;

int main()
{
	//입력
	scanf("%lld", &t);
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &m);
	for (int i=0;i<m;i++) {
		scanf("%lld", &b[i]);
	}
	//가능한 모든 조합의 부분합 구하기
	for (int i=0;i<n;i++) {
		ll s=a[i];
		subA.push_back(s);
		for (int j=i+1;j<n;j++) {
			s+=a[j];
			subA.push_back(s);
		}
	}
	for (int i=0;i<m;i++) {
		ll s=b[i];
		subB.push_back(s);
		for (int j=i+1;j<m;j++) {
			s+=b[j];
			subB.push_back(s);
		}
	}
	//합이 t인 조합 구하기
	ll result = 0;
	sort(subB.begin(), subB.end());

	for (int i=0;i<subA.size();i++) {
		ll target = t-subA[i];
		int low = lower_bound(subB.begin(), subB.end(), target) - subB.begin();
		int up = upper_bound(subB.begin(), subB.end(), target) - subB.begin();	
		result += (up-low);
	}

	printf("%lld", result);
	return 0;
}