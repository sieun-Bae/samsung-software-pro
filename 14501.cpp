#include <iostream>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16];

int main()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d%d", &t[i], &p[i]);
	}

	for (int i=n-1;i>=0;i--) {
		if (i+t[i] >= n+1) {
			dp[i] = max(dp[i+1], 0);
			continue;
		}
		dp[i] = max(dp[i+t[i]]+p[i], dp[i+1]);
	}

	printf("%d", dp[0]);

	return 0;
}