Problem Link : https://tinyurl.com/ys98acwu

>> Total number of Deletion = str1.length() - lcs(x,y,m,n) 
>> Total number of Insertion = str2.length() - lcs(x,y,m,n) 

class Solution{
	public:
	int t[1001][1001];
int lcs(string x,string y,int m,int n)
{
    //initialization 
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i == 0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    
    // choice diagram 
for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
        if(x[i-1] == y[j-1])
        {
t[i][j] = 1 +t[i-1][j-1];
        }
    else{
     t[i][j] = max(t[i-1][j],t[i][j-1]);  
    }
    }
}
return t[m][n];
}
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.length();
	    int n = str2.length();
int longCommSubSeq = lcs(str1,str2,m,n);
int delCount = m -longCommSubSeq;
int insertCount = n - longCommSubSeq ;
int ans = delCount + insertCount;
return ans;
 } 
};
