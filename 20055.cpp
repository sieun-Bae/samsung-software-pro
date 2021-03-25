#include <iostream>
#include <queue>
using namespace std;

int n,k;
int belt[210];
int visited[210];
queue<int> robot;
int s,e;
int answer=0, cnt=0;

int next(int co)
{
	co-=1;
	if (co==0) co=2*n;
	return co;
}
int N(int co)
{
	co+=1;
	if (co==(2*n+1)) co=1;
	return co;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=2*n;i++) {
		scanf("%d", &belt[i]);
	}
	s=1, e=n;
	while (true)
	{
		//4. 내구도 0인 칸의 갯수(cnt) >= k이면
		if (cnt >= k) break;
		answer++;

		//1. 벨트 한칸 회전
		s = next(s);
		e = next(e);

		
		//printf("\ns: %d e: %d\n",s,e);

		if (visited[e] == true) {
			visited[e] = false;
			robot.pop();
		}
		//2. 로봇 이동
		for (int i=0;i<robot.size();i++) {
			int cur = robot.front();

			robot.pop();
			int nxt = N(cur);
			//printf("cur: %d, nxt: %d\n", cur, nxt);
			if (visited[nxt] == false && belt[nxt] >= 1) {
				robot.push(nxt);
				visited[nxt] = true;
				visited[cur] = false;
				belt[nxt] -= 1;
				if (belt[nxt] == 0) cnt++;
			} else {
				robot.push(cur);
			}
		}
		if (visited[e] == true) {
			visited[e] = false;
			robot.pop();
		}/*
		for (int i=0;i<robot.size();i++) {
			int tmp = robot.front();
			printf("robot: %d ", tmp);

			robot.pop();
			robot.push(tmp);
		}
		printf("\n");
		for (int i=1;i<=2*n;i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");
		for (int i=1;i<=2*n;i++) {
			printf("%d ", belt[i]);
		}
		printf("\n");*/
		//3. 로봇 추가
		if (visited[s] == false && belt[s] >= 1) {
			//printf("add robot.. %d\n", s);
			robot.push(s);
			visited[s] = true;
			belt[s] -= 1;
			if (belt[s] == 0) cnt++;
		}/*
		for (int i=0;i<robot.size();i++) {
			int tmp = robot.front();
			printf("robot: %d ", tmp);

			robot.pop();
			robot.push(tmp);
		}
		
		printf("\n");
		for (int i=1;i<=2*n;i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");
		for (int i=1;i<=2*n;i++) {
			printf("%d ", belt[i]);
		}*/
	}
	printf("%d\n", answer);
	return 0;
}