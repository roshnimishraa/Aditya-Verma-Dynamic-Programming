Approach : Recursion + Map 



class Solution{

public:
int mod = 1003;
    unordered_map<string,int> umap;
int solve(string &str,int i,int j,bool isTrue)
{
    //base case 
if(i>j){
    return 0;
    
}
if(i==j){
    if(isTrue){
        return str[i]=='T';
        
    }
    else{
        return str[i]=='F';
    }
}

//check in map
  string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);

if(umap.find(temp) != umap.end())
{
    return umap[temp];
}
int ans=0;
//k will only place on operator 
for(int k= i+1;k<=j-1;k+=2)
{
    int lt = solve(str,i,k-1,true);
    int lf = solve(str,i,k-1,false);
    int rt = solve(str,k+1,j,true);
    int rf = solve(str,k+1,j,false);
    
if(str[k]=='&'){
    if(isTrue == true){
        ans = ans+(lt*rt);
    }
    else{
        ans=ans+(lt*rf)+(lf*rt) + (lf*rf);
    }
}
else if(str[k]=='|')
{
    if(isTrue == true){
        ans=ans+(lt*rf)+(lf*rt)+ (lt*rt);
    }
    else{
        ans = ans+(lf*rf);
    }
}
else if(str[k] == '^')
{
    if(isTrue == true){
        ans =ans + (lt*rf) +(lf*rt);
    }
    else{
        ans =ans+(lt*rt) + (lf*rf);
    }
}
}
return umap[temp]=ans%mod;
}
    int countWays(int N, string S){
   
        return solve(S,0,N-1,true);
    }
};
