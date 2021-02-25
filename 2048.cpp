#include <iostream>
using namespace std;

int n, ans;
int board[25][25];

void dfs(int depth)
{
	//최대 5번 이동
	//상하좌우 네 방향 이동
	//5번째에 답 return
	
	int tmp_board[25][25];
	//체크인
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			tmp_board[i][j] = board[i][j];
		}
	}
	//목적지인가?
	if (idx==5) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return ans;
	}
	//주변 탐색
	for (int d=0;d<4;d++) {
		//사방탐색 갈 수 있는가? -> 완전탐색

		//간다
		dfs(depth+1);
		//체크아웃
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				board[i][j] = tmp_board[i][j];
			}
		}
	}
}

int main()
{
	//보드판 입력
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d", &board[i][j]);
		}
	}

	printf("%d\n", dfs(0));
	return 0;
}