// online stock span
// leetcode - 901

class StockSpanner {
public:
    StockSpanner() {
        
    }
    // brute ->nested loops tc-o(n^2) sc-o(n)
    /*vector<int> arr;
    int next(int price)
    {
        int cnt = 1;
        if(arr.size()==0)
            arr.push_back(price);
        else{
            for(int i=arr.size()-1;i>=0;i--)
            {
                if(arr[i]<=price)
                    cnt++;
                else break;
            }
            arr.push_back(price);
        }
        return cnt;
    }*/

    // optimal -> monotonic stack tc-o(2n) sc-o(n)
    stack<pair<int,int>> st;
    int next(int price) {
        int cnt=1;
        if(st.empty())
            st.push({price,1});
        else{
                while(!st.empty() && st.top().first<=price)
                {
                    cnt = cnt+st.top().second;
                    st.pop();
                }
                st.push({price,cnt});
        }
        return cnt;
    }
};