class Twitter {
public:
    int t;
    unordered_map<int, vector<pair<int,pair<int, int>>>>tweets;
    unordered_map<int, set<int>> followers; // userId-->{their followers}
    unordered_map<int, set<int>> followees; // userId-->{whom they follow}
    Twitter() {t=0;}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t,{tweetId, userId}});
        for (auto user : followers[userId]) {
            tweets[user].push_back({t,{tweetId, userId}});
        }
        t++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        set<int>seen;
        int sz = tweets[userId].size();
        sort(tweets[userId].begin(),tweets[userId].end());
        for (int i = sz - 1; i >= 0; i--) {
            pair<int, int> tmp = tweets[userId][i].second;
            if ((tmp.second == userId ||
                followees[userId].find(tmp.second) != followees[userId].end()) 
                && seen.find(tmp.first)==seen.end()) {
                feed.push_back(tmp.first);
                seen.insert(tmp.first);
            }
            if (feed.size() == 10)
                break;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followees[followerId].find(followeeId) ==
            followees[followerId].end()) {
            for (auto tweet : tweets[followeeId]) {
                tweets[followerId].push_back(tweet);
            }
        }
        followers[followeeId].insert(followerId);
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followers[followeeId].find(followerId) !=
            followers[followeeId].end()) {
            followers[followeeId].erase(followerId);
        }
        if (followees[followerId].find(followeeId) !=
            followees[followerId].end()) {
            followees[followerId].erase(followeeId);
        }
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