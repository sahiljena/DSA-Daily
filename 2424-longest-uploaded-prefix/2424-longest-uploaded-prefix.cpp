class LUPrefix {
public:
    unordered_set<int> s;
    int cnt=0;
    LUPrefix(int n) {

    }
    
    void upload(int video) {
        s.insert(video);
        while(s.count(cnt+1)) cnt++;
        
    }
    
    int longest() {
       
        return cnt;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */