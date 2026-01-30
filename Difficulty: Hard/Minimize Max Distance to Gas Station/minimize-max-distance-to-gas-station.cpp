class Solution {
  public:
    bool canPlaceStations(vector<int>& stations, int K, double maxDist){
        
        int needed = 0;
        int n = stations.size();
        
        for(int i=0; i<n-1; i++){
            
            double gap = stations[i+1] - stations[i];
            // how many stations needed in this gap?
            int stationsInGap = (int)(gap / maxDist);
            needed += stationsInGap;
        }
        return needed <= K;
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        
        // binary serach on answer
        double left = 0;
        double right = stations[n-1] - stations[0];
        double ans = right;
        
        while(right - left > 1e-6){
            
            double mid = left + (right - left)/2;
            
            if(canPlaceStations(stations, K, mid)){
                ans = mid;  // potential answer
                right = mid; // try smaller distance
            } else {
                left = mid; // try larger distances
            }
        }
        return ans;
    }
};