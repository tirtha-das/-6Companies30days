class DataStream {
    queue<int>lastKDigits;
    int curCount;
    int value;
    int k;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        curCount = 0;
    }
    
    bool consec(int num) {
        lastKDigits.push(num);
        if(num==value){
            curCount++;
        }
        if(lastKDigits.size()>k){
            if(lastKDigits.front()==value){
                curCount--;
            }
            lastKDigits.pop();
        }

        return (curCount==k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */