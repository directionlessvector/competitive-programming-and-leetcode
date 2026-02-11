#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        int ans = 0;
        for (int i = x+1; i <= x+90; ++i) {
            if (i == solve(i)+x) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}