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
#### 5.8
##### Weekly contest:
第一题十五分钟写出来，速度还应该再快一点！
第二题用了半个小时，属实难绷，主要是很久没有练二叉树题目了，对遍历有点手生，事实证明，周赛是极为有必要的！不仅能锻炼面试临场反应，也能锻炼手动构造example testcases，还能不定期复习一下已经生疏的知识点。
第三题没做出来，主要还是长久不练DP,也没有形成自己的一套对于DP问题深入理解的体系，最近事情实在太多，dp这种比较难的问题先暂时放一放，把线性表、树、图这些数据结构练的熟熟透透再好好琢磨一下，当然，每周适当的做一点还是ok的。
总结：参加周赛，十分必要，以快制快，压茬推进，层层压实，应来尽来，非必要不缺席
#### 5.9(5.10 补)
1. leetcode 316. Remove Duplicate Letters - Using monotonic stack's idea. There are three constraints. The first step is to fulfill the first two constraints. Using a stack and a isInStack map can be very easy to make it. Then, we can use another map to record whether the same letter will appear in the left string.
2. leetcode 104. Maximum Depth of Binary Tree - Nothing special
3. leetcode 543. Diameter of Binary Tree - Although this question is very easy and it has been sloved in the 2021 算法分析与设计 final exam. I find a better solution in the labuladong's tuition. In each traversal process, I can update the max diameter. So I don't need to travere the whole child-tree in each traversal.
#### 5.10
1. leetcode 144. Binary Tree Preorder Traversal - Nothing special
2. leetcode 226. Invert Binary Tree - That's a horrible record that I can't make it!!! Why? I think the reason is that I don't get deep understand of traversal process and mistake the meaning of quesiton! I use level traversal at first, which is a huge mistake! 
3. leetcode 116. Populating Next Right Pointers in Each Node - I use level traversal. But labuladong uses a new way that I've never seen it before. He put two nodes together so as to view the 2-forks tree as a 3-forks tree. He only needs to link the node1->next to node2.

### Long time no see!!!
#### 5.18 
1. leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal - Well done. At this time, I use reference convey so as to reduce space cost. In Dec. 25th 2021, I don't really understand that.
2. leetcode 654. Maximum Binary Tree - Well done!
#### 5.19 
1. leetcode 889. Construct Binary Tree from Preorder and Postorder Traversal - Don't confuse this question and lc 105! You should use less than 2 minutes to slove it.
2. leetcode 297. Serialize and Deserialize Binary Tree - Two method. The first one is preorder traversal, the other one is using descent traversal. The details
3. leetcode 652. Find Duplicate Subtrees - The key point is serialization! A vital fact: Any preorder and postorder series(include null pointer) can represent a unique binary tree! Serialize the subtree and store it into a umap. Every time you can check whether there is a same series in the umap.
#### 5.20 
1. leetcode 912. Sort an Array - Don't think mergesort() is very easy to build! You have to understand how sort() and merge() worked! Specially merge()
2. leetcode 88. Merge Sorted Array - Using reverse dual pointers to reduce space complexity! A tricky way!
3. leetcode 315. Count of Smaller Numbers After Self - A kind of partial relation question. The details are very clear in the labuladong's explanation!
#### 5.21 
1. leetcode 493. Reverse Pairs - A kind of partial relation question. Mergesort is very convenient to slove partial relationship problem. You just need to add something in merge() so as to get the result. But remember, you can use ascending attribute to optimize the process.
2. leetcode 327. Count of Range Sum - This question is very tricky. You need to use preSum to reduce the order of array. Then, you use mergesort to record the pair meeting the requirement. The details are shown in https://leetcode.cn/problems/count-of-range-sum/solution/qu-jian-he-de-ge-shu-by-leetcode-solution/
3. leetcode 230. Kth Smallest Element in a BST - Just like kth smallest element in a descending array. I just use a inorder traversal to slove it easily.
