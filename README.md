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

#### Weekly contest May 22th(3/4):
1. Weekly contest 2278. Percentage of Letter in String - Easy!
2. Weekly contest 2279. Maximum Bags With Full Capacity of Rocks - Greddy. Vey easy!
3. Weekly contest 2280. Minimum Lines to Represent a Line Chart - I use slope of two points to judge whether these 3 points lies in the same line. But I didn't realize the overflow of double. The improvement is using dot multiple (of course you can't use int!)
4. Weekly contest 2281. Sum of Total Strength of Wizards - Very difficult!!! It's amazon's intern question. Using monotonic stack to search for the covering range of each number. Then using summation formula to induct how to get result with a linear time complexity. Lastly, when you should mod is crucial. If you mod in the last step, it will overflow although you use long long type.

#### 5.22
1. leetcode 907. Sum of Subarray Minimums - It's monotonic stack typical application. Also it's tramsformation of weekly contest 2280. !!! You should know how the stack is complemented by each step. Of course there is a less time complexity solution but I still suggest you use two loops.
2. leetcode 496. Next Greater Element I - Review but I still to solve it in time. I strongly suggest you follow the instruction by labuladong.

#### 5.23
1. leetcode 1038. Binary Search Tree to Greater Sum Tree - Review but I still to solve it in time. The most important part in this question is how to convey the value to the left child tree. - Tips: If you traverse BST inorder, you will get a ascent array. If you traverse BST inorder reversely, you will get a descent array. Thus, you just need a global value to store the result.
2. leetcode 98. Validate Binary Search Tree - The most crucial one is also how to validate the child tree's all elements and the root node. The solution is same as the former question. You just need to define a global value(named: pre) to point to the root. The "pre" points to every element in the ascent array.
3. leetcode 700. Search in a Binary Search Tree - Nothing special!
4. leetcode 701. Insert into a Binary Search Tree - The sceond solution shown in example is to confuse you. Don't change the BST original shape! Or it will be very difficult! You need to find the suitable leaf node and insert your node into it.
5. leetcode 450. Delete Node in a BST - There are two difficult points. The first one is how can you delete a node without know its father node. Of course you can use parenet poniter to record it but I think it will be very difficult. The most conveient way is to use recursion and the root's(at each call to recursion) child point to the return value(? maybe my description is not very clear). So you don't need an extra pointer. The second one is Classified discussion. 1. the target node has no children 2. the target node has left child 3. the target node has right child 4. the target node has two non-empty children. As for the situation 4, you just need to cut the target node's left child to the left child of the most left node in the target node's right child. (Little confusing, ha)

#### 5.24
1. leetcode 96. Unique Binary Search Trees - Using BST attribute. It's very easy to analyze. Carl's mathod is too messy! You only need to know all elements in the left child tree are smaller than the root and all the elements in the right child tree are larget. Thus, you only need to construct a recursion. In order to reduce duplicate calculation, you can use memory search.
2. leetcode 95. Unique Binary Search Trees II. Although this question looks similar to lc 96. But lc 95 only can be solved by BF. The most crucial is: how BF? The answer is listing all the possible root and using the same method to construct the same left and right child tree. But you'd better notice when we should initialize the root node.
3. leetcode 912. 
Sort an Array - Quick Sort. Although it's one of the most basic algorithms in DS. But it's still not very easy to complement in time correctly. The most error prone place is the border condition. 1. The i and j s' meaning and initialization. 2.  The condition expression in the outer-while loop. 3. The condition expression in the inner-while loop. 4. If i >= j in the outer-loop, what we should do next? 5. What we should do before we return value? 6. What should be returned?   
What's more, the quicksort can be seen as the construction of a BST. The mergesort is postorder traverse and the quciksort is inorder traverse.
4. leetcode 215. Kth Largest Element in an Array - Easy
5. leetcode 384. Shuffle an Array - Reviewing the Fisher-Yates Shffle Algorithms. The most crucial part of the algorithm is how to validate's algorith(The function can generate n! kinds of possible result)

### Long time no see!!

#### 6.4 
1. leetcode 207. Course Schedule - Check whether there is a circle in the graph. 1. Create the graph 2. traverse the graph and determine if a circuit exists in the graph
2. leetcode 210. Course Schedule II - The most crucial point is you have to know the postorder of traverse is the reversion of topological sort series.
3. leetcode 111. Minimum Depth of Binary Tree - There are two common solutions to deal with. The first one is DFS. It is less space cost but more time cost. The other is BFS, which might cost much more space but you don't have to traverse all the tree nodes.
4. leetcode 752. Open the Lock - I know I should use BFS, but I don't know how to traverse the whole solution space. The key is to build two functions. The first one is dialing upwards and the other is dialing downwards.

