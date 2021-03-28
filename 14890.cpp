#include <iostream>
using namespace std;

int n,l, answer;
int roads[105][105];
bool flag;
bool gyongsaro[105][105];

int main()
{
	scanf("%d%d",&n,&l);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d",&roads[i][j]);
		}
	}
	//horizontal
	for (int i=0;i<n;i++) {
		for (int j=1;j<n;j++) {
			flag = true;
			if (roads[i][j] == roads[i][j-1]) continue;
			else if (roads[i][j] > roads[i][j-1]) {//높아지면
				if (roads[i][j] == (roads[i][j-1]+1) && !gyongsaro[i][j-1]) {
					int tmp = roads[i][j-1];
					int tmpgr[105][105];
					for (int p=0;p<n;p++) {
						for (int q=0;q<n;q++) {
							tmpgr[p][q] = gyongsaro[p][q];
						}
					}
					for (int r=j-1;j-l-1<r;r--) {
						if ((r<=0 && r != (j-l)) || gyongsaro[i][r]) { //경사로 둘 곳 부족하거나 경사로 겹치는 경우
							for (int p=0;p<n;p++) {
								for (int q=0;q<n;q++) {
									gyongsaro[p][q] = tmpgr[p][q];
								}
							}
							flag = false; 
							break;
						}
						if (tmp == roads[i][r] && !gyongsaro[i][r]) {
							gyongsaro[i][r] = true;
							continue;
						}
					}
				} else flag=false;
			} else {//낮아지면
				if (roads[i][j]+1 == roads[i][j-1] && !gyongsaro[i][j-1]) {
					int tmp = roads[i][j];
					int tmpgr[105][105];
					for (int p=0;p<n;p++) {
						for (int q=0;q<n;q++) {
							tmpgr[p][q] = gyongsaro[p][q];
						}
					}
					for (int r=j;r<j+l;r++) {
						if ((r>=n && r != j+l-1) || gyongsaro[i][r]) {
							for (int p=0;p<n;p++) {
								for (int q=0;q<n;q++) {
									gyongsaro[p][q] = tmpgr[p][q];
								}
							}
							flag = false; 
							break;
						}
						if (tmp == roads[i][r] && !gyongsaro[i][r]) {
							gyongsaro[i][r] = true;
							continue;
						}
					}
				} else flag=false;
			}
		}
		if (flag) answer++;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			gyongsaro[i][j] = 0;
		}
	}/*
	for (int j=0;j<n;j++) {
		for (int i=1;i<n;i++) {
			flag = true;
			if (roads[i][j] == roads[i][j-1]) continue;
			else if (roads[i][j] > roads[i][j-1]) {//높아지면
				if (roads[i][j] == (roads[i][j-1]+1) && !gyongsaro[i][j-1]) {
					int tmp = roads[i][j-1];
					int tmpgr[105][105];
					for (int p=0;p<n;p++) {
						for (int q=0;q<n;q++) {
							tmpgr[p][q] = gyongsaro[p][q];
						}
					}
					for (int r=j-1;j-l-1<r;r--) {
						if ((r<=0 && r != (j-l)) || gyongsaro[i][r]) { //경사로 둘 곳 부족하거나 경사로 겹치는 경우
							for (int p=0;p<n;p++) {
								for (int q=0;q<n;q++) {
									gyongsaro[p][q] = tmpgr[p][q];
								}
							}
							flag = false; 
							break;
						}
						if (tmp == roads[i][r] && !gyongsaro[i][r]) {
							gyongsaro[i][r] = true;
							continue;
						}
					}
				} else flag=false;
			} else {//낮아지면
				if (roads[i][j]+1 == roads[i][j-1] && !gyongsaro[i][j-1]) {
					int tmp = roads[i][j];
					int tmpgr[105][105];
					for (int p=0;p<n;p++) {
						for (int q=0;q<n;q++) {
							tmpgr[p][q] = gyongsaro[p][q];
						}
					}
					for (int r=j;r<j+l;r++) {
						if ((r>=n && r != j+l-1) || gyongsaro[i][r]) {
							for (int p=0;p<n;p++) {
								for (int q=0;q<n;q++) {
									gyongsaro[p][q] = tmpgr[p][q];
								}
							}
							flag = false; 
							break;
						}
						if (tmp == roads[i][r] && !gyongsaro[i][r]) {
							gyongsaro[i][r] = true;
							continue;
						}
					}
				} else flag=false;
			}
		}
		if (flag) answer++;
	}*/
	printf("%d\n", answer);
	return 0;
}