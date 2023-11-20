Problem Link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

>> Observation 
No. of deletion == No. of Insertion => str.length()-LCS

1. Length of LPS(Longest Palindromic Subsequence) inversely propotional to No. of Deletion 

2. If length of LPS is greater then No. of Deletion is minimum 

From this observation, the question reduces and now find LPS (Longest Palindromic Subsequence) 

>> Minimum Number of Deletion = str.length() - LCS
Eg. s = a g b c b a 
option 1 = a g b c b a (3) delete a g a to make palindrome 
option 2 = a g b c b a (5) delete a g b b a 
option 3 = a g b c b a (1) delete g 
return minimum deletion 
 o/p = 1 


int lcs(string x,string y,int n ,int m){
    int t[n+1][m+1];
    // initialization 
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
        }
    }
    }
    // choice diagram 
for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
        if(x[i-1] == y[j-1]){
        t[i][j] = 1 + t[i-1][j-1];
        }
    else{
        t[i][j] = max(t[i-1][j] , t[i][j-1]);
    }
    }
}
return t[n][m];
}
int minDeletions(string str, int n) { 
   string str1 = str;
   reverse(str1.begin(),str1.end());
   int m = str1.length();
   int longCommSubseq = lcs(str,str1,n,m);
   int minDel = n - longCommSubseq;
   return minDel;
} 
