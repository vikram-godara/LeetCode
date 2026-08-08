class EventManager {
public:

    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        auto den = events;
        for(auto &x : den){
           int id = x[0];
            int pr = x[1];
            mp[id] = pr;
            pq.push({pr,-id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
         mp[eventId] = newPriority;
         pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        // if(mp.empty())return -1;
        // int b = -1;
        // int bp=-1;
        // for(auto &p:mp){
        //     int id = p.first;
        //     int pr = p.second;
        //     if(pr>bp || (pr == bp && id<b)){
        //         bp = pr;
        //         b = id;
        //     }
        // }
        // mp.erase(b);
        // return b;
        while(!pq.empty()){
            auto [pr,neg] = pq.top();
            int id = -neg;
            pq.pop();

            if(mp.count(id) && mp[id]==pr){
                mp.erase(id);
                return id;
            }
        }return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */