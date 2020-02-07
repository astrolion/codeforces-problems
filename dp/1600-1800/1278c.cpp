#include "bits/stdc++.h"
using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;

        scanf("%d", &n);
        vector< int > v(n + n);

        for(auto &it : v) scanf("%d", &it);

        int d = 0;
        for(auto it : v) {
            if( it == 1 )d++;
            else d--;
        }

        map< int, int > mp;
        int cur = 0;
        mp[cur] = 0;

        for(int i = n; i < n + n; i++) {
            if(v[i] == 1) cur++;
            else cur--;
            if( !mp.count(cur) ) {
                mp[cur] = i - n + 1;
            }
        }

        int ans = n + n;
        if( mp.count(d) ) {
            ans = min(ans, mp[d] );
        }

        int cnt = 1;
        cur = 0;

        for(int i = n - 1; i >= 0; i--) {

            if( v[i] == 1 ) cur++;
            else cur--;

            if( mp.count( d - cur ) ) {
                ans = min(ans, cnt + mp[ d - cur ] );
            }

            cnt++;
        }

        printf("%d\n", ans);


    }

    return 0;
}
