Invalid Condition (Base Condition ) 
1. String is empty => i> j 
2. string size is 1 => i == j 
  if(i>= j ) return 0
3. if given string is already palindrome => return 0 

>> Bottom Up DP (Recursion + Memoization) 

class Solution{
public:
int t[501][501];
bool isPalindrome(string &s,int i,int j){
    if(i>j || i == j){
        return true;
    }
    while(i<j){
        if(s[i] != s[j])
         return false;
         i++;
           j--;
    }
    return true;
}
int solve(string &s,int i,int j){
    // base case 
    if(i>=j){
        return 0;
    }

if(isPalindrome(s,i,j) == true){
return 0;
}    

if(t[i][j] != -1){
    return t[i][j];
}
    int mini = INT_MAX;
for(int k = i;k<=j-1;k++){
 int left,right;
if(t[i][k] != -1){
  left = t[i][k];
}
else{
  left = solve(s,i,k);
  t[i][k] = left;
}
if(t[k+1][j] != -1){
    right = t[k+1][j];
    
}
else{
    right = solve(s,k+1,j);
    t[k+1][j] = right;
}
int temp_ans = 1 + left+right;
    if(temp_ans < mini)
    {
        mini = temp_ans;
    }
}
return t[i][j] = mini;
}
    int palindromicPartition(string str)
    {
        int n = str.length();
        memset(t,-1,sizeof(t));
return solve(str,0,n-1);
    }
};
  
