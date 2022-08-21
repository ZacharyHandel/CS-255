#include<iostream>
using namespace std;

struct treeNode;
typedef treeNode* treeNodePtr;

struct treeNode
{
    treeNodePtr left;
    int         data;
    treeNodePtr right;
};

class BinarySearchTree
{
    private:
        treeNodePtr root;
        void inorder(treeNodePtr ptr);
        void preorder(treeNodePtr ptr);
        void postorder(treeNodePtr ptr);
        int TreeHeight(treeNodePtr ptr);
    public:
        BinarySearchTree(); //constructor
        void insert(int);
        bool isEmpty() const;
        void print_inorder();
        void print_preorder();
        void print_postorder();
        int findHeight();


};
