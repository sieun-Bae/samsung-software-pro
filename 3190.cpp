#include <iostream>
using namespace std;

int n,k,l;
bool board[101][101];
int main()
{
	scanf("%d%d", &n, &k);
	int x,y;
	for (int i=0;i<k;i++) {
		scanf("%d%d", &x, &y);
		board[x][y] = true;
	}
	scanf("%d%d", &n, &k);
	
	//배열에 방향전환을 각 초에 저장해놓고
	//방향전환할때 좌표 


	return 0;
}