#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string cmd;
	cin>>cmd;

	stack<int> s;
	
	for (int i=0;i<cmd.length();i++) {
		//열린 괄호인 경우 push
		if (cmd[i] == '(') {
			s.push(-1);
		}
		else if (cmd[i] == '[') {
			s.push(-3);
		}
		//닫힌 괄호인 경우
			//빈 경우 >>>> 불가
		else if (s.empty())  { printf("0"); return 0; }
		else {
			//앞에 열린괄호인 경우
			if (s.top() == -1 && cmd[i] == ')') {
				s.pop();
				s.push(2);
			}	else if (s.top() == -3 && cmd[i] == ']') {
				s.pop();
				s.push(3);
			} else {
			//앞이 숫자인 경우
				int temp = 0;
				while (s.top() != -1 && s.top() != -3) {
					//계속 더하기
					temp += s.top();
					s.pop();

					if (s.empty()) { printf("0"); return 0; }
				}
				//괄호 짝 만난 경우
				if (s.top() == -1 && cmd[i] == ')') {
					temp *= 2;
					s.pop();
				} else if (s.top() == -3 && cmd[i] == ']') {
					temp *= 3;
					s.pop();
				} else {
				//괄호 짝 맞지않은 경우 >>>> 불가
					printf("0"); return 0;
				}
				s.push(temp);
			}
		}
	}
	int ans = 0;
	while (!s.empty()) {
		//만일 괄호 남았으면 불가능 >>>> 불가
		if (s.top() == -1 || s.top() == -3) {
			printf("0"); return 0;
		} 
		//스택 남은동안 숫자 더하기
		ans += s.top();
		s.pop();
		
	}
	printf("%d", ans);
	return 0;
}