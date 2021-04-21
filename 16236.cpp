#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info {
	int x,y;
	int size;
	info(int xx, int yy, int ss) {
		x = xx;
		y = yy;
		size = ss;
	}
	info() {}
} info;

int n;
int map[21][21];
int answer;

vector<info> fishes;
int fish_num;
info shark;

int main()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]==9) { //상어 좌표 저장
				shark = info(i, j, 2);
				continue;
			}
			if (map[i][j]) { //물고기 크기, 좌표 저장
				fishes.push_back(info(i,j,map[i][j]));
			}
		}
	}
	fish_num = fishes.size();

	if (fish_num==0) {
		printf("0\n");
		return 0;
	}
	
	while(fish_num) {

	}

	printf("%d\n", answer);

	return 0;
}