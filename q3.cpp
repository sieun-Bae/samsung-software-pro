#include <iostream>
using namespace std;

int n,m,e,ans=0;
int peanut[10010];
bool tmpflag = false;
int startIdx = -1;
void setIdx(int idx, bool plus, int howmuch)
{
    if (plus) {
        for (int i=0;i<idx;i++) {
            peanut[i] += howmuch;
        }
    } else {
        for (int i=idx+1;i<n;i++) {
            peanut[i] -= howmuch;
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &e);
    
    for (int i=0;i<n;i++) {
        scanf("%d", &peanut[i]);
        if (e==peanut[i]) { 
            m--; 
            tmpflag=true;
            startIdx = i;
        }//땅콩과 소마 위치가 같으면 바로 먹음
    }
    //소마 위치가 땅콩들 사이라면, 
    if (e <= peanut[0]) {//소마 위치가 땅콩들 앞일때,
        ans = peanut[m]-e;
    } else if (e >= peanut[n-1]) {//소마 위치가 땅콩들 뒤일 때
        ans = e-peanut[n-1-m];
    } else { //소마 위치가 땅콩들 사이일때
        //우선 소마의 위치가 포함되는 인덱스를 찾음
        int idx=0;
        if (tmpflag) idx = startIdx;
        else {
            for (int i=1;i<n;i++) {
                if (peanut[i-1] < e && e < peanut[i]) { //차이가 같은 경우는 어떡하지?
                    if (peanut[idx] - e < e - peanut[idx-1]) {
                        idx = i;
                        int howmuch = peanut[idx] - e;
                        ans += howmuch;
                        //오른쪽으로 가면 왼쪽애들 peanut[idx]-e만큼 더해줌
                        setIdx(idx, true, howmuch);
                    }
                    else {
                        idx = i-1;
                        int howmuch = e - peanut[idx-1];
                        ans += howmuch;
                        //왼쪽으로 가면 오른애들 e-peanut[idx]만큼 빼줌
                        setIdx(idx, false, howmuch);
                    }
                    m--;
                    break;
                }
            }
        }

        while (m--) {
            if (idx > n || idx < 0) break;
            if (peanut[idx+1] - e < e - peanut[idx-1]) {
                idx++; //차이가 같은 경우는 어떡하지?
                int howmuch = peanut[idx] - e;
                ans += howmuch;
                //오른쪽으로 가면 왼쪽애들 peanut[idx]-e만큼 더해줌
                setIdx(idx, true, howmuch);
            }
            else {
                idx--;
                int howmuch = e - peanut[idx-1];
                ans += howmuch;
                //왼쪽으로 가면 오른애들 e-peanut[idx]만큼 빼줌
                setIdx(idx, false, howmuch);
            }
        }


    }
    printf("%d\n",ans);
    //거리 차이 (인덱스)는 매번 갱신됨 
    //인덱스 찾고 양 옆 탐색, 거리 차이 적은 애 
    //(소마기준 오른쪽으로 이동하면 이동한만큼 그 전 애들 --;)
    //         왼쪽으로 이동하면 이동한만큼 그 후 애들 ++;
    return 0;
}