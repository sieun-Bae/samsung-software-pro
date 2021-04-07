#include <iostream>
#include <vector>
using namespace std;

typedef struct info {
	//어떤 상어가
	int idx;
	//어디에
	int x,y;
	//어떤 방향으로
	int dir;
	//존재하는가
	bool exist;
	info (int ii, int xx, int yy) {
		idx = ii;
		x = xx;
		y = yy;
		exist = true;
	}
	info () {}
}Info;

typedef struct smell{
	//상어가 존재하는가 - 실시간 상어위치 
	int shark;
	//어떤 상어의 냄새가
	int idx;
	//얼마나 남았나
	int t;
	smell (int ee, int ii, int tt) {
		shark = ee;
		idx = ii;
		t = tt;
	}
	smell (int ee) {
		shark = ee;
	}
	smell () {}
}smell;

int n,m,k;
//냄새 저장용
smell ocean[25][25];
//각 상어의 방향 탐지를 위한 정보 저장용
info shark[410];
int shark_num;
int second;
int priority[410][5][5]; //[i][j][k] i번 상어의 j방향에서 우선순위 k

//0번지는 공란, 1:위, 2:아래, 3:왼쪽, 4:오른쪽 
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1}; 

bool possible = true;
void log()
{
	printf("%d\n", second);
	printf("shark, idx, t\n");
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("(%d, %d, %d) ", ocean[i][j].shark, ocean[i][j].idx, ocean[i][j].t);
		}
		printf("\n");
	}

	printf("shark\n");
	for (int s=1;s<=m;s++) {
		printf("idx: %d x,y: %d,%d dir: %d\n", shark[s].idx, shark[s].x, shark[s].y, shark[s].dir); 
	}
}
void solve()
{
	//1번 상어만 남을 때까지 반복
	
	//int tmp = 3;
	//while (tmp--)
	while (shark_num != 1)
	{
		second++;
		//만약 1000초 이상 -> -1 출력, break
		if (second >= 1001) {
			printf("-1\n");
			possible = false;
			break;
		}

		//냄새 뿌리기
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (ocean[i][j].shark) {
					ocean[i][j].idx = ocean[i][j].shark;
					ocean[i][j].t = k;
				}
			}
		}

		//방향 잡기 (이동 가능한 곳)
		for (int s=1;s<=m;s++) {
			//아무 냄새 없는 칸의 방향 우선
				//없으면 자신의 냄새가 있는 방향
			//너무 많으면 지금 방향에서의 우선순위
			vector<int> possibleWay;
			if (shark[s].exist) {
				int cx = shark[s].x;
				int cy = shark[s].y;
				int dir = shark[s].dir;

				for (int d=1;d<=4;d++) {
					int nx = cx+dx[d];
					int ny = cy+dy[d];

					if (nx<=-1 || nx>=n || ny<=-1 || ny>=n)
						continue;
					if (ocean[nx][ny].idx == 0) { //아무냄새없는칸
						possibleWay.push_back(d);
					}
				}
/*
				printf("possibleway\nidx %d dir %d\n",s,dir);
				for (int q=0;q<possibleWay.size();q++) {
					printf("%d ", possibleWay[q]);
				}
				printf("\n");
*/
				if (possibleWay.size()==0) {
					for (int i=1;i<=4;i++) {
						int p = priority[s][dir][i];
						int nx = cx+dx[p];
						int ny = cy+dy[p];
						if (ocean[nx][ny].idx == s) {
							shark[s].dir = p;
							break;
						}
					}
					//shark[s].dir = (dir%2==0)?(dir-1):(dir+1);
					//shark[s].dir = ((dir+2) == 4)?4:(dir+2)%4;
				} else { //갈 수 있는 방향이 여러개
					bool flag = false;
					for (int i=1;i<=4;i++) {
						//printf("prio: %d\n", priority[s][dir][i]);
						for (int j=0;j<possibleWay.size();j++) {
							//printf("poss: %d\n", possibleWay[j]);
							if (priority[s][dir][i] == possibleWay[j]) {
								//printf("selected poss: %d\n", possibleWay[j]);
								shark[s].dir = priority[s][dir][i];
								flag=true;
								break;
							}
						}
						if (flag) break;
					}
				}
				/*else if (possibleWay.size()==1) {
					shark[s].dir = possibleWay[0];
				} */
			}
		}
		//log();
		//현재 남은 냄새 --
		
		//이동 
		for (int s=1;s<=m;s++) {
			if (shark[s].exist) {
				int dir = shark[s].dir;
				int cx = shark[s].x;
				int cy = shark[s].y;
				int nx = cx+dx[dir];
				int ny = cy+dy[dir];
				int nn = ocean[nx][ny].shark;
				if (nn) {
					shark[s].exist = false;
					shark_num--;
					ocean[cx][cy].shark = 0;
					continue;
					/*
					if (nn>s) { //현재 상어가 같은 자리로 이동한 상어보다 강하면
						shark[nn].exist = false;
						shark[s].x = nx;
						shark[s].y = ny;
						ocean[nx][ny].shark = s;
						ocean[cx][cy].shark = 0;
					} else {
						shark[s].exist = false;
					}
					shark_num--;
				} else {
					ocean[nx][ny].shark = s;
					ocean[cx][cy].shark = 0;
					shark[s].x = nx;
					shark[s].y = ny;
				}*/

				}
				ocean[nx][ny].shark = s;
				ocean[cx][cy].shark = 0;
				shark[s].x = nx;
				shark[s].y = ny;
			}
		}
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				//냄새 - 1
				if (ocean[i][j].idx) {
					ocean[i][j].t -= 1;
				}
				//냄새 0이 되면 냄새 존재하지 않음
				if (ocean[i][j].t == 0) {
					ocean[i][j].idx = 0;
				}
			}
		}
		//log();
	}
	if (possible)
		printf("%d\n", second);

	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	shark_num = m;

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int tmp;
			scanf("%d",&tmp);
			if (tmp) {
				shark[tmp] = info(tmp,i,j);
				ocean[i][j] = smell(tmp);
			}
		}
	}
	for (int i=1;i<=m;i++) {
		scanf("%d", &shark[i].dir);
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=4;j++) {
			for (int k=1;k<=4;k++) {
				scanf("%d",&priority[i][j][k]);
			}
		}
	}
	//printf("*\n");
	solve();
	//printf("*\n");
	return 0;
}