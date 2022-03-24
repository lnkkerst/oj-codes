class BrowserHistory {
public:
    vector<string> a;
    int now;
    BrowserHistory(string homepage) {
        a.push_back(homepage);
        now = 0;
    }
    
    void visit(string url) {
        a.erase(a.begin() + now + 1, a.end());
        a.push_back(url);
        now = a.size() - 1;
    }
    
    string back(int steps) {
        now = max(0, now - steps);
        return a[now];
    }
    
    string forward(int steps) {
        now = min((int)a.size() - 1, now + steps);
        return a[now];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */