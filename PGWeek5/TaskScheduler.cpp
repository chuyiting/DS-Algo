//
//  TaskScheduler.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/24.
//

#include "TaskScheduler.hpp"
#include <queue>
#include <unordered_map>
#include <utility>

struct FreqCmp{
public:
    bool operator()(const std::pair<char, int>& t1, const std::pair<char, int>& t2) {
        return t1.second < t2.second;
    }
};

int TaskScheduler::leastInterval(std::vector<char>& tasks, int n) {
    if (tasks.size() == 0)
        return 0;
    std::unordered_map<char, int> freq;
    for (auto& task : tasks) {
        freq[task]++;
    }

    std::priority_queue<std::pair<char, int>,
                        std::vector<std::pair<char, int>>, FreqCmp>
        maxHeap;

    for (auto& p : freq) {
        maxHeap.push(p);
    }

    std::queue<std::pair<int, std::pair<char, int>>> waitList;
    int i = 0;
    while (!maxHeap.empty() || !waitList.empty()) {
        if (!waitList.empty()) {
            while (!waitList.empty() &&  waitList.front().first < i) {
                maxHeap.push(waitList.front().second);
                waitList.pop();
            }
        }

        if (maxHeap.empty()) {
            i++;
            continue;
        }

        auto& task = maxHeap.top();
        std::pair<char, int> taskCpy(task);

        taskCpy.second--;
        if (taskCpy.second > 0 && n > 0) {
            waitList.push({i + n, taskCpy});
        }
        maxHeap.pop();
        i++;
    }

    return i;
}
