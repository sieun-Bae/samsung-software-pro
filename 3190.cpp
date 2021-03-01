#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n,k,l;
int second=0;
int board[101][101]; //2: 뱀, 0: 빈칸, 1: 사과
int dx[4] = {0,-1,0,1}; //오, 위, 왼, 아래
int dy[4] = {1,0,-1,0};

deque< pair<int,int> > dq;//front: head, back: tail
vector< pair<int,char> > v;//<초, 방향>

void solution()
{
	int x=1, y=1, go=0, cnt=0;
	dq.push_back(make_pair(x,y));
	board[x][y] = 2;

	while(1)
	{
		second++;
		int nx = x+dx[go];
		int ny = y+dy[go];

		if (nx<1 || nx>=(n+1) || ny<1 || ny>=(n+1) || board[nx][ny] == 2) return; //벽이거나 이동한 곳이 뱀이면
		else if (board[nx][ny] == 0) { //이동하는 곳이 빈칸이면
			board[nx][ny] = 2;
			dq.push_front(make_pair(nx, ny));
			board[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		} else if (board[nx][ny] == 1) { //이동하는 곳이 사과라면
			board[nx][ny] = 2;
			dq.push_front(make_pair(nx, ny));
		}

		if (cnt < v.size()) {
			if (second == v[cnt].first) {
				if (v[cnt].second == 'L') go = (go+1)%4;
				else if (v[cnt].second == 'D') go = (go+3)%4;
				cnt++;
			}
		}
		x = nx;
		y = ny;
	}

}
int main()
{
	scanf("%d%d", &n, &k);
	int x,y;
	for (int i=1;i<=k;i++) {
		scanf("%d%d", &x, &y);
		board[x][y] = 1; //사과 표시
	}

	scanf("%d", &l);
	for (int i=1;i<=l;i++) {
		int tmp=0;
		char c;
		cin>>tmp>>c;
		v.push_back(make_pair(tmp, c));
	}	
	
	solution();
	//이동방향으로 전진 -> head front push
	//if apple -> board 뱀 표시
	//else -> board 뱀 표시, tail pop
	printf("%d\n", second);

	return 0;
}