class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 2) return 0; // It will be easier for me to make sure the border. If I don't use a if sentence, the exceeding of array will happen

        int* maxLeft = new int[size];
        int* maxRight = new int[size];

        maxLeft[0] = height[0]; // initialize the array
        for (int i = 1; i <= size - 1; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]); // State transition equation 
        }

        maxRight[size - 1] = height[size - 1];
        for (int j = size - 2; j >= 0; j--) {
            maxRight[j] = max(maxRight[j + 1], height[j]);
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) result += count;
        }
        return result;
    }
};

