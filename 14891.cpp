#include <iostream>
using namespace std;

int tnbq[4][8], k; //tnbq[i][0] == 12시 방향

void turnf(int n, int d)
{
	if (d==1) {
		int tmp = tnbq[n][7];
		for (int i=7;i>=1;i--) {
			tnbq[n][i] = tnbq[n][i-1];
		}
		tnbq[n][0] = tmp;
	} else if (d==-1) {
		int tmp = tnbq[n][0];
		for (int i=0;i<7;i++) {
			tnbq[n][i] = tnbq[n][i+1];
		}
		tnbq[n][7] = tmp;
	}
}
void funcf(int n, int d)
{
	if (n==1){
		if (tnbq[0][2] != tnbq[1][6]) {
			if (tnbq[1][2] != tnbq[2][6]) {
				if (tnbq[2][2] != tnbq[3][6]) {
					//4번 돌림
					turnf(3, -d);
				}
				//3번 돌림
				turnf(2, d);
			}
			//2번 돌림
			turnf(1, -d);
		}
		turnf(0, d);
	}else if (n==2) {
		if (tnbq[1][6] != tnbq[0][2]) {
			//1번 돌림
			turnf(0, -d);
		}
		if (tnbq[1][2] != tnbq[2][6]) {
			if (tnbq[2][2] != tnbq[3][6]) {
				//4번 돌림
				turnf(3, d);
			}
			//3번 돌림
			turnf(2, -d);
		}
		turnf(1,d);
	}else if (n==3) {
		if (tnbq[2][2] != tnbq[3][6]) {
			//4번 돌림
			turnf(3, -d);
		}
		if (tnbq[2][6] != tnbq[1][2]) {
			if (tnbq[1][6] != tnbq[0][2]) {
				//1번 돌림
				turnf(0, d);
			}
			//2번 돌림
			turnf(1, -d);
		}
		turnf(2, d);
	}else if (n==4) {
		if (tnbq[3][6] != tnbq[2][2]) {
			if (tnbq[2][6] != tnbq[1][2]) {
				if (tnbq[1][6] != tnbq[0][2]) {
					//1번 돌림
					turnf(0, -d);
				}
				//2번 돌림
				turnf(1, d);
			}
			//3번 돌림
			turnf(2, -d);
		}
		turnf(3, d);
	}
}

int main()
{
	//freopen("test.txt", "r",stdin);
	for (int i=0;i<4;i++) {
		for (int j=0;j<8;j++) {
			scanf("%1d", &tnbq[i][j]);
		}
	}
	
	scanf("%d", &k);
	for (int i=0;i<k;i++) {
		int num, dir;
		scanf("%d%d", &num, &dir);
		funcf(num, dir);
	}

	int total=0;
	if (tnbq[0][0] == 1) total += 1;
	if (tnbq[1][0] == 1) total += 2;
	if (tnbq[2][0] == 1) total += 4;
	if (tnbq[3][0] == 1) total += 8;
	printf("%d\n", total);

	return 0;
}