#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[110][110];
int r,c,k;
int nrow, ncol; //row 최댓값, col 최댓값
int second;
bool isPossible = true;

int returnMax (const int& o1, const int& o2)
{
	if (o1 < o2) return o2;
	else return o1;
}
bool cmp(const pair<int,int>& o1, const pair<int,int>& o2)
{
	if (o1.second != o2.second)
		return o1.second < o2.second;
	else
		return o1.first < o2.first;
}

bool desc(int a, int b)
{
	return a>b;
}

void Rf()
{
	for (int x=1;x<=nrow;x++) {
		//printf("\n%dth row\n",x);
		sort(A[x]+1, A[x]+ncol+1, desc);
		/*
		printf("after sort\n");
		for (int i=1;i<=nrow;i++) {
			for (int j=1;j<=ncol;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		*/
		vector< pair<int,int> > pairs;
		int num=A[x][1], numofnum=0;
		for (int i=1;i<=ncol;i++) {
			if (A[x][i] == 0) break;
			if (A[x][i] != num) {
				pairs.push_back(make_pair(num, numofnum));
				num = A[x][i];
				numofnum = 1;
			}
			else numofnum++;
		}
		pairs.push_back(make_pair(num, numofnum));
		/*
		for (int i=0;i<pairs.size();i++) {
			printf("(%d,%d) ", pairs[i].first, pairs[i].second);
		}
		printf("\n");
		*/

		sort(pairs.begin(), pairs.end(), cmp);
		/*
		for (int i=0;i<pairs.size();i++) {
			printf("(%d,%d) ", pairs[i].first, pairs[i].second);
		}
		printf("\n");
		*/
		for (int i=1;i<=ncol;i++) {
			A[x][i] = 0;
		}

		ncol = returnMax(ncol, pairs.size() * 2);
		//printf("ncol: %d\n", ncol);

		for (int i=1;i<=pairs.size();i++) {
			//printf("%d: %d, %d: %d\n", i*2-1, pairs[i].first i*2);
			if (i==51)
				break;
			A[x][i*2-1] = pairs[i-1].first;
			A[x][i*2] = pairs[i-1].second;
		}
	}
}

void Cf()
{
	for (int y=1;y<=ncol;y++) {
		int tmpCol[nrow+1];
		for (int j=1;j<=nrow;j++) {
			tmpCol[j] = A[j][y];
		}
		/*
		printf("%dth col\n", y);
		for (int j=1;j<=nrow;j++) {
			printf("%d ", tmpCol[j]);
		}
		printf("\n");
		*/
		sort(tmpCol+1, tmpCol+nrow+1, desc);
		/*
		printf("after sort\n");
		for (int i=1;i<=nrow;i++) {
			printf("%d ", tmpCol[i]);
		}
		*/
		vector< pair<int,int> > pairs;
		int num = tmpCol[1], numofnum = 0;
		for (int j=1;j<=nrow;j++) {
			if (tmpCol[j] == 0) break;
			if (tmpCol[j] != num) {
				pairs.push_back(make_pair(num, numofnum));
				num = tmpCol[j];
				numofnum = 1;
			} else {
				numofnum++;
			}
		}
		pairs.push_back(make_pair(num, numofnum));
		/*
		for (int i=0;i<pairs.size();i++) {
			printf("(%d,%d) ", pairs[i].first, pairs[i].second);
		}
		printf("\n");
		*/
		sort(pairs.begin(), pairs.end(), cmp);
		for (int i=1;i<=nrow;i++) {
			A[i][y] = 0;
		}
		nrow = returnMax(nrow, pairs.size()*2);

		for (int j=1;j<=pairs.size();j++) {
			if (j==51)
				break;
			A[j*2-1][y] = pairs[j-1].first;
			A[j*2][y] = pairs[j-1].second;
		}
	}
}

int main()
{
	scanf("%d%d%d", &r,&c,&k);

	for (int i=1;i<=3;i++) {
		for (int j=1;j<=3;j++) {
			scanf("%d",&A[i][j]);
		}
	}
	nrow = 3, ncol = 3; //초기화 
	
	//printf("*\n");
	
	while (A[r][c] != k) {
		if (second >= 101) {
			printf("-1\n");
			isPossible = false;
			break;
		}

		//nrow, ncol 비교
		if (nrow >= ncol) Rf();
		else Cf();
		/*
		for (int i=1;i<=nrow;i++) {
			for (int j=1;j<=ncol;j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}*/
		second++;
	}
	//Rf();
	/*
	printf("Rf\n");
	for (int i=1;i<=nrow;i++) {
		for (int j=1;j<=ncol;j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/
	//Cf();
	/*
	for (int i=1;i<=nrow;i++) {
		for (int j=1;j<=ncol;j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/
	if (isPossible)
		printf("%d\n", second);
	return 0;
}