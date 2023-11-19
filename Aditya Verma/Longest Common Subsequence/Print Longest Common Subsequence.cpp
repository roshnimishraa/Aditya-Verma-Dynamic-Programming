
Approach : Longest Common Subseuences 

int t[1002][1002];
int lcs(int n,int m,string &s1,string &s2){
//initialization 
for(int i=0;i<m+1;i++)
{
	for(int j=0;j<n+1;j++){
	if(i==0 || j==0){
	t[i][j] = 0;
	}

	}
}

for(int i=1;i<m+1;i++){
	for(int j=1;j<n+1;j++){
	if(s1[i-1] == s2[j-1]){
t[i][j] = 1 + t[i-1][j-1];
	}
else{
	t[i][j] = max(t[i-1][j], t[i][j-1]);
}
	}
}
return t[m][n];
}
string findLCS(int n, int m,string &s1, string &s2)
{
int result = lcs(n,m,s1,s2);
int i = m,j=n;
string s = "";
while(i>0 && j>0){
	if(s1[i-1] ==s2[j-1]){
		s.push_back(s1[i-1]);
		i--;
		j--;
	}
	else{
if(t[i][j-1] > t[i-1][j]){
	j--;
}
else {
	i--;
}
	}
}
reverse(s.begin(),s.end());
return s;
}
