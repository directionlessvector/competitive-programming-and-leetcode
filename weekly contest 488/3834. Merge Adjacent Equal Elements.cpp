#define ll long long

class Solution {
public:
    vector<ll> mergeAdjacent(vector<int>& a) {
        // int n = a.size();
        // vector<ll> ans;
        vector<ll> st;
        // ans.push_back(a[0]);
        
        // for (int i = 1; i < n; ++i) {
        //     if (ans.back() == a[i]) {
        //         ans.pop_back();
        //         if (!ans.empty() && ans.back() == 2 * a[i]) {
        //             ans.pop_back();
        //             ans.push_back(4 * a[i]);
        //         }
        //         else 
        //             ans.push_back(2 * a[i]);
        //     }
        //     else {
        //         ans.push_back(a[i]);
        //     }
        // }

        for (int &x : a) {
            ll temp = x;
            while (!st.empty() && st.back() == temp) {
                st.pop_back();
                temp = 2 * temp;
            }
            
            st.push_back(temp);
        }

        return st;
    }
};