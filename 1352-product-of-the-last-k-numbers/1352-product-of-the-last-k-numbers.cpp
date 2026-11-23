class ProductOfNumbers {
public:
    vector<int>productOfNumbers;
    ProductOfNumbers() {
        //  productOfNumbers = new ProductOfNumbers();
    }
    
    void add(int num) {
        productOfNumbers.push_back(num);
    }
    
    int getProduct(int k) {
        int n = productOfNumbers.size();
        int product = 1;
        int cnt= 1;
        for(int i = n-1;i>=0;i--){
            if(cnt<= k){
                product*= productOfNumbers[i];
            }
            else break;
            cnt++;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */