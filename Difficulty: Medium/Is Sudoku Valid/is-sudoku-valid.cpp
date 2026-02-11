class Solution {
  public:
    bool validBoard(vector<vector<int>>& mat, int sr, int er, int sc, int ec){
        
        unordered_set<int> st;
        for(int row=sr; row<=er; row++){
            for(int col=sc; col<=ec; col++){
                
                if(mat[row][col] == 0) continue;
                if(st.find(mat[row][col]) != st.end())
                    return false;
                
                
                st.insert(mat[row][col]);
            }
        }
        return true;
    }
    bool isValid(vector<vector<int>>& mat) {
        // code here
        
        // validate rows
        for(int row=0; row<9; row++){
            unordered_set<int> st;
            for(int col=0; col<9; col++){
                
                if(mat[row][col] == 0) continue;
                
                if(st.find(mat[row][col]) != st.end())
                    return false;
                    
                st.insert(mat[row][col]);
            }
        }
        
        // validate cols
        for(int col=0; col<9; col++){
            unordered_set<int> st;
            for(int row=0; row<9; row++){
                
                if(mat[row][col] == 0) continue;
                
                if(st.find(mat[row][col]) != st.end())
                    return false;
                    
                st.insert(mat[row][col]);
            }
        }
        
        // validate 3x3 box
        for(int sr=0; sr<9; sr+=3){
            int er = sr+2;
            for(int sc=0; sc<9; sc+=3){
                int ec = sc+2;
                if(!validBoard(mat,sr,er,sc,ec))
                    return false;
            }
        }
        return true;
    }
};