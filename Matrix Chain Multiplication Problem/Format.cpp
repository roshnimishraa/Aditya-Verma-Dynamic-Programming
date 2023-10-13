Format : 
int solve(int arr[],int i,int j)
{
//base case 
if(i>j) return 0

for(int k=i;k<j;k++) 
{
//calculate temp ans 
temp_ans = solve(arr,i,k) + solve(arr,k+1,j) 
//calculate ans 
  ans <- temp_ans
}
return ans
  }
