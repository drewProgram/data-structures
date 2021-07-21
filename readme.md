# Data Structures
This repo has the purpose of further study of Data Structures with C++.

## Binary Tree
### Properties
#### 1. The maximum number of nodes at level 'l' of a binary tree is 2^l.
Here level is the number of nodes on the path from the root to the node (including root and node). Level of the root is 0. This can be proved by induction.

For root, l = 0, numbers of nodes = 2^0 = 1. Assume that the maximum number nodes on level 'l' is 2^l. Since in Binary Tree every node has at most 2 children, next level would have twice nodes, i.e 2 * 2^l.

#### 2. The maximum numbers of nodes in a binary tree of hight 'h' is 2^h - 1.
Here the height of a tree is the maximum number of nodes on the root to leaf path. Height of a tree with a single node is considered as 1.

This result can be derived from point 2 above. A tree has maximum nodes if all levels have maximum nodes. So maximum number of nodes in a binary tree of height h is 1 + 2 + 4 + .. + 2^h. This is a simple geometric series with h terms and sum of this series is 2^h - 1.

In some books, the height of the root is considered as 0. In this convention, the above formula becomes 2^(h+1) - 1.

#### 3. In a Binary Tree with N nodes, minimum possible height or the minimum number of levels is? Log2(N+1)?
This can be directly derived from point 2 above. If we consider the convention where the height of a root node is considered as 0, then above formula for minimum possible height becomes | Log2(N+1) | -1.

#### 4. A Binary Tree with L leaves has at least | Log2L? | + 1 levels
A Binary Tree has the maximum number of leaves (and a minimum number of levels) when all levels are fully filled. Let all leaves be at level l, then below is true for the number of leaves L.

### Types of binary tree
#### Full binary tree
When every node has 0 or 2 children.

#### Complete BT
When all the levels are completely filled except possibly the last level has all keys as left as possible.