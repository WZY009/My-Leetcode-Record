* pay attention to the check condition in preorder and postorder traversal, because you have to check whether the treenode is null, if the tree node is null, but you still try to use it's left node. you can not be accepted
* pay attention to none recursive preorder traversal, especially the order of putting the node into stack 
* Let's look at the post order traversal. The pre order traversal is left and right, and the subsequent traversal is left and right. Then we only need to adjust the code order of the next pre order traversal. 
The sequence becomes the middle right and left traversal sequence, and then the result array is reversed, and the output result sequence is left and right.
* I think in the lc 94, the mostleftnode is the most suitable name for it. Because in the inorder traversal problem, we need to find the most left node(you can search for the definity of "most left node") so as to find the first output. and then we need to find whether the most left node has child right tree. so we can let the mostLeftNode = mostLeftNode->right