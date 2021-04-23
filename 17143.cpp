#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct shark{
	int x,y;
	int s,d,z;
	shark(int xx, int yy, int ss, int dd, int zz) {
		x = xx;
		y = yy;
		s = ss;
		d = dd;
		z = zz;
	}
	shark() {}
}shark;
int r,c,m;
shark ocean[101][101];
int fisher;
int answer;
vector<shark> tmp[101][101];

bool cmp(const shark& o1, const shark& o2)
{
	return o1.z > o2.z;
}
void movef(shark sh)
{
	int x = sh.x;
	int y = sh.y;
	int d = sh.d;
	int s = sh.s;
	int z = sh.z;
	int speed = sh.s;

	while (true)
	{
		//s는 이동해야할 남은 칸 수
		if (s == 0) {
			break;
		}

		if (d == 1) { //위
			if (s >= (x-1)) {
				s-=(x-1);
				x=1;
				d=2;
			} else {
				x-=s;
				s=0;
			}
		} else if (d == 2) { //아래
			if (s >= (r-x)) {
				s-=(r-x);
				x=r;
				d=1;
			} else {
				x+=s;
				s=0;
			}
		} else if (d == 3) { //오른쪽
			if (s >= (c-y)) {
				s-=(c-y);
				y=c;
				d=4;
			} else {
				y+=s;
				s=0;
			}
		} else if (d == 4) { //왼쪽
			if (s >= (y-1)) {
				s-=(y-1);
				y=1;
				d=3;
			} else {
				y-=s;
				s=0;
			}
		}
	}
	tmp[x][y].push_back(shark(x,y,speed,d,z));
}

void move()
{
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			tmp[i][j].clear();
		}
	}
	//우선 상어 이동시켜봄
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if (ocean[i][j].z != -1) { //상어 있으면
				movef(ocean[i][j]);
			}
		}
	}
	//2마리 이상인 칸이 있으면 크기가 가장 큰 상어 제외 모두 삭제
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if (tmp[i][j].size() >= 2) {
				sort(tmp[i][j].begin(), tmp[i][j].end(), cmp);
				//shark biggest = tmp[i][j][0];
				//tmp[i][j].clear();
				//tmp[i][j].push_back(biggest);
			}
		}
	}
	//원래 ocean에 저장해줌 
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if (tmp[i][j].size()>=1) {
				ocean[i][j] = tmp[i][j][0];
			} else {
				ocean[i][j] = shark(i,j,-1,-1,-1);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &r,&c,&m);
	//ocean 초기화
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			ocean[i][j] = shark(i,j,-1,-1,-1);
		}
	}
	if (m==0) {
		printf("0\n");
		return 0;
	}
	//상어 저장
	for (int i=0;i<m;i++) {
		int xx,yy,ss,dd,zz;
		scanf("%d%d%d%d%d", &xx,&yy,&ss,&dd,&zz);
		ocean[xx][yy] = shark(xx,yy,ss,dd,zz);
	}

	for (int i=0;i<c;i++) {
		
		//1. 낚시왕 오른쪽으로 한칸 이동
		fisher++;
		//2. 낚시왕이 있는 열에 있는 상어 중 땅과 제일 가까운 상어 잡음
		for (int f=1;f<=r;f++) {
			if (ocean[f][fisher].z != -1) { //상어 있으면
				answer += ocean[f][fisher].z; //잡은 상어 크기만큼 ++
				ocean[f][fisher] = shark(f,fisher,-1,-1,-1); //상어 잡았으니 초기화
				break;
			}
		}

		//3. 상어 이동
		move();
		
	}
	printf("%d\n", answer);
	return 0;
}