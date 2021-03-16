#include <iostream>
#define MAX 98765
using namespace std;

int n,m,h;
int garo[35][15];

int sadari;
bool flag;


void dfs(int x, int cnt)
{
	if (flag)
		return;
	//목적지인가?
	if (sadari == cnt) {
		bool possible = true;
		for (int k=1;k<=n;k++) {
			int j=k;
			for (int i=0;i<h;i++) {
				if (garo[i][j]) 
					j++;
				else if (j>1 && garo[i][j-1]) 
					j--;
			}
			if (j != k) {
				possible = false;
				break;
			}
		}	
		if (possible) flag = true;
		return;
	}
	
	//갈 수 있는 곳 탐색
	for (int i=x;i<h;i++) {
		for (int j=1;j<n;j++) {
			//갈 수 있는가?
			if (!garo[i][j-1] && !garo[i][j] && !garo[i][j+1]) {
				//간다
				garo[i][j] = 1;
				dfs(i, cnt+1);
				garo[i][j] = 0;
			}
		}
	}
	return;
}
int main()
{
	//초기화
	scanf("%d%d%d", &n,&m,&h);
	for (int i=0;i<m;i++) {
		int r,c;
		scanf("%d%d", &r, &c);
		garo[r-1][c] = 1;
	}
	//사다리 최대 3개까지만 추가해봄
	for (int i=0;i<=3;i++) {
		sadari = i;
		dfs(0,0);
		if (flag)
		{
			printf("%d\n", sadari);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}