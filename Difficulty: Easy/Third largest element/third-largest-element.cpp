class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        int third_largest = INT_MIN;
        
        for(int i=0;i<n;i++){
            
            if(arr[i] > largest){
                third_largest = second_largest;
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i] <= largest && arr[i] >= second_largest){
                third_largest = second_largest;
                second_largest = arr[i];
            }
            else if(arr[i] <= second_largest && arr[i] >= third_largest){
                third_largest = arr[i];
            }
        }
        return third_largest;
    }
};