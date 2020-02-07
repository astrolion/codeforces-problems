#include "bits/stdc++.h"
using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;

        scanf("%d", &n);
        vector<int>L(n), R(n);

        for(auto &it : L) scanf("%d", &it);
        for(auto &it : R) scanf("%d", &it);

        int total_one = 0, total_two = 0;
        for(auto it : L) total_one += (it == 1), total_two += (it == 2);
        for(auto it : R) total_one += (it == 1), total_two += (it == 2);

        if(total_one == total_two) {
            puts("0");
            continue;
        }

        if(total_one == 0 or total_two == 0) {
            printf("%d\n", n + n);
            continue;
        }


        int ans = n + n;

        int one = 0, two = 0;
        for(int i = 1; i <= n; i++) {
            if( L[n - i] == 1 ) one++;
            else two++;
            if( total_one - one == total_two - two ) {
                ans = min(ans, i);
            }
        }

        one = two = 0;
        for(int i = 0; i < n; i++) {
            if( R[i] == 1 ) one++;
            else two++;

            if( total_one - one == total_two - two ) {
                ans = min(ans, i + 1);
            }

        }

        vector< int > dp(n + n + 5, -1);

        int cur = n;

        for(int i = n - 1; i >= 0; i--) {
            if(R[i] == 1) cur++;
            else cur--;
            dp[cur] = i;
        }

        cur = n;
        for(int i = 0; i < n; i++) {
            if(L[i] == 2) cur++;
            else cur--;
            if( dp[cur] ^ -1 ) {
                ans = min(ans, n - i - 1 + dp[cur] );
            }
        }

        printf("%d\n", ans);

    }

    return 0;
}
