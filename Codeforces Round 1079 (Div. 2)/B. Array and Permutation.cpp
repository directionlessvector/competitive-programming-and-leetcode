#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] = i; 
        }
        for (int &x : b) cin >> x;
        bool flag = true;

        int ls = mp[b[0]];  
        for (int i = 1; i < n; ++i) {
            if (b[i] != b[i - 1]) {
                int curr = mp[b[i]];
                if (curr < ls) {  //order ulto thai gyo
                    flag = false;
                    break;
                }
                ls = curr;  //update kariye
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "No " << endl;
    }
}