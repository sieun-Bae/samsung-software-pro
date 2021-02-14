//union find
#include <iostream>
using namespace std;

int n, m, pr[1000010];

int findf(int a) 
{
	if (pr[a]==a) return a;
	pr[a] = findf(pr[a]);
	return pr[a];
}
void unionf(int a, int b)
{
	a = findf(a);
	b = findf(b);
	pr[a] = b;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0;i<=n;i++) {
		pr[i] = i;
	}
	for (int i=0;i<m;i++) {
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 0) {
			unionf(a,b);
		} else if (cmd == 1) {
			if (findf(a) == findf(b)) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
	}
	return 0;
}