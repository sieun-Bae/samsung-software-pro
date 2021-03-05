//연산자 끼워넣기
//연산자 우선순위 무시, 나눗셈은 몫만 취함

#include <iostream>
#include <vector>
#define MAX 1e9+1
using namespace std;
int n, maxR=-MAX, minR=MAX;
int num[12], op[4];

void dfs(int plus, int minus, int multiply, int divide, int cnt, int sum)
{
	//체크인
	//목적지인가
	if (cnt==n){
		maxR = max(maxR, sum);
		minR = min(minR, sum);
	}
	//주변탐색
	if (plus>0)
		dfs(plus-1, minus, multiply, divide, cnt+1, sum+num[cnt]);
	if (minus>0)
		dfs(plus, minus-1, multiply, divide, cnt+1, sum-num[cnt]);
	if (multiply>0)
		dfs(plus, minus, multiply-1, divide, cnt+1, sum*num[cnt]);
	if (divide>0)
		dfs(plus, minus, multiply, divide-1, cnt+1, sum/num[cnt]);
	//갈수있는가?
	//간다 -> 완전탐색
	//체크아웃
}
int main()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &num[i]);
	}
	for (int i=0;i<4;i++) {
		scanf("%d", &op[i]);
	}
	dfs(op[0],op[1],op[2],op[3],1,num[0]);
	printf("%d\n%d\n", maxR, minR);
	return 0;
}