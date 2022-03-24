class Twitter {
public:
    unordered_map<int, unordered_map<int, bool> > a;
    vector<pair<int, int> > pt;
    /** Initialize your data structure here. */
    Twitter() {
        a.clear();
        pt.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        pt.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        int cnt = 0;
        for(auto i = pt.rbegin(); i != pt.rend(); ++i) {
            if(cnt >= 10) break;
            if(i->first == userId || a[userId][i->first]) {
                ++cnt;
                ret.push_back(i->second);
            }
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        a[followerId][followeeId] = 1;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        a[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */