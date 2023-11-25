In memoization the matrix t[]..t[][] ...t[][][] represents -> No. of variable that are changing in function call

Format : 

STEPS : 
1. Find i and j
2. Find Base Condition 
3. Move K determine k move 
4. ans <- temp_ans
5. return ans
  
int solve(int arr[],int i,int j)
{
//base case 
if(i>j) return 0

//break into k
for(int k=i;k<j;k++) 
{

//calculate temp ans 
temp_ans = solve(arr,i,k) + solve(arr,k+1,j) 
//calculate ans 
  ans <- temp_ans
}
return ans
  }


>> Base Condition 
1. Think of the Smallest Valid Input 
2. Think of Invalid Input 






