#include "bits/stdc++.h"
using namespace std;

int main() {



    int t;
    cin >> t;

    while(t--) {
        string s, t;
        cin >> s >> t;

        vector< bool > v1(26, false);

        for(char ch : s)
            v1[ ch - 'a' ] = true;

        bool flag = true;

        for(char ch : t) {
            if( v1[ ch - 'a' ] ) continue;
            flag = false;
        }

        if( !flag ) {
            puts("-1");
            continue;
        }

        vector< int > g[26];
        for(int i = 0; i < (int)s.size(); i++ ) {
            g[ s[i] - 'a' ].push_back(i);
        }

        int pos = -1;
        int cnt = 0;

        //cout<< s <<" "<< t<<endl;
        string test = "";

        for(auto ch : t) {

            int it = ch - 'a';
            //cout<<it<<endl;
            test+=ch;

            if(pos == -1) {
                cnt++;
                pos = g[ it ][0];
                //test = "";
                //cout<<test<<endl;

            } else {

                int st = 0, ed = (int) g[it].size() - 1;
                int ans = -1;

                //cout<<pos<<endl;
                while(st <= ed) {
                    int mid = (st + ed) / 2;
                    if( g[it][mid] > pos ) {
                        ans = g[it][mid];
                        ed = mid - 1;
                    } else {
                        st = mid + 1;
                    }
                }

                //cout<<ans<<endl;

                if( ans == -1 ) {
                    cnt++;
                    pos = g[it][0];
                    //cout<<test<<endl;
                } else {
                    pos = ans;
                }


            }
        }

        cout << cnt << "\n";



    }

    return 0;
}
