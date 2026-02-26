class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool> prime(n+1, true);
        
        for(int p=2; p*p<=n; p++){
            
            if(prime[p] == true){
                for(int i=p*p; i<=n; i+=p)
                    prime[i]= false;
            }
        }
        
        vector<int> res;
        for(int j=2; j<=n; j++){
           if(prime[j])
            res.push_back(j);
        }
        return res;
    }
};