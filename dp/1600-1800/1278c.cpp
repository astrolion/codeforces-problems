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

        int cur = n + n;
        for(auto it : v) cur +=  it == 1  ? +1 : -1;

        int base = n + n;

        map<int, int > mp;
        int test = n + n;
        mp[test] = 0;

        for(int i = n; i < n + n; i++) {
            test += v[i] == 1 ? +1 : -1;
            if( mp.find(test)  == mp.end() ) {
                mp[test] = i - n + 1;
            }
        }



        test = n + n;
        int ans = n + n;
        if( mp.find(cur - test + base) != mp.end() ) {
            ans = min(ans, mp[cur - test] );
        }

        cout << endl;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            test += v[i] == 1 ? +1 : -1;
            cnt++;
            cout << test << endl;
            if( mp.find(cur - test+base) != mp.end() ) {
                ans = min(ans, mp[cur - test] + cnt );
            }
        }

        printf("%d\n", ans);


    }

    return 0;
}
