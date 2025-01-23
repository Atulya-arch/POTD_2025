//Best Approach
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            int val=arr[i];
            mp[val]=i;
        }
        
        //Check each row one by one
        int minIdx=INT_MAX;
        for(int row=0; row<m; row++){
            int lastIdx=INT_MIN; // last Index in arr when this row will be completely painted
            for(int col=0; col<n; col++){
                int val=mat[row][col];
                int index=mp[val];
                lastIdx=max(lastIdx, index);
            }
            minIdx=min(minIdx, lastIdx);
        }

        //Check each column one by one
        for(int col=0; col<n; col++){
            int lastIdx=INT_MIN; // last Index in arr when this column will be completely painted
            for(int row=0; row<m; row++){
                int val=mat[row][col];
                int index=mp[val];
                lastIdx=max(lastIdx, index);
            }
            minIdx=min(minIdx, lastIdx);
        }
        
        return minIdx;
    }
};