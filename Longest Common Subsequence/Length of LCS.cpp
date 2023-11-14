Problem Link : https://tinyurl.com/28bndgkf

Find : Length of Longest Common Subsequence 

Eg. X : a b c d g h 
    Y : a b e d f h 
a b d h
O/P : 4
    
Recursive Approach 

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
