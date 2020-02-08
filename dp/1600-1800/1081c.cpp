#include "bits/stdc++.h"
using namespace std;

int main() {

    const int MOD = 998244353;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector< vector< int > > dp( n + 1, vector<int>(n + 1, 0) );

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {

            if(j == 0 or i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] %= MOD;
            }

        }
    }

    int ans = dp[n - 1][k];

    ans = (1LL * dp[n - 1][k] * m) % MOD;

    for(int i = 0; i < k; i++) {
        ans = (1LL * ans * (m - 1) ) % MOD;
    }

    printf("%d\n", ans);



    return 0;
}
