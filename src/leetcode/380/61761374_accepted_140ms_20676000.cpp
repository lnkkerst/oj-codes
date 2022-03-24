class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> b;
    RandomizedSet() {
        b.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(b.find(val) != b.end()) return 0;
        b.insert(val);
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(b.find(val) == b.end()) return 0;
        b.erase(b.find(val));
        return 1;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rk = rand() % b.size();
        auto i = b.begin();
        for(int j = 0; j < rk; ++j)
            ++i;
        return *i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */