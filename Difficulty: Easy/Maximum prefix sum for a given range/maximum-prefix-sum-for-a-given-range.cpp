class Solution {
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex,
                            vector<int>& rightIndex) {
        // code here.
        
        vector<int> result;
        for (int q = 0; q < leftIndex.size(); q++) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = leftIndex[q]; i <= rightIndex[q]; i++) {
            sum += arr[i];
            maxSum = max(maxSum, sum);  // track running max
        }
        result.push_back(maxSum);
     }
    return result;
        
    }
};