Problem Link : https://tinyurl.com/28abaoud

0/1 KnapSack :  The constraint here is we can either put an item completely into the bag or cannot put it at all.
  
Eg. wt[] = [1 3 4 5] 
  val[] =  [1 4 5 7]
  W = knapsack capacity = 7 
Maximize profit 

>>>>>>>>>>>>> 1. RECURSIVE IMPLEMENTATION 

  Approach :
1. Base condition 
2. Choice Diagram 
      if (Wt <= W) then take max( val + take,not - take) 
      else if (Wt > W) not take 

Time Complexity: O(2N)
Auxiliary Space: O(N), Stack space required for recursion

Recursive Function Implementation 

int knapSack(int wt[], int val[], int W[], int n)
{
  //base condition 
if(n==0 || W==0) {
return 0;
}
//choice diagram 
if(wt[n-1] <= W) {
return max(val[n-1] + knapSack(wt, val, W-wt[n-1], n-1) , knapSack(wt, val, W, n-1));
}
else if(wt[n-1] > W) {
  return knapSack(wt, val, W, n-1);
} 
}

-----------------------------------------------------------------------------------------------------------------------------------------
  
>>>>>>>>>>>> 2. MEMOIZATION IMPLEMENTATION 
?? Knapsack Memoization 
1. t[n+1][W+1]
2. memset (t,-1,sizeof(t)) 

Time Complexity: O(N * W). As redundant calculations of states are avoided.
Auxiliary Space: O(N * W) + O(N). The use of a 2D array data structure for storing intermediate states
and O(N) auxiliary stack space(ASS) has been used for recursion stack

let n<= 1000
  W <= 1000
  
class Solution
{
    public:
    int t[1002][1002];
int helper(int W,int wt[],int val[],int n)
{
      if(W==0 || n==0){
         return 0;
     }
     if(t[n][W] != -1)
     {
         return t[n][W];
     }
if(wt[n-1] <= W)
{
    // take or not take
return t[n][W] = max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1), 
            knapSack(W,wt,val,n-1));
}
else if(wt[n-1] > W) {
    //not take 
return t[n][W] = knapSack(W,wt,val,n-1);
}
}
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
   memset(t,-1,sizeof(t));
   return helper(W,wt,val,n);
    }
};

 -------------------------------------------------------------------------------------------------------------------------------------
   
>>>>>>>>>> 3. TOP-DOWN APPROACH (Tabulation) 
   
STEPS 
1. Base Condition -> Initialization -> First row and col used for initialization  
2. Recurive fun -> Iterative fun 
3. t[n][w] will give maximum profit 
4. change n -> i & w-> j
  
Time Complexity: O(N * W). where ‘N’ is the number of elements and ‘W’ is capacity. 
Auxiliary Space: O(N * W). The use of a 2-D array of size ‘N*W’.
   
class Solution
{
    public:
int t[1001][1001];
int helper(int W,int wt[],int val[],int n)
{
  
  for(int i=0;i<n+1;i++)
  {
      for(int j=0;j<W+1;j++)
      {
          if(i == 0 || j==0)
          {
         t[i][j]= 0;
          }
      }
  }
   
     
// i=1,j=1 because first row & first col used for initialization
for(int i=1;i<n+1;i++)
{
    for(int j=1;j<W+1;j++)
    {
     if(wt[i-1] <= j)
{
    // take or not take
t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 
            t[i-1][j]);
}
else  {
    //not take 
t[i][j]=   t[i-1][j];
}   
}
}
 return t[n][W];
}
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 

  helper(W,wt,val,n);
  
    }
};









