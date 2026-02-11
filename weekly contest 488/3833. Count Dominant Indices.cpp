class Solution {
public:
    int dominantIndices(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        vector<int> pref(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            pref[i] = pref[i + 1] + a[i];
        }

        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] * (n - i - 1) > (pref[i + 1]))
                ++ans;
        }

        return ans;
    }
};