class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        int third_largest = INT_MIN;
        
        for(int num :  arr){
            
            if(num >= largest){
                third_largest = second_largest;
                second_largest = largest;
                largest = num;
            }
            
            else if(num >= second_largest && num  <= largest ){
                third_largest = second_largest;
                second_largest = num ;
            }
            
            else if(num >= third_largest && num <= second_largest){
                third_largest = num;
            }
        }
        
        return third_largest;
    }
};