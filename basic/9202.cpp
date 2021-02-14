#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int w;
vector<string> dic;
char board[5][5];
bool visited[5][5];
bool found[300010];

int dx[8] = {1,0,0,-1,-1,1,1,-1};
int dy[8] = {0,1,-1,0,-1,1,-1,1};
int score[9] = {0,0,0,1,1,2,3,5,11};

int max_score;
int max_len;
int max_idx;
int word_cnt;
void dfs(int word, int idx, int cur_x, int cur_y)
{
	//체크인
	visited[cur_x][cur_y] = true;
	//목적지인가?
	if (dic[word].length()==idx && found[word] != true) { //end이고 found 아니면
		found[word] = true;
		max_score += score[idx];
		if (idx > max_len) {
			max_len = idx;
			max_idx = word;
		}
		word_cnt++;
	} else {
		//갈 수 있는곳 탐색
		for (int k=0;k<8;k++) {
			int nxt_x = cur_x + dx[k];
			int nxt_y = cur_y + dy[k];
			//갈수있는가?
			if (nxt_x >= 0 && nxt_x < 4 && nxt_y >= 0 && nxt_y < 4) {
				if (!visited[nxt_x][nxt_y] && board[nxt_x][nxt_y] == dic[word][idx]) {
					//간다
					dfs(word, idx+1, nxt_x, nxt_y);
				}
			} 
		}
	}
	//체크아웃
	visited[cur_x][cur_y] = 0;
}

int main()
{
	//입력, board 만들기
	scanf("%d", &w);
	string tmp="";
	getline(cin, tmp);
	for (int i=0;i<w;i++) {
		getline(cin, tmp);
		dic.push_back(tmp);
	}

	sort(dic.begin(), dic.end());
	getline(cin, tmp);

	int b;
	scanf("%d", &b);
	while(b--) {
		getline(cin, tmp);
		for (int i=0;i<4;i++) {
			getline(cin,tmp);
			for(int j=0;j<4;j++) board[i][j] = tmp[j];
		}
		//초기화
		for (int i=0;i<w;i++) found[i] = false;
		max_score=0;
		max_len=-1;
		max_idx=0;
		word_cnt=0;

		for (int t=0;t<w;t++) {
			for (int i=0;i<4;i++) {
				for (int j=0;j<4;j++) {
					if (board[i][j] == dic[t][0] && found[t] == false) {
						dfs(t, 1, i, j);
					}
				}
			}
		}

		cout << max_score << " " << dic[max_idx] << " " << word_cnt << "\n";
	}
	return 0;
}