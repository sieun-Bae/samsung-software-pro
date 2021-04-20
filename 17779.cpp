#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[21][21];
int label[21][21];
int answer = 987654321;

void calculate()
{
	int Sum[6] = {0,0,0,0,0};
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			Sum[ label[i][j] ] += A[i][j];
		}
	}
	sort(Sum, Sum+6);

	int diff = Sum[5]-Sum[1];
	answer = min(answer, diff);
	//printf("%d %d\n", diff, answer);
}
void func(int x, int y, int d1, int d2)
{
	//printf("x: %d y: %d d1: %d d2: %d\n",x,y,d1,d2);
	/*
	p0: (x, y)
	p1: (x+d1, y-d1)
	p2: (x+d2, y+d2);
	p3: (x+d1+d2, y-d1+d2)*/
	//printf("p1: (%d, %d) p2: (%d, %d) p3: (%d, %d) p4: (%d, %d)\n", x,y,x+d1,y-d1,x+d2,y+d2, x+d1+d2, y-d1+d2);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			label[i][j] = 5;
		}
	}
	
	int tmp=0;
	for (int i=1;i<x+d1;i++) {
		if (i>=x) tmp++;
		for (int j=1;j<=y-tmp;j++) {
			label[i][j] = 1;
		}
	}
	
	tmp=0;
	for (int i=1;i<=x+d2;i++) {
		if (i>x) tmp++;
		for (int j=y+1+tmp;j<=n;j++) {
			label[i][j] = 2;
		}
	}
	
	tmp=0;
	for (int i=n;i>=x+d1;i--) {
		if (i < x+d1+d2) tmp++;
		for (int j=1;j<y+d2-d1-tmp;j++) {
			label[i][j] = 3;
		}
	}
	
	tmp=0;
	for (int i=n;i>x+d2;i--) {
		if (i <= x+d1+d2) tmp++;
		for (int j=y-d1+d2+tmp;j<=n;j++) {
			label[i][j] = 4;
		}
	}
	
	calculate();
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%d", &A[i][j]);
		}
	}

	//시작점 x,y
	//func(3,3,1,1);
	for (int x=1;x<=n;x++) {
		for (int y=2;y<=n;y++) {
			//d1 + d2 <= n-2
			for (int d1=1;d1<=y;d1++) {
				/*
				p0: (x, y)
				p1: (x+d1, y-d1)
				p2: (x+d2, y+d2);
				p3: (x+d1+d2, y-d1+d2)*/
				for (int d2=1;d2<n-y;d2++) {
					if ((x+d1)>=(n+1) || (y-d1)<=0) continue;
					if ((x+d2)>=(n+1) || (y+d2)>=(n+1)) continue;
					if ((x+d1+d2)>=(n+1) || (y-d1+d2)>=(n+1)) continue;
					if ((x+d2+d1)>=(n+1) || (y+d2-d1)<=0) continue;
					//printf("(%d, %d) (%d, %d) (%d, %d)\n", x+d1, y-d1, x+d2, y+d2, x+d1+d2, y-d1+d2);
					//printf("x: %d y: %d d1: %d d2: %d\n", x, y, d1, d2);
					func(x, y, d1, d2);
				}

			}
	

		}
	}
	printf("%d\n", answer);
	return 0;
}