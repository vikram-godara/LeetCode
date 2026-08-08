class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
       unordered_map<uint64_t, int> suffixMap;
        
        int shortest_idx = 0;
        for(int i = 0; i < wordsContainer.size(); i++) {
            if(wordsContainer[i].size() < wordsContainer[shortest_idx].size()) {
                shortest_idx = i;
            }
        }
        
        const uint64_t BASE = 313;
        
        for(int i = 0; i < wordsContainer.size(); i++) {
            uint64_t hash = 0;
            uint64_t p = 1;
            
            for(int j = wordsContainer[i].size() - 1; j >= 0; j--) {
                hash += (wordsContainer[i][j] - 'a' + 1) * p;
                p *= BASE;
                
                if(suffixMap.find(hash) == suffixMap.end()) {
                    suffixMap[hash] = i;
                } else {
                    int saved_idx = suffixMap[hash];
                    if(wordsContainer[i].size() < wordsContainer[saved_idx].size()) {
                        suffixMap[hash] = i;
                    }
                }
            }
        }
        
        vector<int> result;
        for(string& q : wordsQuery) {
            int best_ans = shortest_idx;
            uint64_t hash = 0;
            uint64_t p = 1;
            
            for(int j = q.size() - 1; j >= 0; j--) {
                hash += (q[j] - 'a' + 1) * p;
                p *= BASE;
                
                if(suffixMap.find(hash) != suffixMap.end()) {
                    best_ans = suffixMap[hash];
                } else {
                    break; 
                }
            }
            result.push_back(best_ans);
        }
        
        return result;
    }
    };