#### 6.5 
1. leetcode 773. Sliding Puzzle - Same as lc 752, the problem I did yesterday. I know I should use BFS but I don't how to traverse the whole solution space... The key is knowing how to describe the blank's moving. Each position has different moving pattern. In this case, you can use a two dimension array to record the moving pattern. 
2. leetcode 277. Find the Celebrity - It's a typical graph problem. You can use a vector which store many pair recording each node's indegree and outdegree. The target is the indegree should be n - 1 and outdegree should be 0.
3. leetcode 997. Find the Town Judge - Same as lc 277

#### 6.6
1. leetcode 130. Surrounded Regions. Same as lc 773. In this case, we can use a moving function to record the possible next status. If the next status is invalid, we can add a validation check. One more thing, you should pay attention to the problem of duplicate insert! You have to change the value insdie the for loop but not 
2. leetcode 323. Number of Connected Components in an Undirected Graph - Use union find
3. leetcode 990. Satisfiability of Equality Equations - Use UF. But you have to scan the array twice or you will miss the impact from the order. If the test example is ["a==b","b!=c","c==a"], you have to check the unequal relationship again!

#### 6.7
1. leetcode 261. Graph Valid Tree - Union find application. If you know how to create a uf, it is not difficult.
2. leetcode 1135. Connecting Cities With Minimum Cost - Same as before.
3. leetcode 1584. Min Cost to Connect All Points - Kruskral or Prim algorithm. But in this problem, you have to use Prim algorithm or it will be TLE!

#### 6.8
1. leetcode 785. Is Graph Bipartite? - You can use two array, the first one is the visited array, the visited array is used to record whether a node has been visited or not. The second one is used to record the color. By the way, you should use memset() or fill() to initialize the dynamic array.
2. leetcode 886. Possible Bipartition - I have to record this quesiton. There is a very implicit condition inside. If A dislikes B, B must dislike A. While, it may be very difficult to understand. In our daily life, the hate for a person might be one direction. But in this quesion, the hate must be bidirectional. If A dislike B, A and B can not be in the same group, so the graph should record bidirectional edges

#### 6.9
1. leetcode 743. Network Delay Time - Basic Dijkstra algorithm's application. Labuladong's note is quite good! You should understand the essence of this algorithm. Furthermore, you should learn how to use emplace() API in the STL.
2. leetcode 1514. Path with Maximum Probability - the maximum problem in Dijkstra algorithm. Many people think D's algorithm can only be used in the minimum problem while that's a huge mistake!
3. leetcode 1631. Path With Minimum Effort - Pay attention! Labuladong doesn't mention that if you want to exit the loop in advance, you have to use priority_queue! Also, you have to understand the priority_queue in STL or you might convert the order!

### Long time no see!!
#### 6.19
1. leetcode 146. LRU Cache - Use two basic data structure. The map is used to visit the node in O(1), and the doule list is used to record the order. If a node is visited, it should be taken to the tailer position. When you want to put one more node but you find the cache is full, you can move the head node.

#### 6.20
1. leetcode 460. LFU Cache - The key of this question is how to record the frequency and delete the node by frequency. You can use two maps to record the nodes(the second one should record the iterator of the node so that you can operate the origin node). YThe first one record the frequency and the second on record the key. Both of them have access to the nodes. The key is to understand the process completely. What you should do if you recall get() and put().


### Long time no see!!!
#### 6.29
1. leetcode 208. Implement Trie (Prefix Tree) - The note of labuladong is too hard to handle at first. The simple edition is also ok.
2. leetcdoe 648. Replace Words - Use a new API - stringstream to handle the string with space split.
3. leetcode 211. Design Add and Search Words Data Structure - The most difficult part is how to deal with wildcard character. We could use DFS to skip current node.
4. leetcode 677. Map Sum Pairs - At first I made a mistake. I give every node a value. In fact, we should just give the value to the end of the word in the dictionary.

### Long time no see!!!
#### 7.27
1. leetcode 295. Find Median from Data Stream - Key is to use two priority queue to record the numbers larger than the middle and the numbers smaller or euqal than the middle. What's more, you should notice that the different size of these two queues should be less than 2! Specifically, the queMin.size() >= queMax.size()