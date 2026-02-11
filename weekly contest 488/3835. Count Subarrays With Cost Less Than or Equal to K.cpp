#define ll long long

struct SegTree {
    int n;
    vector<ll> mn, mx;

    SegTree(int n) {
        this->n = n;
        mn.assign(4 * n, LLONG_MAX);
        mx.assign(4 * n, LLONG_MIN);
    }

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            mn[node] = mx[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }

    pair<ll, ll> query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return {LLONG_MAX, LLONG_MIN};

        if (ql <= l && r <= qr)
            return {mn[node], mx[node]};

        int mid = (l + r) / 2;
        auto left = query(node * 2, l, mid, ql, qr);
        auto right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return {
            min(left.first, right.first),
            max(left.second, right.second)
        };
    }

    void update(int node, int l, int r, int idx, ll val) {
        if (l == r) {
            mn[node] = mx[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        int n = a.size();
        SegTree st(n);
        st.build(1, 0, n - 1, a);

        ll ans = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (l <= r) {
                auto [mn, mx] = st.query(1, 0, n - 1, l, r);
                ll t = (mx - mn) * (r - l + 1);
                    if (t <= k)
                        break;

                l++;
            }
            ans += (r - l + 1);
        }

        return ans;
    }
};