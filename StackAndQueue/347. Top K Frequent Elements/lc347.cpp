class compare {
    //about min-STL priority queue:
    // https://stackoverflow.com/questions/26269650/understanding-operator-overloading-with-min-stl-priority-queue
public:
    bool operator() (const pair<int, int>& pair1, const pair<int, int>& pair2) { // 
        return pair1.second > pair2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // the first step is to create a map!
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size();) {
            map[nums[i++]]++;
        }
        // the second step is to convert the Top k frequence number
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        for (auto it = map.begin(); it != map.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        // the third step is to convert the priority_queue to vector
        vector<int> result;
        for (int i = k - 1; i >= 0; i--) {
            int temp = que.top().first;
            que.pop();
            result.push_back(temp);
        }
        return result;
    }
};
