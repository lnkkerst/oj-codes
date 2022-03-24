class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    multiset<int> b;
    RandomizedCollection() {
        b.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto t = b.find(val);
        bool ret = (t == b.end());
        b.insert(val);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto t = b.find(val);
        bool ret = (t != b.end());
        if(ret) b.erase(t);
        return ret;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // srand(time(NULL));
        int rk = (rand() % b.size()) * rand() % b.size();
        auto t = b.begin();
        for(int i = 0; i < rk; ++i)
            ++t;
        return *t;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */