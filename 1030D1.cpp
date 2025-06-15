#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, k;
        cin >> n >> k;
        vector<int> light(n);
        vector<int> delay(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> light[i];
        }
        for ( int i = 0; i < n; i++ ) {
            cin >> delay[i];
        }
        int q; cin >> q;
        while ( q-- ) {
            int x; cin >> x;

            int pos = lower_bound( light.begin(), light.end(), x) - light.begin();
            bool dir = true;
            unordered_map<int,bool> vis1;
            unordered_map<int,bool> vis2;
            int t = 0;
            int prev = x;
            bool ans = true;
            while ( pos < n && pos >= 0 ) {
                int time = t + abs( light[pos] - prev );
                time %= k;
                if ( delay[pos] == time ) {

                    if ( (dir && vis1[light[pos]]) || (!dir && vis2[light[pos]]) ) {
                        ans = false;
                        break;
                    }

                    if ( dir ) vis1[light[pos]] = true;
                    if ( !dir) vis2[light[pos]] = true;

                    dir = !dir;
                    prev = light[pos];
                    t = time;
                }
                pos += ( dir ? 1 : -1 );
            }
            cout << ( ans ? "YES" : "NO" ) << endl;
        }
    }
    return 0;
}
