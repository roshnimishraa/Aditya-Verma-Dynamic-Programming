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

>>>>>>>>>>>> 2. MEMOIZATION IMPLEMENTATION 
?? Knapsack Memoization 
1. t[n+1][W+1]
2. memset (t,-1,sizeof(t)) 


let n<= 100 
  W <= 1000
  
int t[102][1002] 
// in main fun 
memset(t,-1,sizeof(t))
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


>>>>>>>>>> 3. TOP-DOWN APPROACH 
STEPS 
1. Base Condition -> Initialization -> First row and col used for initialization  
2. Recurive fun -> Iterative fun 

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        long long int t[n+1][W+1];
        //Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    
// Choice diagram 
for(int i=1;i<n+1;i++)
{
    for(int j=1;j<W+1;j++)
    {
        if(wt[i-1] <= j)
        {
t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
 }
else {
    t[i][j] = t[i-1][j];
}
       
 }
}
return t[n][W];
    }
};











