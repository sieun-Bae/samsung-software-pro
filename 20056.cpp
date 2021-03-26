#include <iostream>
#include <vector>
using namespace std;

typedef struct fireball{
	int m,s,d; //(r,c) 질량 m, 방향 d, 속력 s
	fireball(int mm, int ss, int dd) {
		m = mm;
		s = ss;
		d = dd;
	}
}FB;

int n,m,k;
vector<FB> fireballs[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int a[4] = {0,2,4,6}; //모두 홀수거나 짝수
int b[4] = {1,3,5,7};
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) {
		int rr,cc,mm,ss,dd;
		scanf("%d%d%d%d%d",&rr,&cc,&mm,&ss,&dd);
		fireballs[rr-1][cc-1].push_back(FB(mm,ss,dd));
	}
	while (k--) {
		vector<FB> tmp[51][51];
		//printf("%d\n",k);
		//모든 파이어볼 이동 -> tmp에 저장
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				for (int t=0;t<fireballs[i][j].size();t++) {
					int ss = fireballs[i][j][t].s;
					int dd = fireballs[i][j][t].d;
					int mm = fireballs[i][j][t].m;
					int ii = i;
					int jj = j;
					//printf("ii: %d jj: %d ss: %d dd: %d mm: %d\n", ii,jj,ss,dd,mm);
					for (int S=0;S<ss;S++) {
						ii+=dx[dd];
						jj+=dy[dd];
					}
					while (ii<0 || jj<0 || ii>=n || jj>=n) {
						ii = (ii+n)%n;
						jj = (jj+n)%n;
					}
					//printf("ii: %d jj: %d ss: %d dd: %d mm: %d\n", ii,jj,ss,dd,mm);
					tmp[ii][jj].push_back(FB(mm, ss, dd));
				}
			}
		}
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				fireballs[i][j].clear();
				/*
				for (int t=0;t<tmp[i][j].size();t++) {
					printf("I:%d J:%d m:%d s:%d d:%d\n", i,j,tmp[i][j][t].m, tmp[i][j][t].s, tmp[i][j][t].d);
				}*/
			}
		}

		//각 위치에 파이어볼 2개 이상이면
		int mm=0, ss=0, dd;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (tmp[i][j].size() == 0) {
					continue;
				} else if (tmp[i][j].size() == 1) {
					fireballs[i][j].push_back(tmp[i][j][0]);
					continue;
				} else { //2개 이상
					mm=0, ss=0, dd=(tmp[i][j][0].d)%2;
					for (int t=0;t<tmp[i][j].size();t++) {
						mm += tmp[i][j][t].m;
						ss += tmp[i][j][t].s;
						if (dd != ((tmp[i][j][t].d)%2)) {
							dd = 2;
						}
					}
					//printf("mm: %d, size: %d, ss: %d\n", mm, int(tmp[i][j].size()),ss);
					//질량 0이면 파이어볼 삭제
					mm = int(mm/5);
					if (mm == 0) continue;

					int ssize = tmp[i][j].size();
					ss = int(ss/ssize);
					//printf("mm: %d, size: %d, ss: %d\n", mm, ssize, ss);
					if (dd==2) {
						for (int f=0;f<4;f++) {
							fireballs[i][j].push_back(FB(mm, ss, b[f]));
						}
					} else { //모두 홀수거나 짝수
						for (int f=0;f<4;f++) {
							fireballs[i][j].push_back(FB(mm, ss, a[f]));
						}
					}
				}
			}
		}
		/*
		printf("after\n");
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				for (int t=0;t<fireballs[i][j].size();t++) {
					printf("I:%d J:%d m:%d s:%d d:%d\n", i,j,fireballs[i][j][t].m, fireballs[i][j][t].s, fireballs[i][j][t].d);
					
				}
			}
		}*/
	}
	//남아있는 질량의 합
	int answer=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			for (int t=0;t<fireballs[i][j].size();t++) {
				//printf("I:%d J:%d m:%d s:%d d:%d\n", i,j,fireballs[i][j][t].m, fireballs[i][j][t].s, fireballs[i][j][t].d);
				answer += fireballs[i][j][t].m;
			}
		}
	}
	printf("%d\n", answer);
	
	return 0;
}