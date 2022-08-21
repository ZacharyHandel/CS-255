
class IntNode;  //Forward Declaration

typedef IntNode* IntNodePtr;

class IntNode
{
    private:
        int data;
        IntNodePtr link;
    public:
        IntNode();
        IntNode(int theData, IntNodePtr theLink);
        void setData(int theData);
        void setLink(IntNodePtr theLink);
        int getData() const;
        IntNodePtr getLink() const;
};

//function prototypes for the IntNode class
int recursiveSearchAndCount(IntNodePtr ptr, int key);
int searchAndCount(IntNodePtr head, int key);
int recursiveCountNodes(IntNodePtr ptr);
int countNodes(IntNodePtr head);
void deleteNode(IntNodePtr &head, int target);
void insert(IntNodePtr afterMe, int theData);
void tailInsert(IntNodePtr &head, int theData);
void headInsert(IntNodePtr &head, int theData);
void display(IntNodePtr head);
