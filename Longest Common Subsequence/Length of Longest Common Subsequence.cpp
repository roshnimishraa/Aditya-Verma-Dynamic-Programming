Problem Link : https://tinyurl.com/28bndgkf

Find : Length of Longest Common Subsequence 

Eg. X : a b c d g h 
    Y : a b e d f h 
a b d h
O/P : 4
    
Recursive Approach 

Time Complexity: O(2^m*n)
Auxiliary Space: O(1)

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        //base case
    if(n == 0 || m == 0){
        return 0;
    }
    
    //choice diagram code
    if(s1[n-1] == s2[m-1])
    {
        return 1+lcs(n-1,m-1,s1,s2);
    }
    else{
        return max(lcs(n,m-1,s1,s2), lcs(n-1,m,s1,s2));
    }
    
    }
};

Memoization Approach 

Time Complexity: O(m * n) where m and n are the string lengths.
Auxiliary Space: O(m * n) Here the recursive stack space is ignored.

class Solution
{
    public:
  int t[1002][1002]; 
   
    int helper(int m,int n, string &s1, string &s2){
        //base case 
        if(n == 0 || m == 0){
        return 0;
        }
    if(t[m][n] != -1){
        return t[m][n];
    }

// choice diagram code 
if(s1[m-1] == s2[n-1])
{
   return t[m][n]  = 1 + helper(n-1,  m-1, s1,  s2);
}
else{
return t[m][n] = max(helper(n,  m-1, s1,  s2) ,helper(n-1,  m, s1,  s2));
}

    }
    int lcs(int n, int m, string s1, string s2)
    {
        memset(t,-1,sizeof(t));
        return helper(m,  n, s1,  s2) ;
    }
};

Tabulation Method 

Time Complexity: O(m * n) which is much better than the worst-case time complexity of Naive Recursive implementation. 
Auxiliary Space: O(m * n) because the algorithm uses an array of size (m+1)*(n+1) to store the length of the common substrings.

class Solution
{
    public:

    int lcs(int n, int m, string s1, string s2)
    {
          // your code here
        int dp[n+1][m+1];
        
        for(int i=0; i<n+1; i++)
            for(int j=0; j<m+1; j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
                    
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

