class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        else{
            auto temp=st.top();
            int cnt = 0;
            while(temp.first<=price){
                auto t = st.top();
                cnt+=t.second;
                st.pop();
                if(st.empty()) break;
                temp=st.top();
            }
            st.push({price,cnt+1});
            //cout<<cnt+1<<endl;
            return cnt+1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */