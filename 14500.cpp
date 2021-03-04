#include <iostream>
using namespace std;

int n,m;
int board[510][510];
int answer=0;

void tetrominoooo()
{
	int tmp=0,tmp2=0;
	// 1111
	
	for (int i=0;i<n;i++) {
		for (int j=0;j+3<m;j++) {
			tmp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
			answer = max(answer, tmp);
		}
	} //세로 1111

	for (int i=0;i+3<n;i++) {
		for (int j=0;j<m;j++) {
			tmp = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
			answer = max(answer, tmp);
		}
	}

}
void tetromino()
{
	int tmp=0,tmp2=0;
	// 1111
	
	for (int i=0;i<n;i++) {
		for (int j=0;j+3<m;j++) {
			tmp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
			answer = max(answer, tmp);
		}
	} //세로 1111

	for (int i=0;i+3<n;i++) {
		for (int j=0;j<m;j++) {
			tmp = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
			answer = max(answer, tmp);
		}
	}
	/*
	11
	11
	*/
	for (int i=0;i<n-1;i++) {
		for (int j=0;j<m-1;j++) {
			tmp = board[i][j]+board[i][j+1]+board[i+1][j]+board[i+1][j+1];	
			answer = max(tmp, answer);	
		}
	}
	/*
	1   1
	11 11
	 1 1
	*/

	for (int i=0;i+2<n;i++) {
		for (int j=0;j<m-1;j++) {
			tmp = board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+2][j+1];
			tmp2 = board[i][j+1]+board[i+1][j+1]+board[i+1][j]+board[i+2][j];
			answer = max(tmp,answer);
			answer = max(tmp2, answer);
		}
	}
	/*
	11   11
	 11 11  
	*/
	for (int i=0;i<n-1;i++) {
		for (int j=0;j+2<m;j++) {
			tmp = board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j+2];
			tmp2 = board[i+1][j]+board[i+1][j+1]+board[i][j+1]+board[i][j+2];
			answer = max(tmp, answer);
			answer = max(tmp2, answer);
		}
	}
	/*
	1  11 1  11  1  1
	1  1  11  1 11  1
	11 1  1   1  1 11
	*/
	for (int i=0;i+2<n;i++) {
		for (int j=0;j<m-1;j++) {
			tmp = board[i][j]+board[i+1][j]+board[i+2][j];
			tmp2 = board[i][j+1]+board[i+1][j+1]+board[i+2][j+1];
			for (int k=i;k<i+3;k++) {
				answer = max(tmp+board[k][j+1], answer);
				answer = max(tmp2+board[k][j], answer);
			}
		}
	}
	/*
	111 111 111 1    1    1
	1    1    1 111 111 111
	*/
	
	for (int i=0;i<n-1;i++) {
		for (int j=0;j+2<m;j++) {
			tmp = board[i][j]+board[i][j+1]+board[i][j+2];
			tmp2 = board[i+1][j]+board[i+1][j+1]+board[i+1][j+2];
			for (int k=j;k<j+3;k++) {
				answer = max(tmp+board[i+1][k], answer);
				answer = max(tmp2+board[i][k], answer);
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &board[i][j]);
		}
	}
	tetromino();
	printf("%d\n", answer);
	return 0;
}