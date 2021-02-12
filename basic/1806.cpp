//two pointer, 부분합
#include <iostream>
#include <vector>
#define MAX 999999
using namespace std;

int n, m;
vector<int> arr;

int main()
{
	scanf("%d%d", &n, &m);
	int i=0, temp;
	for (i=0;i<n;i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	arr.push_back(0); //마지막에 0 추가

	int s, e, sum=arr[0];
	int result = MAX;
	bool exist = false;
	while (e != n && s != n) {
		if (sum >= m) {
			exist = true;
			result = min(result, e-s+1);
			sum -= arr[s++];
		} else {
			sum += arr[++e];
		}
	}
	if (exist) printf("%d", result);
	else printf("0");

	return 0;
}