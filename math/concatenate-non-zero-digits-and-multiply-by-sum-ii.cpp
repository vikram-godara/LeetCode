// class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         int n = s.size();
//         int x = queries.size();
//         vector<int>ans;
//         ans.reserve(x);
//         const long long mod = 1000000007LL;
//         for(auto q: queries){
//             int a = q[0];
//             int b = q[1];
//             long long sum =0;
//             long long z =0;

//             for(int i=a;i<=b;i++){
//                 if(s[i]!='0'){
//                    long long d = s[i]-'0';
//                    sum+=d;
//                    z = ((z*10) +d)%mod;
//                 }
//             }
//             auto m = (z*sum)%mod;
//             ans.push_back(m);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod = 1000000007;
        int n = s.size();

        vector<long long> pre(n + 1, 0);
        vector<long long> sum(n + 1, 0);
        vector<long long> pw(n + 1, 1);
        vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            pre[i + 1] = pre[i];
            sum[i + 1] = sum[i] + d;
            cnt[i + 1] = cnt[i];

            if (d != 0) {
                pre[i + 1] = (pre[i + 1] * 10 + d) % mod;
                cnt[i + 1]++;
            }

            pw[i + 1] = (pw[i] * 10) % mod;
        }

        vector<int> ans;

        for (auto q : queries) {
            int l = q[0];
            int r = q[1];

            long long sm = sum[r + 1] - sum[l];

            int len = cnt[r + 1] - cnt[l];

            long long x = pre[r + 1];
            long long remove = (pre[l] * pw[len]) % mod;

            x = (x - remove + mod) % mod;

            ans.push_back((x * sm) % mod);
        }

        return ans;
    }
};