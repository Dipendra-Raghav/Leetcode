class MyHashMap {
public:
    vector<int> nums;
    MyHashMap() {
        
        for(int i=0;i<=10000001;i++)
            nums.push_back(-1);
    }
    
    void put(int key, int value) {
        nums[key]=value;   
    }
    
    int get(int key) {
        return nums[key];
    }
    
    void remove(int key) {
        nums[key]=-1;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */