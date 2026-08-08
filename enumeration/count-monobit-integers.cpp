class Solution {
public:
    int countMonobit(int n) {
        int x = n;
        int count = 1;
        for(int i = 1 ; ; i++){
            int a = (1<<i) - 1;
            if(a>n){
                break;
            }
            count++;
        }
        return count;
    }
};