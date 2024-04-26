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
#include <queue>
#include <utility>

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
    User() = delete;
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
    
    
    bool operator==(const User& o) const {
        return id == o.id;
    }
    
    friend class UserHash;
    
};

struct UserHash {
    size_t operator()(const User& user) const {
        return user.id;
    }
};

struct TweetCmp {
    bool operator()(const Tweet *t1, const Tweet *t2) {
        return t1->timestamp < t2->timestamp;
    }
};

struct UserTweetCmp {
    bool operator()(const std::pair<int, User*> & ut1, const std::pair<int, User*> & ut2) {
        return ut1.second->getTweets()[ut1.first] < ut2.second->getTweets()[ut2.first];
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
        std::priority_queue<std::pair<int, User*>, std::vector<std::pair<int, User*>>, UserTweetCmp> pq;
        
        for (const auto& followee : followees) {
            int id = followee.second->getTweets().size()-1;
            if (id >= 0) {
                pq.push({id, followee.second});
            }
        }
        
        int count = 0;
        std::vector<int> feed;
        while (!pq.empty() && count < 10) {
            const auto tweetIdUser = pq.top();
            int tweetId = tweetIdUser.first;
            User *user = tweetIdUser.second;
            Tweet *tweet = user->getTweets()[tweetId];
            feed.push_back(tweet->id);
            
            pq.pop();
            
            if (tweetId > 0) {
                pq.push({tweetId-1, user});
            }
            count++;
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
