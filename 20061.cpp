#include <iostream>
using namespace std;

int green[6][4];
int blue[4][6];
int n, t, x, y;
int score, block;

void move()
{
	//move
	if (t==1) {
		//t=1: 1*1 (x,y)
		//green
		int i=0, j=0;
		for (i=0;i<6;i++) {
			if (green[i][y] != 0) {
				break;
			}
		}
		green[i-1][y] = 1;
		for (j=0;j<6;j++) {
			if (blue[x][j] != 0) {
				break;
			}
		}
		blue[x][j-1] = 1;
	} else if (t==2) {
		//t=2: 1*2 (x,y) (x,y+1)
		int i=0, j=0;
		for (i=0;i<6;i++) {
			if (green[i][y] != 0 || green[i][y+1] != 0){
				break;
			}
		}
		green[i-1][y] = 1;
		green[i-1][y+1] = 1;
		for (j=1;j<6;j++) {
			if (blue[x][j] != 0) {
				break;
			}
		}
		blue[x][j-1] = 1;
		blue[x][j-2] = 1;
	} else if (t==3) {
		//t=3: 2*1 (x,y) (x+1,y)
		int i=0, j=0;
		for (i=1;i<6;i++) {
			if (green[i][y] != 0){
				break;
			}
		}
		green[i-1][y] = 1;
		green[i-2][y] = 1;
		for (j=0;j<6;j++) {
			if (blue[x][j] != 0 || blue[x+1][j] != 0) {
				break;
			}
		}
		blue[x][j-1] = 1;
		blue[x+1][j-1] = 1;
	}
	//꽉찬 칸 삭제
	int s=6;
	while(s--) {
		//printf("score: %d\n", score);
		for (int i=5;i>0;i--) {
			bool flag1=true, flag2=true;
			for (int j=0;j<4;j++) {
				if (green[i][j] == 0) flag1 = false;
				if (blue[j][i] == 0) flag2 = false;
			}
			if (flag1) {
				score++;
				for (int j=0;j<4;j++) 
					green[i][j] = 0;
				for (int j=i;j>0;j--) {
					for (int k=0;k<4;k++) 
						green[j][k] = green[j-1][k];
				} 
			}
			if (flag2) {
				score++;
				for (int j=0;j<4;j++) {
					blue[j][i] = 0;
				}
				for (int j=i;j>0;j--) {
					for (int k=0;k<4;k++) 
						blue[k][j] = blue[k][j-1];
				}
			}
		}
	}
	
}

void scan()
{
	bool flag1=false, flag2=false, flag3=false, flag4=false;
	for (int i=0;i<4;i++) {
		if (green[0][i]) flag1 = true;
		if (green[1][i]) flag2 = true;
		if (blue[i][0]) flag3 = true;
		if (blue[i][1]) flag4 = true;
	}
	//green
	for (int s=0;s<(flag1+flag2);s++) {
		for (int i=5;i>0;i--) {
			for (int j=0;j<4;j++) {
				green[i][j] = green[i-1][j];
			}
		}
		for (int j=0;j<4;j++)
				green[0][j] = 0;
	}
	//blue
	for (int s=0;s<(flag3+flag4);s++) {
		for (int i=5;i>0;i--) {
			for (int j=0;j<4;j++) {
				blue[j][i] = blue[j][i-1];
			}
		}
		for (int j=0;j<4;j++)
				blue[j][0] = 0;
	}
}

void log()
{
	printf("green..\n");
	for (int i=0;i<6;i++) {
		for (int j=0;j<4;j++) {
			printf("%d ", green[i][j]);
		}
		printf("\n");
	}
	printf("blue..\n");
	for (int i=0;i<4;i++) {
		for (int j=0;j<6;j++) {
			printf("%d ", blue[i][j]);
		}
		printf("\n");
	}
}

int main()
{	
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&t,&x,&y);
		//printf("\nnew block.. type: %d coor: %d, %d\n", t,x,y);
		//이동 + 가득찬 행이나 열 삭제
		//printf("move\n");
		move();
		//log();
		//연한칸에 블록이 있는 경우 처리
		//printf("scan\n");
		scan();
		//log();
	}
	//출력
	printf("%d\n", score);
	for (int i=0;i<4;i++) {
		for (int j=0;j<6;j++) {
			if (green[j][i]) block++;
			if (blue[i][j]) block++;
		}
	}
	printf("%d\n", block);
	return 0;
}