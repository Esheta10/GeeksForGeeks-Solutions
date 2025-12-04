class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        if(n==0)
            return{};
            
        deque<int> deq;
        vector<int> result;
        
        for(int i=0; i<n; i++){
            
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
                
            while(!deq.empty() && arr[i] > arr[deq.back()])
                deq.pop_back();
                
            deq.push_back(i);
            
            if(i>= k-1)
                result.push_back(arr[deq.front()]);
        }
        
        return result;
    }
};