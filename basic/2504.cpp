#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string cmd;
	cin>>cmd;

	stack<int> s;
	int ans = 0;
	for (int i=0;i<cmd.length();i++) {
		//열린 괄호인 경우 push
		//닫힌 괄호인 경우
			//빈 경우 >>>> 불가 
			//앞에 열린괄호인 경우
			//앞이 숫자인 경우
				//계속 더하기
				//괄호 짝 만난 경우
				//괄호 짝 맞지않은 경우 >>>> 불가

	}
	//스택 남은동안 숫자 더하기
		//만일 괄호 남았으면 불가능 >>>> 불가

	return 0;
}