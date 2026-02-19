class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();

        arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
        n = arr.size();

        int low = 0;
        int high = n - k;

        while(low < high){
            int mid = low + (high - low) / 2;
            if(x - arr[mid] >= arr[mid+k] - x){  // ← >= fixed here
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        vector<int> result(arr.begin() + low, arr.begin() + low + k);

        sort(result.begin(), result.end(), [&](int a, int b){
            if(abs(a-x) == abs(b-x)) return a > b;
            return abs(a-x) < abs(b-x);
        });

        return result;
    }
};