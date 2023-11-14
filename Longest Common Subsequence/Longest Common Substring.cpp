Time complexity: O(2^max(m,n)) as the function is doing two recursive calls – lcs(i, j-1, 0) and lcs(i-1, j, 0) 
when characters at X[i-1] != Y[j-1]. So it will give a worst case time complexity as 2^N, where N = max(m, n), m and n 
is the length of X and Y string.
Auxiliary Space: O(1): as the function call is not using any extra space (function is just using a recursive call 
stack which we generally doesn’t consider in auxiliary space).

class Solution{
    public:
  int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int t[n+1][m+1];
//initialization 
for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        if(i==0 || j==0){
            t[i][j] = 0;
        }
    }
}

int ans = 0;
for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
    if(s1[i-1] == s2[j-1]){
    t[i][j] = 1 + t[i-1][j-1];
    ans = max(t[i][j],ans);
    }
else{
  t[i][j] = 0;
}
    }
}
return ans;
    }
};
