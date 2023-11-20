Problem Link : https://tinyurl.com/ylauuu53

>> Approach : LCS + Repeating char 
>> Single occurance of char -> ignore 

TC : O(N^2) 
SC : O(N^2) 

class Solution {
	public:
	int lcs(string x,string y,int m,int n){
	   int t[m+1][n+1];
	  for(int i=0;i<m+1;i++){
	      for(int j=0;j<n+1;j++){
	          if(i==0 || j==0){
	              t[i][j] = 0;
	          }
	      }
	  }
	
for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
        if(x[i-1] == y[j-1] && i!= j)
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
		int LongestRepeatingSubsequence(string str){
 int n=str.length();
 string str2 = str;
 return lcs(str,str2,n,n);
		}

};
