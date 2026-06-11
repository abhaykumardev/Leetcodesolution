class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0});
        vis[1] = 1;

        int mxDepth = 0;

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            mxDepth = max(mxDepth, d);

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, d + 1});
                }
            }
        }

        if (mxDepth == 0) return 0;

        return (int)modPow(2, mxDepth - 1);
    }
};
