## 2022
### April
#### 4.25
1. leetcode 25 - Reverse Nodes in K-Group: It's little tricky for setting the parameters. The sencond node can not be reached
#### 4.26
1. leetcode 234 - Palindrome Linked List. There are two ways. The first one is finding(via two pointers) the middle of the list and then reversing the former. The other one is using recursion, which will not destroy the origin structure of the list but it's space complexity will not be constant.
2. leetcode 303 - A very good question about dynamic programming! The first time when I meet LC 303, I didn't realize dp could be used in this way.
3. leetcode 304 - Pay attention to the boarder condition!
#### 4.27
1. leetcode 560 - First, you should know how to use preSum array to reduce the time complexity(although it still fails to AC). Then, you can use hashmap to store nums[j], which will reduce time complexity for another time.
2. leetcode 370 - Difference array is the opposite form of preSum array. But both of them can reduce time complexity and show the essence of dynamic programming!
3. leetcode 1109 - same as 370
#### 4.28(4.30补一题)
1. leetcode 1094 - nothing special.
2. leetcode 167 - Pay attention to the quesiton - non decreasing array! So the first thing you need to know is using binary search.
#### 4.29(4.30补)
1. leetcode 26 - nothing sepcial. I do it very fast
2. leetcode 83 - nothing sepcial. I do it very fast
3. leetcode 27 - nothing sepcial. I do it very fast
#### 4.30
1. leetcode 283 - nothing sepcial. I do it very fast
2. leetcode 167 - nothing sepcial. I do it very fast
3. leetcode 5 - The way of judging whether it's palindrome string is crucial. Although these two ways' the time complextiy are same, the arguments will not be the same, which will increase time complexity by n times if you choose the worse one.
#### 5.1
##### Weekly contest:
😅第一题十五分钟写出来，找bug花了大半个小时，一会是循环的自增条件没写，一会是数组越界，花了好久才ac，第二题一眼过去就是hashmap，五分钟写出来，但是老是wa，找了半天bug超时了，后来去vs2019一跑发现是三目运算冒号两侧写反了😅
周赛，我劝你多打！😅难绷
##### Tricky traversal:
1. leetcode 48 - Rotate the matrix by its diagonal. Then reverse each row.
2. leetcode 54 - Remember four bounds. Traverse in a specific order by using these bounds instead of 代码随想录, which is too difficult to understand and recall efficiently.
3. leetcode 59 - same as 54
#### 5.2（5.3补）
1. leetcode 76 - Understanding the sliding window frame
2. leetcode 567 - Same as above
3. leetcode 438 - Same as above
#### 5.3 
1. leetcode 3 - Pay attention to loop condition! you can use window[c] > 1 to make sure the left points to right pos.
2. leetcode 704 - Nothing special
3. leetcode 34 - How to define the left and right border by binary search? You just need to change the finishing condition. What's more, the final result may conclude illgal position, which means you should check it before return value(the order of if condition is crucial!) 
#### 5.4
##### The random alforithm is quite new for me. I think the quesitons selected by labuladong are quite good except for his tuition.😅
1. leetcode 380. Insert Delete GetRandom O(1) - Using multi data structure to acheive some functions with constant time complexity
2. leetcode 710. Random Pick with Blacklist - Although my method is also constant time complexity, I still get TLE😅. But the answer is quite tricky, labuladong doesn't need a new vector. He builds a link between those blacklist numbers and normal ones via hashmap.
3. leetcode 382. Linked List Random Node - I use a vector to store each node, which costs a huge space waste. Labuladong uses mathematics method to decide each node's chance of being updated. Quite tricky! 
#### 5.5
1. leetcode 384. Shuffle an Array - Using Fisher-Yates-Shuffle Algorithm, which is similar to Reservoir Sampling Algorithm.
2. leetcode 528. Random Pick with Weight - Using preSum array and binary search. There are lots of details so it's not easy to finish it.
3. leetcode 875. Koko Eating Bananas - Another perspective for me to use binary. All the increasing or decreasing array can use binary search. This method didn't come to my mind at first, on the contarary, I use linear search. Of course it will exceed the time limits.
#### 5.6
1. leetcode 1011. Capacity To Ship Packages Within D Days - Same as 875. Koko Eating Bananas
2. leetcode 410. Split Array Largest Sum - This question and the previous questions - 1011. Capacity To Ship Packages Within D Days are one and two sides of generalized binary search.
3. leetcode 870. Advantage Shuffle - Greedy algorithm. You have to use pair to record the B[i]'s position or it will exceed time limit.
#### 5.7（5.8补2，3）
I rarely meet monotonic stack question so I can't recall it immediately. The next step is learning labuladon's list and set up a regulation to review the question done before.
1. leetcode 739. Daily Temperatures
2. leetcode 496. Next Greater Element I 
3. leetcode 503. Next Greater Element II

