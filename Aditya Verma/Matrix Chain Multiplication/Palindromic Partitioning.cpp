Approach 1 : Recursion 

class Solution{
    private:
    bool isPalindrome(string str,int i,int j)
{
    while(i<=j){
    if(str[i++] != str[j--])
    {
        return false;
    }
}
return true;
}
int helper(string str,int i,int j)
{
    //base cases 
    int mn = INT_MAX;
// 1. 
if(i>= j) return 0;
//2. if already a palindrome string 
if(isPalindrome(str,i,j)==true){
    return 0;
}

for(int k=i;k<=j-1;k++)
{
    int temp_ans = helper(str,i,k)+helper(str,k+1,j)+1;
    if(temp_ans < mn){
        mn = temp_ans;
    }
}
return mn;
}
public:
    int palindromicPartition(string str)
    {
        return helper(str,0,str.length()-1);
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Approach 2 : Bottom-Up DP (Recursion + Memoization) 

// User function Template for C++

class Solution{
    public:
   int t[501][501];
    bool isPalindrome(string str,int i,int j)
{
if(i== j) return true;
if(i>j) return true;
while(i<j){
    if(str[i] != str[j])
    {
        return false;
    }
    else{
        i++;
        j--;
    }
}
return true;
}

int helper(string str,int i,int j)
{
    //base cases 
    int mn = INT_MAX;
// 1. 
if(i>= j) return 0;
//2. if already a palindrome string 
if(isPalindrome(str,i,j)==true){
  return t[i][j] = 0;
}
if(t[i][j] != -1) 
return t[i][j];

for(int k=i;k<=j-1;k++)
{
    int left,right;
 if(t[i][k] != -1){
    left = t[i][k];
 }
 else{
    left = helper(str,i,k);
     t[i][k] = left;
 }
  if(t[k+1][j] != -1){
     right=t[k+1][j];
  }
  else{
     right= helper(str,k+1,j);
      t[k+1][j]=right;
  }
  
  int temp_ans = 1 + left + right;
    if(temp_ans < mn){
        mn = temp_ans;
    }
}
//store in table/matrix
return t[i][j]=mn;
}
public:
    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof(t));
        return helper(str,0,str.length()-1);
    }
};





  
