#define ll long long

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        vector dp(n + 1, vector(m + 1, vector<ll>(k + 1, LLONG_MIN)));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j][0] = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                for (int used = 1; used <= k; ++used) {
                    ll ans = LLONG_MIN;
                    ans = max(ans, dp[i + 1][j][used]);
                    ans = max(ans, dp[i][j + 1][used]);
                    if (dp[i + 1][j + 1][used - 1] != LLONG_MIN) {
                        ans = max(ans, dp[i + 1][j + 1][used - 1] + 1LL * a[i] * b[j]);
                    }
                    dp[i][j][used] = ans;
                }
            }
        }

        return dp[0][0][k];
    }
};

// memoized solution
// #define ll long long

// class Solution {
// public:
//     int n , m;
//     vector<vector<vector<ll>>> dp;
//     vector<int> a,b;
    
//     ll solve(int i, int j, int used) {
//         if (used == 0)
//             return 0;

//         if (i == n || j == m)
//             return LLONG_MIN;

//         if (dp[i][j][used] != LLONG_MIN)
//             return dp[i][j][used];

//         ll ans = LLONG_MIN;
//         ans = max(ans, solve(i + 1, j, used));
//         ans = max(ans, solve(i, j + 1, used));
//         // ans = max(ans, solve(i + 1, j + 1, used - 1) + 1LL * a[i] * b[j]);
//         ll take_both = solve(i + 1, j + 1, used - 1) ;
//         if (take_both != LLONG_MIN)
//             ans = max(ans, take_both + 1LL * a[i] * b[j]);

//         return dp[i][j][used] = ans;
//     }
    
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         a = nums1, b = nums2;
//         n = nums1.size(), m = nums2.size();

//         dp.assign(n, vector<vector<ll>>(m, vector<ll>(k+1, LLONG_MIN)));

//         return solve(0, 0, k);
//     }
// };