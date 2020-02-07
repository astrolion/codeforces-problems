#include "bits/stdc++.h"
using namespace std;

int main() {

    int rows, cols;
    scanf("%d %d", &rows, &cols);

    vector< vector<int> > g( rows, vector<int>(cols) );

    int val = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &g[i][j]);
        }
        val ^= g[i][0];
    }

    vector< int > ans(rows, 0);

    if( !val ) {
        bool flag = false;
        for(int i = 0; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if( g[i][j] ^ g[i][0] ) {
                    ans[i] = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag == false) {
            puts("NIE");
            return 0;
        }
    }

    puts("TAK");
    for(auto it : ans) printf("%d ", it + 1);


    return 0;
}
