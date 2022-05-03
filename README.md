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
结论：多打周赛！
##### Tricky traversal:
1. leetcode 48 - Rotate the matrix by its diagonal. Then reverse each row.
2. leetcode 54 - Remember four bounds. Traverse in a specific order by using these bounds instead of 代码随想录, which is too difficult to understand and recall efficiently.
3. leetcode 59 - same as 54
#### 5.2（5.3补）
1. leetcode 76 - Understanding 