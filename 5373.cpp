#include <iostream>
using namespace std;

int t,n;
char which,dir;

void funct()
{
	switch(which){
		case 'U':
			
			break;
		case 'D':
		case 'F':
		case 'B':
		case 'L':
		case 'R':
	}
}

int main()
{
	scanf("%d",&t);
	for (int tc=0;tc<t;tc++) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%c%c",&which,&dir);
			funct();
		}
	}
	return 0;
}