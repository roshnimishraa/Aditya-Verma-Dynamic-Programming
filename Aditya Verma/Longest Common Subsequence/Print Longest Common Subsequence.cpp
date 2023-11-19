Problem Link : https://tinyurl.com/yqgk8vp3

Approach : Longest Common Subseuences 


class Solution {
public:
int t[1002][1002];
int lcs(string x,string y,int m,int n){
// initialization 
for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i==0 || j==0){
            t[i][j] = 0;
        }
    }
}

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
    string shortestCommonSupersequence(string str1, string str2) {
   int m = str1.length();
   int n = str2.length();
      int ans = lcs(str1,str2,m,n);
   int i=m, j = n;
   string s = "" ; //scs print 

while(i>0 && j>0){
    if(str1[i-1] == str2[j-1])
    {
 //if string are matching then store only one occurance of string 
        s.push_back(str1[i-1]);
        i--;
        j--;
    }
    // str1 != str2 
    else{
// if string are not matching but present in both str1 and str2 then
//doesn't add any string
        if(t[i][j-1] > t[i-1][j])
        {
            j--;
        }
        else{
            i--;
        }
    }
}
// since iteration start from t[m][n] then the ans is in   
//reverse order therefore reverse to get the original ans
reverse(s.begin(),s.end());
return s;
    }
};
