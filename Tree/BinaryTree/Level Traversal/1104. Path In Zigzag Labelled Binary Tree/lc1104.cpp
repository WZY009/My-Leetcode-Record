class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log(label) / log(2);
        vector<int> res(level + 1);
        int i = level;
        while (label != 0) {
            res[i--] = label;
            label /= 2;
        }
        for (int i = 1 + (level & 1); i < res.size() - 1; i += 2) {
            res[i] = pow(2, i + 1) - 1 - (res[i] - pow(2, i)); 
        }
        return res;
    }
};
