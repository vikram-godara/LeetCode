class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string> str;
        for(int i=1;i<=n;i++){
            str.push_back(to_string(i));  //number to string convert 
    }
    sort(str.begin(),str.end());
    
    vector<int> results;
    for(int i=0;i<n;i++){
        results.push_back(stoi(str[i])); //string to  number convert 
    }
  return results;
    }
    
};