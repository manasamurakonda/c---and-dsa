// GFG - Rod Cutting
class Solution {
  public:
    int recursion(int ind,vector<int> &price,int length)
    {
        if(ind==0)
        {
            if((length%(ind+1))==0)
                return ((length/(ind+1))*price[ind]);
            return 0;
        }
        int take=0,not_take=0;
        if(length>=ind+1)
            take = price[ind]+recursion(ind,price,length-(ind+1));
        not_take = recursion(ind-1,price,length);
        return max(take,not_take);
    }
    int memoization(int ind,vector<int> &price,int length,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if((length%(ind+1))==0)
                return ((length/(ind+1))*price[ind]);
            return 0;
        }
        
        if(dp[ind][length]!=-1)
            return dp[ind][length];
        int take = 0,not_take = 0;
        if(length>=ind+1)
            take = price[ind]+memoization(ind,price,length-(ind+1),dp);
        not_take = memoization(ind-1,price,length,dp);
        return dp[ind][length] = max(take,not_take);
    }
    int cutRod(vector<int> &price) {
        // recursion
        /*int n = price.size();
        return recursion(n-1,price,n);*/
        
        // memoization
        /*int n = price.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return memoization(n-1,price,n,dp);*/
        
        // tabulation
        /*int n = price.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        for(int i=1;i<=n;i++)
        {
            dp[0][i] = i*price[0];
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int length=0;length<=n;length++)
            {
                int take = 0,not_take=0;
                if(length>=ind+1)
                    take = price[ind]+dp[ind][length-(ind+1)];
                not_take = dp[ind-1][length];
                dp[ind][length] = max(take,not_take);
            }
        }
        return dp[n-1][n];*/
        
        // space optimization
        int n = price.size();
        vector<int> dp(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            dp[i] = i*price[0];
        }
        for(int ind=1;ind<n;ind++)
        {
            vector<int> temp(n+1,-1);
            for(int length=0;length<=n;length++)
            {
                int take = 0,not_take=0;
                if(length>=ind+1)
                    take = price[ind]+temp[length-(ind+1)];
                not_take = dp[length];
                temp[length] = max(take,not_take);
            }
            dp = temp;
        }
        return dp[n];
    }
};