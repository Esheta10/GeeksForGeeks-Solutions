class Solution {
  public:
    vector<int> addOne(vector<int>& arr) {
        // code here
        int n = arr.size();
        int carry = 1;
        
        for(int i=n-1;i>=0;i--){
            int sum = arr[i] + carry;
            
            arr[i] = sum % 10;
            carry = sum / 10;
        }
        
        if(carry)
            arr.insert(arr.begin(),1);
            
            
        return arr;
    }
};