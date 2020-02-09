#include "bits/stdc++.h"
using namespace std;

int a[11];

int main() {

    int s;
    scanf("%d", &s);

    int mx = 1e6+5;
    int id = 0;

    for(int i = 1; i < 10; i++ ) {
        scanf("%d", a + i);
        if(i<9 and a[i] <= mx ) {
            mx = a[i];
            id = i;
        }
    }

    //cout<<id<<endl;
    vector< int > ans;
    while( min(mx + mx, a[9]) <= s  ) {

        if( mx + mx <= a[9] and (mx + mx) <= s ) {
            ans.push_back(id);
            ans.push_back(id);
            s -= (mx + mx);
        } else {
            ans.push_back(9);
            s -= a[9];
        }
    }

    for( int i=9; i; i-- ){
        if( a[i] <= s ){
            ans.push_back(i);
            s-=a[i];
        }
    }

    sort(ans.begin(), ans.end());

    for(auto it: ans) printf("%d",it);
    puts("");



    return 0;
}
