#include <iostream>
#include <queue>
using namespace std;

int n, ans = -987654321;
int board[25][25];

void go(int dir)
{
	queue<int> q;
	switch (dir) {
		case 0: //상
			for (int c=0;c<n;c++) {
				for (int r=0;r<n;r++) {
					if (board[r][c] != 0) {
						q.push(board[r][c]);
						board[r][c] = 0;
					}
				}
				int idx=0;
				while(!q.empty()) {
					int block = q.front();
					q.pop();
					if (board[idx][c] == 0)
						board[idx][c] = block;
					else if (board[idx][c] == block) {
						board[idx][c] *= 2;
						idx++;
					} else {
						board[++idx][c] = block;
					}
				}
			}
			break;
		case 1: //하
			for (int c=0;c<n;c++) {
				for (int r=n-1;r>=0;r--) {
					if (board[r][c] != 0) {
						q.push(board[r][c]);
						board[r][c] = 0;
					}
				}
				int idx = n-1;
				while (!q.empty()) {
					int block = q.front();
					q.pop();

					if (board[idx][c] == 0)
						board[idx][c] = block;
					else if (board[idx][c] == block) {
						board[idx][c] *= 2;
						idx--;
					} else {
						board[--idx][c] = block;
					}
				}
			}
			break;
		case 2: //좌
			for (int r=0;r<n;r++) {
				for (int c=0;c<n;c++) {
					if (board[r][c] != 0) {
						q.push(board[r][c]);
						board[r][c] = 0;
					}
				}
				int idx=0;
				while (!q.empty()) {
					int block = q.front();
					q.pop();

					if (board[r][idx] == 0)
						board[r][idx] = block;
					else if (board[r][idx] == block) {
						board[r][idx] *= 2;
						idx++;
					} else {
						board[r][++idx] = block;
					}
				}
			}
			break;
		case 3: //우
			for (int r=0;r<n;r++) {
				for (int c=n-1;c>=0;c--) {
					if (board[r][c] != 0) {
						q.push(board[r][c]);
						board[r][c] = 0;
					}
				}
				int idx = n-1;
				while (!q.empty()) {
					int block = q.front();
					q.pop();
					
					if (board[r][idx] == 0)
						board[r][idx] = block;
					else if (board[r][idx] == block) {
						board[r][idx] *= 2;
						idx--;
					} else {
						board[r][--idx] = block;
					}
				}
			}
			break;
	}
}

int findMax()
{
	int m = -987654321;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (m<board[i][j]) m = board[i][j];
		}
	}
	return m;
}
void dfs(int depth)
{
	//최대 5번 이동
	//상하좌우 네 방향 이동
	//5번째에 답 return
	//목적지인가?
	if (depth==5) {
		ans = max(ans, findMax());
		return;
	}

	int tmp_board[25][25];
	//체크인
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			tmp_board[i][j] = board[i][j];
		}
	}
	//주변 탐색
	for (int d=0;d<4;d++) {
		//사방탐색 갈 수 있는가? -> 완전탐색
		go(d);
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
			ans = max(ans, board[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}