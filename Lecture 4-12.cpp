//Binary Search Trees
/*
- Given: Data items that have unique KEYS
- Definition: T is either empty or it has a special node called a ROOT NODE
              OR it has 2 sets of nodes LsubT and RsubT, called the left
              sub tree and right right sub tree
              - The key in the root node is larger than every key in the left
              sub tree
              - It is also smaller than everything in the right sub tree
              - The left and right sub tree are binary search trees
              Ex: There is a root pointer that is the root of the tree
              - If it is an empty tree it is a null pointer
              - If the node is pointing to some data (open to interpretation)
                there is a left and sub right tree where the left tree is less
                than the root and the right is greater than the root
                MAKE SURE TO SEE PIC ON PHONE
              - A binary search tree is a special case of a binary tree
- It is a linked implementation using a linked list
- Example operations:
    - Array:
        - Search: Unordered- Linear (O(N))
                  Ordered- Binary (O(LogN))
        - Insert: Unordered- Constant Time (O(1))
                  Ordered- (O(N))
        - Delete: Unordered- O(N)
                  Ordered- O(N)
    - Binary is the best way to go about this when speaking about
    efficiency
    SEE NEW PROJECT!!!!

- Traversals:
    - In order traversal:
        - Will be done on either the left or right trees/subtrees
    - Pre-order traversal:
        All the way to the left, then all the way to the right
    - Post-order traversal:
        - root gets printed last

- Deleting Nodes:
    - very tricky, we must search first

-FOR EXAM: Be able to draw binary search tree and understand the process of all traversal algorithms






*/
