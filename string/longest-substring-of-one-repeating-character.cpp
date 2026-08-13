class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char left;
        char right;

        Node() {
            len = 0;
            pref = 0;
            suff = 0;
            best = 0;
            left = '#';
            right = '#';
        }

        Node(char c) {
            len = 1;
            pref = 1;
            suff = 1;
            best = 1;
            left = c;
            right = c;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.left = a.left;
        res.right = b.right;

        // prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.right == b.left) {
            res.pref = a.len + b.pref;
        }

        // suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.right == b.left) {
            res.suff = b.len + a.suff;
        }

        // best
        res.best = max(a.best, b.best);

        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }


    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        // vector<string>v;

        int k = queryIndices.size();
        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < k; i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};






// class Solution {
// public:
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
//         // vector<string>v;
//         int k = queryIndices.size();

//     //TLE --->>> Time Limit Exceeded  -->> 47 / 57 testcases passed
//     //     vector<int>ans;
//     //     for(int i=0;i<k;i++){
//     //         s[queryIndices[i]] = queryCharacters[i];
//     //         // v.push_back(s);

//     //         int mx = 1;
//     //         int cnt =1;
//     //         for(int i =1;i<s.size();i++){
//     //             if(s[i]==s[i-1]) cnt++;
//     //             else {
//     //                 mx = max(mx,cnt);
//     //                 cnt =1;
//     //             }
//     //         }
//     //         mx = max(mx,cnt);
//     //         ans.push_back(mx);

//     //     }
//     //    return ans;
//     }
// };

