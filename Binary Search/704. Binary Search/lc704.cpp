/*
二分查找涉及的很多的边界条件，逻辑比较简单，但就是写不好。例如到底是 while(left < right) 还是 while(left <= right)，到底是right = middle呢，还是要right = middle - 1呢？

大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，区间的定义就是不变量。要在二分查找的过程中，保持不变量，就是在while寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则。

写二分法，区间的定义一般为两种，左闭右闭即[left, right]，或者左闭右开即[left, right)。
这里采用左闭右闭
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) >> 1;
        while (left <= right) {
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                right = mid - 1;
                mid = left + ((right - left) >> 1);
            }
            else {
                left = mid + 1;
                mid = left + ((right - left) >> 1);
            }
        }
        return -1;
    }
};