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

bool cmp(const pair<int, bool>& o1, const pair<int, bool>& o2)
{
	return o1.first < o2.first;
}

void log()
{
	printf("tree\n");
	for (int i=1;i<n*n;i++) {
		for (int j=0;j<tree[i].size();j++) {
			printf("%d: %d ", i, tree[i][j]);
		}
	}
	printf("\nmap\n");
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

void solution()
{
	vector<int> dead_tree[110];
	for (int i=1;i<=(n*n);i++) {
		vector< pair< int, bool> > trees; //<<인덱스, 나무나이>, 양분먹었는지여부>
	
		for (int j=0;j<tree[i].size();j++) {
			trees.push_back(make_pair(tree[i][j],false));
		}
		int r=1;
		int c=1;
		if (n!=1) {
			r = i/n+1;
			c = i%n;
		}
		if (trees.size() == 0) {
			continue;
		} else {
			while(true) {
				sort(trees.begin(), trees.end(), cmp); //나이 오름차순 정렬
				
				if (trees.front().first <= map[r][c]) { //양분을 먹을 수 있으면
					trees.front().second = true;
					map[r][c] -= trees.front().first;
					trees.front().first += 1;
				} else {
					break;
				}
			}
			//죽은 나무 벡터에 추가
			tree[i].clear();
			for (int j=0;j<trees.size();j++) {
				if (trees[j].second == true) {
					tree[i].push_back(trees[j].first);
				} else {
					dead_tree[i].push_back(trees[j].first);
				}
			}
		}
		
	}
	log();
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
	log();
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
	log();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			map[i][j] += A[i][j];
		}
	}
	log();
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
	//log();
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