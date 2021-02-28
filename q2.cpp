#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int p,n,h;
vector<ll> pc[110];

int main() {
    //pc별로 이용시간 sort 후, 부분합 계산, 딱 운영시간만큼인 항이 있으면 그대로 return, 
    scanf("%d%d%d", &p, &n, &h);
    for (int i=0;i<n;i++) {
        int num; 
        ll hour;
        scanf("%d%lld", &num, &hour);
        pc[num].push_back(hour);
    }

    for (int i=1;i<=p;i++) {
        sort(pc[i].begin(), pc[i].end());
        for (int j=1;j<pc[i].size();j++) {
            pc[i][j] += pc[i][j-1];
        }
    }
    for (int i=1;i<=p;i++) {
        int idx=-1;
        for (int j=0;j<pc[i].size();j++) {
            if (pc[i][j] < h) {
                idx = j;
                continue;
            } else if (pc[i][j] == h) {
                idx = j;
                break;
            } else break;
        }
        printf("%d ", i);
        if (idx == -1) printf("0\n");
        else printf("%lld\n", 1000*pc[i][idx]);
    }
    return 0;
}