//시험 감독
//수학

#include <iostream>
using namespace std;
#define MAX 1000010
typedef long long ll;

int N, B, C;
int A[MAX];
ll answer;

int main()
{
	scanf("%d", &N);
	for (int i=0;i<N;i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);
	for (int i=0;i<N;i++) {
		if (B>=A[i]){
			answer += 1;
			continue;
		}

		int temp = (A[i]-B)%C;
		if (temp == 0)
			answer += ((A[i]-B)/C + 1);
		else
			answer += ((A[i]-B)/C + 2);
	}
	printf("%lld", answer);
	return 0;
}