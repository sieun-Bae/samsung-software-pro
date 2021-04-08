#include <iostream>
#include <vector>
using namespace std;

int r,c,k;
vector<int> A[110];

int nrow, ncol;

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
	
	//check
	check();
	//nrow, ncol 비교
	//연산

	
	return 0;
}