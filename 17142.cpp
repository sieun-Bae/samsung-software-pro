//https://jaimemin.tistory.com/1203
#include <iostream>
#include <vector>
#include <queue>
#define INF 98765
using namespace std;

int cnt;
int n,m;
int board[55][55];
int tmp_board[55][55];
vector< pair<int,int> > viruses;
int answer = INF;
int virus;
bool chosen[11];
bool visited[55][55];

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

void bfs(pair<int, int> start_point)
{
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			visited[i][j] = false;
		}
	}
	//완전탐색
	queue < pair<int,int> > q;
	q.push(start_point);
	//int cnt = 1;
	tmp_board[start_point.first][start_point.second] = 0; //활성화
	visited[start_point.first][start_point.second] = true;
	
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		//printf("cx: %d cy: %d\n", cx, cy);
		
		q.pop();

		//사방 탐색
		for (int i=0;i<4;i++) {
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			//printf("nx: %d ny: %d\n", nx, ny);
			if (0<=nx && nx<=(n-1) && 0<=ny && ny<=(n-1) && !visited[nx][ny]) { //지도 범위 넘어가지 않고
				if (tmp_board[nx][ny] != '-' && tmp_board[nx][ny] != '*') { //벽과 바이러스 아니면
					tmp_board[nx][ny] = min(tmp_board[cx][cy]+1, tmp_board[nx][ny]);
					q.push(make_pair(nx,ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
	/*
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d ", tmp_board[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
}

//idx: 현재 보고 있는 원소 인덱스, cnt: 선택한 원소 갯수
void comb(int idx, int cnt)
{
	if (cnt > m) {
		/*printf("%d\n", cnt);
		for (int k=0;k<virus;k++) {
			printf("%d ", chosen[k]);
		}
		printf("\n");*/
		for (int i=0;i<virus;i++) {
			if (chosen[i] == true) {
				//printf("%d\n", i+1);
				//printf("(%d, %d) ",viruses[i].first, viruses[i].second);
				//printf("***\n");
				bfs(viruses[i]);
			}
		}
		//board 탐색, 최댓값이 tmp_answer
		int tmp_answer = -1;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (tmp_board[i][j] == INF) { //불가능 구역 존재
					tmp_answer = -1;
					break;
				}
				if (tmp_board[i][j] == 0 || tmp_board[i][j] == '*' || tmp_board[i][j] == '-') continue;
				tmp_answer = max(tmp_board[i][j], tmp_answer);
			}
		}
		//answer 갱신
		if (tmp_answer != -1) 
			answer = min(answer, tmp_answer);

		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++) {
				tmp_board[i][j] = board[i][j]; //복원
			}
		}
		//printf("answer: %d\n", answer);
		return;
	}
	if (idx == virus) return;

	chosen[idx] = true;
	comb(idx+1, cnt+1);
	chosen[idx] = false;
	comb(idx+1, cnt);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 2) { //비활성바이러스
				viruses.push_back(make_pair(i,j));
				board[i][j] = '*';
				tmp_board[i][j] = '*';
			} else if (tmp == 1) { //벽
				board[i][j] = '-';
				tmp_board[i][j] = '-';
			} else { //빈칸
				cnt++;
				board[i][j] = INF; //빈칸
				tmp_board[i][j] = INF;
			}
		}
	}

	//탐색하지않아도 되는 경우
	bool flag = false;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (board[i][j] == INF)  {
				flag = true;
				break;
			}
		}
	}
	if (flag) {
		//viruses.size() 중 m개 조합으로 탐색 virus C m
		virus = viruses.size();
		//printf("virus size: %d\n", virus);
		comb(0,1);

		if (answer == INF) printf("-1\n");
		else printf("%d\n", answer);
	} else {
		printf("0\n");
	}

	return 0;
}