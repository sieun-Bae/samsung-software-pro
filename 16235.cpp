#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[11][11]; //겨울에 주는 양분 정보
int map[11][11]; //현재 땅의 양분 정보
vector<int> tree[110]; //나무 나이로 각 좌표에 있는 나무 저장

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,1,-1,-1};
int n,m,k;


void solution()
{
	vector<int> dead_tree[110];
	for (int i=1;i<=(n*n);i++) {
		sort(tree[i].begin(), tree[i].end()); //나이 오름차순 정렬
		int r=1;
		int c=1;
		if (n!=1) {
			r = i/n+1;
			c = i%n;
		}
		int j=0;
		for (j=0; j<tree[i].size(); j++) {
			if (tree[i][j] <= map[r][c]) { //양분을 먹을 수 있으면
				map[r][c] -= tree[i][j];
				tree[i][j] += 1;
			} else //양분 못먹는 나무 순서라면
				break;
		}
		//죽은 나무 벡터에 추가
		int d = (tree[i].size() - j);
		while (d--) {
			dead_tree[i].push_back(tree[i].back());
			tree[i].pop_back();
		}
	}
	for (int i=1;i<=(n*n);i++) {
		int r=1;
		int c=1;
		if (n!=1) {
			r = i/n+1;
			c = i%n;
		}
		for (int j=0;j<dead_tree[i].size();j++) {
			map[r][c] += dead_tree[i][j]/2;
		}
	}
	for (int i=1;i<=(n*n);i++) {
		int r=1;
		int c=1;
		if (n!=1) {
			r = i/n+1;
			c = i%n;
		}
		for (int j=0;j<tree[i].size();j++) {
			if (tree[i][j]%5 == 0) {
				for (int d=0;d<8;d++) {
					int nx = r+dx[d];
					int ny = c+dy[d];
					int p = n*(nx-1)+ny;
					if (1<=nx&&nx<=n&&1<=ny&&ny<=n) tree[p].push_back(1);
					else continue;
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			map[i][j] += A[i][j];
		}
	}
} 

int main()
{
	scanf("%d%d%d", &n,&m,&k);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}
	for (int i=0;i<m;i++) {
		int x,y,z;
		scanf("%d%d%d", &x,&y,&z);
		int p = (x-1)*n + y;
		tree[p].push_back(z);
	}
	for (int i=0;i<k;i++) {
		solution();
	}
	int ans=0;
	for (int i=1;i<=(n*n);i++) {
		ans += tree[i].size();
	}
	printf("%d\n", ans);
	return 0;
}