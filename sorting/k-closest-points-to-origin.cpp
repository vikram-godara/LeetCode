class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // vector<pair<pair<int,int>,int>>v;
        // int n = points.size();
        // for(auto x : points){
        //     int a = x[0];
        //     int b = x[1];
        //     long long  d = ((1LL*a*a)+ (1LL*b*b));
        //     v.push_back({{a,b},d});
        // }
        // sort(v.begin(),v.end(),[](auto &a ,auto &b){
        //     return a.second<b.second;
        // });
        // vector<vector<int>>ans;
        // for(int i =0;i<v.size();i++){
        //     if(i<k)ans.push_back({v[i].first.first,v[i].first.second});
        //     else break;
        // }
        // return ans;

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            pq.push({dist, i});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};