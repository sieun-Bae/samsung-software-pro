//스타트와 링크
#include <iostream>
#include <vector>
#define MIN 99999999
using namespace std;

int n, s[20][20];
bool team[20];
int answer = MIN;

void dfs(int idx, int cnt)
{
	//목적지인가?
	if (cnt == (n/2)) {
		vector<int> start;
		vector<int> link;
		int start_score=0, link_score=0;
		for (int i=0;i<n;i++) {
			if (team[i]==true)
				start.push_back(i);
			else
				link.push_back(i);
		}
		for (int i=0;i<(n/2);i++) {
			for (int j=0;j<(n/2);j++) {
				start_score += s[start[i]][start[j]];
				link_score += s[link[i]][link[j]];
			}
		}
		answer = min(answer, abs(start_score - link_score));
		return;
	}
	//주변 탐색
	for (int i=idx;i<n;i++) {
		if (team[i]) continue;
		else {
			//체크인
			team[i] = true;
			dfs(i, cnt+1);
			//체크아웃
			team[i] = false;
		}
	}	

}

int main()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d", &s[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", answer);
	return 0;
}