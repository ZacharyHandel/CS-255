#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

int BinarySearchTree::findHeight()
{
    return TreeHeight(root);
}

int BinarySearchTree::TreeHeight(treeNodePtr ptr)
{
    if(ptr == nullptr)
    {
        return 0;
    }
    else
    {
       if(ptr->left==nullptr && ptr->right == nullptr)  //no left or right values
       {
           return 0;
       }
       else
       {
           return 1 + max(TreeHeight(ptr->left), TreeHeight(ptr->right));
       }
    }
}

/*
void BinarySearchTree::remove(int key)
{
    bool found=false;
    if(isEmpty())
    {
        cout << "Tree is empty... Cannot remove an item" << endl;
    }
    else
    {
        treeNodePtr current = root;
        treeNodePtr parent = nullptr;

        while((current != nullptr) && (!found))
        {
            if(current->data == key)
            {
                found = true;
            }
            else
            {
                parent = current;

                if(key > current-> data)
                {
                    current = current->right;
                }
                else
                {
                   current = current->left;
                }
            }
        }
        if(!found)
        {
            cout << "Cannot remove item - non-existent." << endl;
        }
        else
        {       //does current have exactly one subtree???  CASE 1!
            if(current->left == nullptr && current->right !=nullptr) || (current->left != nullptr && current->right ==nulptr)
            {
                if(current->left == nullptr && current->right !=nullptr)    //if current has a right subtree
                {
                    if(parent->left == current) //right child but no left child
                    {
                        parent->left = current->right;
                        delete current;
                    }
                    else
                    {
                        parent->right = current->right;
                        delete current;
                    }
                }
                else    //left child but no right child
                {
                    if(parent->left == current)
                    {
                        parent->left = current->left;
                        delete current;
                    }
                    else
                    {
                        parent->right = current->left;
                        delete current;
                    }
                }
            }
        }

    }
}
*/

void BinarySearchTree::print_postorder()  //helper function
{
    postorder(root);
}

void BinarySearchTree::postorder(treeNodePtr ptr)
{
    if(ptr != nullptr)
    {
        if(ptr->left != nullptr)
        {
            postorder(ptr->left);
        }
        if(ptr->right != nullptr)
        {
            postorder(ptr->right);
        }
        cout << " " << ptr->data << " ";
    }
}

void BinarySearchTree::print_preorder()  //helper function
{
    preorder(root);
}

void BinarySearchTree::preorder(treeNodePtr ptr)
{
    if(ptr != nullptr)
    {
        cout << " " << ptr->data << " ";
        if(ptr->left != nullptr)
        {
            preorder(ptr->left);
        }
        if(ptr->right != nullptr)
        {
            preorder(ptr->right);
        }
    }
}

void BinarySearchTree::print_inorder()  //helper function
{
    inorder(root);
}

void BinarySearchTree::inorder(treeNodePtr ptr)
{
    if(ptr != nullptr)
    {
        if(ptr->left != nullptr)
        {
            inorder(ptr->left);
        }
        cout << " " << ptr->data << " ";

        if(ptr->right != nullptr)
        {
            inorder(ptr->right);
        }
    }
}


bool BinarySearchTree::isEmpty() const
{
    return root==nullptr;   //if these are equal, it is true!
}

void BinarySearchTree::insert(int theKey)
{
    treeNodePtr temp = new treeNode;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data = theKey;

    if (isEmpty())
    {
        root = temp;    //first node (check if it is an empty tree)

    }
    else
    {
        treeNodePtr parent = nullptr;
        treeNodePtr current = root;
        while(current != nullptr)
        {
            parent = current;
            if(temp->data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        if(temp->data < parent->data)
            {
                parent->left = temp;
            }
            else
            {
                parent->right = temp;
            }

    }
}

