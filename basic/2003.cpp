//two pointer, 부분합
#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> arr;

int main()
{
	scanf("%d%d", &n, &m);
	int temp;
	for (int i=0;i<n;i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	arr.push_back(0);

	int s=0,e=0,sum=arr[0];
	int result=0;

	while (e != n && s != n) {
		if (sum == m) {
			result++;
			sum -= arr[s++];
		} else if (sum < m) {
			sum += arr[++e];
		} else sum -= arr[s++];
	}

	printf("%d", result);
	return 0;
}