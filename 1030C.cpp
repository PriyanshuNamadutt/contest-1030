#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while( t-- ) {
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> a(n);
        ll ans = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            ans += __builtin_popcountl( a[i] );
        }

        for ( int i = 0; i <= 60; i++ ) {
            if ( k < (1LL << i) ) break;

            for ( int j = 0; j < n; j++ ) {
                if ( (k < (1LL << i)) || ( a[j] & (1LL << i)) ) continue;
                ans++;
                k -= (1LL << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
