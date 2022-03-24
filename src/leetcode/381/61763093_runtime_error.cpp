class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_set<int> b;
    RandomizedCollection() {
        b.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(b.find(val) != b.end()) return 0;
        b.insert(val);
        return 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(b.find(val) == b.end()) return 0;
        b.erase(b.find(val));
        return 1;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return *b.begin();
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */