class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        // har number ko sah jagah rakho
        for(int i=0; i<n; i++){
            
            // jab tak current number, sahi jagah nahi pahunch jaata
            while(true){
                
                int current = arr[i];
                
                if(current<1 || current>n)
                    break;
                    
                int rightPlace = current-1;
                
                if(arr[rightPlace] == current)
                    break;
                    
                swap(arr[rightPlace], arr[i]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1)
                return i+1; // ye missing hai!
        }
        return n+1; // sab mil gaye, toh next number answer hai
    }
};