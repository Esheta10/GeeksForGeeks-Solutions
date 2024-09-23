//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        if(matrix.size()==0)
            return {};
         
         int m=matrix.size();
         int n=matrix[0].size();
         
         int top=0;
         int down=m-1;
         int left=0;
         int right=n-1;
         
         int id=0;
         vector<int> result;
         while(top<=down && left<=right)
         {
             //left to right
             //constant:row(top)
             if(id==0)
             {
                 for(int i=left;i<=right;i++)
                 {
                     result.push_back(matrix[top][i]);
                 }
                top++;
             }
             //top to down
             //constant:column(right)
             if(id==1)
             {
                 for(int i=top;i<=down;i++)
                 {
                     result.push_back(matrix[i][right]);
                 }
                 right--;
             }
             //right to left
             //constant:row(down)
             if(id==2)
             {
                for(int i=right;i>=left;i--)
                 {
                     result.push_back(matrix[down][i]);
                 }
                 down--;
             }
             //down to top
             //constant:column(left)
            if(id==3)
            {
                 for(int i=down;i>=top;i--)
                 {
                     result.push_back(matrix[i][left]);
                 }
                 left++;
            }
            id++;
            if(id==4)
                id=0;
         }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends