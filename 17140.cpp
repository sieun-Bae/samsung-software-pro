#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c,k;
vector<int> A[110];

int nrow, ncol;
int second;
bool isPossible = true;

void Rf() //R연산
{
	for (int x=1;x<=nrow;x++) {
		sort(A[x].begin(), A[x].end);
		
	}
}

void Cf() //C연산
{

}

bool check()
{
	if (A[r].size() == 0) return false;
	if (A[r].size() <= (c-1)) return false;

	if (A[r][c-1] == k) return true;
	else return false;
}

int main()
{
	scanf("%d%d%d", &r,&c,&k);

	for (int i=1;i<=3;i++) {
		for (int j=0;j<3;j++) {
			int tmp;
			scanf("%d",&tmp);
			A[i].push_back(tmp);
		}
	}
	nrow = 3, ncol = 3; //초기화 
	
	while (true) {
		if (second >= 101) {
			printf("-1\n");
			isPossible = false;
			break;
		}
		//check
		if (check()) {
			break;
		}
		//nrow, ncol 비교
		if (nrow >= ncol) Rf();
		else Cf();
	}

	if (isPossible)
		printf("%d\n", second);
	return 0;
	
}