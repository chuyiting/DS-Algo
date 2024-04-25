//
//  DesignTwitter.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/24.
//

#ifndef DesignTwitter_hpp
#define DesignTwitter_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

typedef int userId_t;

struct Tweet {
    int id;
    int timestamp;
    Tweet(int id, int timestamp) : id(id), timestamp(timestamp) {};
};

class User {
    userId_t id;
    std::unordered_map<userId_t, User*> followees;
    std::vector<Tweet*> tweets;
public:
    User(userId_t id) {
        this->id = id;
        this->followees[id] = this;
        this->tweets = {};
    }
    std::unordered_map<userId_t, User*>& getFollowees() {
        return followees;
    }
    
    std::vector<Tweet*>& getTweets() {
        return tweets;
    }
    
    void addFollowee(User *user) {
        this->followees[user->id] = user;
    }
    
    void postTweet(Tweet *tweet) {
        this->tweets.push_back(tweet);
    }
    
    
};

struct TweetCmp {
    bool operator()(const Tweet *t1, const Tweet *t2) {
        return t1->timestamp < t2->timestamp;
    }
};

class Twitter {
    std::unordered_map<userId_t, User*> users;
public:
    static int timestamp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto* tweet = new Tweet(tweetId, timestamp);
        if (users.count(userId) == 0) {
            auto* user = new User(userId);
            this->users[userId] = user;
        }
        users[userId]->postTweet(tweet);
        timestamp++;
    }
    
    std::vector<int> getNewsFeed(int userId) {
        if (users.count(userId) == 0) return {};
        auto &followees = users[userId]->getFollowees();
        std::vector<int> currIds(followees.size());
        int i = 0;
        for (const auto& followee : followees) {
            currIds[i] = followee.second->getTweets().size()-1;
            i++;
        }
        
        int j = 0;
        bool moreFeedExist = true;
        std::vector<int> feed;
        
        while (j < 10 && moreFeedExist) {
            moreFeedExist = false;
            int k = 0;
            Tweet* latestTweet = nullptr;
            int latestK = 0;
            
            for (const auto& followee : followees) {
                if (currIds[k] >= 0 && followee.second->getTweets()[currIds[k]]->timestamp > latestTweet->timestamp) {
                    latestTweet = followee.second->getTweets()[currIds[k]];
                    latestK = k;
                    moreFeedExist = true;
                }
                k++;
            }
            
            if (moreFeedExist) {
                feed.push_back(latestTweet->id);
                j++;
                currIds[latestK]--;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (users.count(followerId) == 0) {
            auto* follower = new User(followerId);
            this->users[followerId] = follower;
        }
        
        if (users.count(followeeId) == 0) {
            auto* followee = new User(followeeId);
            this->users[followeeId] = followee;
        }
        
        this->users[followerId]->addFollowee(this->users[followeeId]);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (users.count(followerId) == 0) {
            auto* follower = new User(followerId);
            this->users[followerId] = follower;
        }
        
        if (users.count(followeeId) == 0) {
            auto* followee = new User(followeeId);
            this->users[followeeId] = followee;
        }
        
        this->users[followerId]->getFollowees().erase(followeeId);
    }
};

int Twitter::timestamp = 0;
#endif /* DesignTwitter_hpp */
