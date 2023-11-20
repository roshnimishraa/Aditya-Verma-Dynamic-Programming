>> if a present in b -> return true 
>> LCS 0 to min(m,n) 


class Solution {
public:
int lcs(string x,string y,int m,int n)
{
int t[m+1][n+1];
  
    // initialization 
 for(int i=0;i<m+1;i++){
     for(int j=0;j<n+1;j++){
         if(i==0 || j==0){
             t[i][j] = 0;
         }
     }
 }

//  choice diagram 
for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
    if(x[i-1] == y[j-1])
    {
    t[i][j] = 1 + t[i-1][j-1];
    }
else{
    t[i][j] = max(t[i-1][j], t[i][j-1]);
}
    }
}
return t[m][n];
}
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
int longestCommonSubSeq = lcs(s,t,m,n);
if(m == longestCommonSubSeq){
    return true;
}
else {
    return false;
}
    }
};
