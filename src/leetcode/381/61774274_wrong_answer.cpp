class RandomizedCollection {
public:
  /** Initialize your data structure here. */
  unordered_map<int, int> b;
  RandomizedCollection() {
    b.clear();
  }

  /** Inserts a value to the collection. Returns true if the collection did
   * not already contain the specified element. */
  bool insert(int val) {
    bool ret = b[val];
    ++b[val];
    return !ret;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    int ret = b[val];
    if (!ret) {
      return 0;
    }
    --b[val];
    return 1;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    for (auto i = b.begin(); i != b.end(); ++i) {
      if (i->second) {
        return i->first;
      }
    }
    return 1;
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
