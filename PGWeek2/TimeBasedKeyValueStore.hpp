//
//  TimeBasedKeyValueStore.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/6.
//

#ifndef TimeBasedKeyValueStore_hpp
#define TimeBasedKeyValueStore_hpp

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>

class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> storage;

public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        if (storage.count(key)) {
            storage[key].push_back({timestamp, value});
        } else {
            storage[key] = {{timestamp, value}};
        }
    }
    
    std::string get(std::string key, int timestamp) {
        if (!storage.count(key)) {
            return "";
        }
        
        auto &bucket = storage[key];
        if (bucket[bucket.size()-1].first > timestamp) {
            return "";
        }
        
        int l = 0, r = bucket.size()-1;
        std::string currMaxTs = "";
        while (l <= r) {
            int mid = (l+r) / 2;
            if (bucket[mid].first == timestamp) {
                return bucket[mid].second;
            } else if (bucket[mid].first > timestamp) {
                r = mid-1;
            } else {
                currMaxTs = bucket[mid].second;
                l = mid+1;
            }
        }
        return currMaxTs;
    }
    
};

#endif /* TimeBasedKeyValueStore_hpp */
