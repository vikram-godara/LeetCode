class Solution {
    vector<int> seg;
    
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }
        
        int mid = (l + r) >> 1;
        
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);
            
        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }
    
    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[node];
        
        int mid = (l + r) >> 1;
        
        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // int n  = queries.size();
        // vector<bool>ans;
        // int maxx = 50000;
        // vector<int>arr(maxx+1,0);
        // for(auto  &q : queries){
        //     int len = q.size();
        //     if(len==2){
        //         int x = q[1];
        //         arr[x] = 1;
        //     }
        //     if(len==3){
        //         int x = q[1];
        //         int sz = q[2];
        //         vector<int>pos;
        //          pos.push_back(0);
        //         int max1  = 0;
        //         for(int i=1;i<=x;i++){
        //             if(arr[i]) pos.push_back(i);
        //         }
        //         for(int i=1;i<pos.size();i++){
        //             max1 = max(max1 , pos[i] - pos[i-1]);
        //         }
        //         max1 = max ( max1 , x - pos.back());
            

        //       ans.push_back(max1>=sz);
        //     }
        // }
        // return ans;
        
        const int MX = 50000;
        
        set<int> st;
        st.insert(0);
        st.insert(MX);
        
        vector<int> obstacle(MX + 1, 0);
        
        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacle[q[1]] = 1;
                st.insert(q[1]);
            }
        }
        
        seg.assign(4 * (MX + 1), 0);
        
        for (auto it = next(st.begin()); it != st.end(); ++it) {
            update(1, 0, MX, *it, *it - *prev(it));
        }
        
        vector<bool> ans;
        
        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            
            if (queries[i][0] == 2) {
                
                int x = queries[i][1];
                int sz = queries[i][2];
                
                int best = query(1, 0, MX, 0, x);
                
                auto it = st.upper_bound(x);
                int last = *prev(it);
                
                best = max(best, x - last);
                
                ans.push_back(best >= sz);
            }
            else {
                
                int p = queries[i][1];
                
                auto it = st.find(p);
                
                int L = *prev(it);
                int R = *next(it);
                
                update(1, 0, MX, p, 0);
                update(1, 0, MX, R, R - L);
                
                st.erase(it);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};