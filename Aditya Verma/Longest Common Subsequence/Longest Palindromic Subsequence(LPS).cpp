Problem Link : https://leetcode.com/problems/longest-palindromic-subsequence/description/

LPS(a) = LCS(a,reverse(a)) 
  
Eg. s = a g b c b a 
reverse s = a b c b g a 
find length of LCS = 5 
output = 5
  
TC : O(N^2) 
SC : O(N^2) 

  
class Solution {
public:
int lcs(string x,string y,int m,int n){
    int t[m+1][n+1];
//initialization 
for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i==0 || j==0){
            t[i][j] = 0;
        }
    }
}

// choice diagram 
for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
if(x[i-1] == y[j-1])
{
    t[i][j] = 1 + t[i-1][j-1];
}
else{
    t[i][j] = max(t[i-1][j] , t[i][j-1]);
}
    }
}
return t[m][n];
}
    int longestPalindromeSubseq(string s) {
string s2 = s;
reverse(s2.begin(),s2.end());
int n = s.length();
int m = s2.length();
return lcs(s,s2,m,n);
    }
};
