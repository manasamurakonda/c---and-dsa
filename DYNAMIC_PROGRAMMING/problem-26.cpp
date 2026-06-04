// print longest common subsequence
// code 360 by coding ninjas
string findLCS(int n1, int n2,string &s1, string &s2){
    // optimal -> deived from tabulation code of lcs problem
	vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
	for(int ind1=0;ind1<=n1;ind1++)
            dp[ind1][0] = 0;
    for(int ind2=0;ind2<=n2;ind2++)
        dp[0][ind2] = 0;
    for(int ind1=1;ind1<=n1;ind1++)
    {
        for(int ind2=1;ind2<=n2;ind2++)
        {
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
            else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
	int i = n1,j=n2;
	string ans = "";
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans.push_back(s1[i-1]);
			i = i-1;
			j = j-1;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1])
				i = i-1;
			else j = j-1;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}