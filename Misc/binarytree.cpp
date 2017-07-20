#include <iostream>
#include <vector>

using namespace std;

/*
              8
            /   \
           /     \
          6      10
         / \     / \
        /   \   /   \
       5    7   9   11
      /\   /\   /\   / \
     1  2 3 4 12 15 17 19

    8
    |____________
    |            |
    6            10
    |_____       |_______
    |     |      |       |
    5     7      9       11
    |__   |___   |___    |___
    |  |  |   |  |   |   |   |
    1  2  3   4  12  15  17  19
    
               8
         ______|______
         |           |
         6           10
      ___|___     ___|___
      |     |     |     |
      5     7     9     11
     _|_   _|_   _|_   _|_
    |   | |   | |   | |   |
    1   2 3   4 12 15 17 19

    Expected output:  8 6 10 5 7 9 11 1 2 3 4 12 15 17 19
*/

int x[] = { 8, 6, 10, 5, 7, 9, 11, 1, 2, 3, 4, 12, 15, 17, 19 };
const int LEN = sizeof(x)/sizeof(int);

struct BinaryTreeNode
{
    int             m_value;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void show_vector(vector<BinaryTreeNode*> Vec_proc)
{
    vector<BinaryTreeNode*>::iterator Iter;

    for ( Iter = Vec_proc.begin( ) ; Iter != Vec_proc.end( ) ; Iter++ )
    {
        cout << " " << (*Iter)->m_value;
    }
    cout << endl;
}

void print_BTnodes_by_layer(BinaryTreeNode* p_BThead)
{
    if (p_BThead == NULL)
    {
        cout << "Pointer of BinaryTree is NULL! *" << endl;
        return;
    }

    BinaryTreeNode* p_leftnode, *p_rightnode;
    vector<BinaryTreeNode*>::iterator Iter;
    vector<BinaryTreeNode*> Vec_proc;
    vector<BinaryTreeNode*> Vec_swap;

    Vec_proc.push_back(p_BThead);
    while (! Vec_proc.empty())
    {
        Vec_swap.clear();
        cout << " (";
        for ( Iter = Vec_proc.begin( ) ; Iter != Vec_proc.end( ) ; Iter++ )
        {
            cout << " " << (*Iter)->m_value;
            p_leftnode = (*Iter)->m_pLeft;
            if (p_leftnode != NULL) Vec_swap.push_back(p_leftnode);

            p_rightnode = (*Iter)->m_pRight;
            if (p_rightnode != NULL) Vec_swap.push_back(p_rightnode);
        }
        cout << " ) ";
        Vec_proc = Vec_swap;
    }
}

void print_BTnodes_Recur(BinaryTreeNode* p_BThead)
{
    BinaryTreeNode* p_leftnode, *p_rightnode;
    if (p_BThead != NULL)
    {
        cout << " " << p_BThead->m_value;
        p_leftnode = p_BThead->m_pLeft;
        if (p_leftnode != NULL) {
            print_BTnodes_Recur(p_leftnode);
        }
        p_rightnode = p_BThead->m_pRight;
        if (p_rightnode != NULL) {
            print_BTnodes_Recur(p_rightnode);
        }
    }
    else
        cout << "  * The BinaryTree pointer is NULL! *" << endl;
}

void build_BinaryNodes(int leftvalue, int rightvalue, BinaryTreeNode *p_parentnode)
{
    BinaryTreeNode *p_leftnode, *p_rightnode;

    p_leftnode = new(BinaryTreeNode);
    p_rightnode = new(BinaryTreeNode);
    if ( (p_leftnode == NULL) || (p_rightnode == NULL) )
    {
        cout << "Failed to new memory to store BTnode!" << endl;
        return;
    }
    p_leftnode->m_value = leftvalue;
    p_leftnode->m_pLeft = NULL;
    p_leftnode->m_pRight = NULL;

    p_rightnode->m_value = rightvalue;
    p_rightnode->m_pLeft = NULL;
    p_rightnode->m_pRight = NULL;

    p_parentnode->m_pLeft = p_leftnode;
    p_parentnode->m_pRight = p_rightnode;
}

BinaryTreeNode* build_BinaryTree(int data[])
{
    BinaryTreeNode *p_parentnode, *p_leftnode, *p_rightnode, *p_headnode;
       BinaryTreeNode *p1, *p2, *p3, *p4;
    int index = 0;
    int v_left, v_right;

    // head(root) node (8)
    p_headnode = new(BinaryTreeNode);
    if (p_headnode == NULL)
    {
        cout << "Failed to new memory to store BTnode!" << endl;
        return NULL;
    }
    p_headnode->m_value = data[index++];

    // parent nodes (6, 10)
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_headnode);

    // sub-left node (5, 7)
    p_parentnode = p_headnode->m_pLeft;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);
    p1 = p_parentnode->m_pLeft;
    p2 = p_parentnode->m_pRight;

    // sub-right node (9, 11)
    p_parentnode = p_headnode->m_pRight;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);
    p3 = p_parentnode->m_pLeft;
    p4 = p_parentnode->m_pRight;

    // sub-sub node1 (1, 2)
    p_parentnode = p1;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);

    // sub-sub node2 (3, 4)
    p_parentnode = p2;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);

    // sub-sub node3 (12, 15)
    p_parentnode = p3;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);

    // sub-sub node4 (17, 19)
    p_parentnode = p4;
    v_left = data[index++];
    v_right = data[index++];
    build_BinaryNodes(v_left, v_right, p_parentnode);

    return p_headnode;
}

void delete_BTnodes(BinaryTreeNode* p_BThead)
{
    BinaryTreeNode* p_leftnode, *p_rightnode;
    //static int nm = 0;

    if (p_BThead != NULL)
    {
        p_leftnode = p_BThead->m_pLeft;
        p_rightnode = p_BThead->m_pRight;

        delete(p_BThead);
        //cout << "  delete node [" << ++nm << "]" << endl;

        if (p_leftnode != NULL) {
            delete_BTnodes(p_leftnode);
        }

        if (p_rightnode != NULL) {
            delete_BTnodes(p_rightnode);
        }
    }
}

void print_tree_align_left(int data[])
{
    int index = 0;

    cout << "  " << data[index++] << endl;
    cout << "  |____________" << endl;
    cout << "  |            |" << endl;
    cout << "  " << data[index++];
    cout << "            " << data[index++] << endl;
    cout << "  |_____       |_______" << endl;
    cout << "  |     |      |       |" << endl;
    cout << "  " << data[index++];
    cout << "     " << data[index++];
    cout << "      " << data[index++];
    cout << "       " << data[index++] << endl;
    cout << "  |__   |___   |___    |___" << endl;
    cout << "  |  |  |   |  |   |   |   |" << endl;
    for(int i=0;i<8;i++)
        cout << "  " << data[index++];
    cout << endl;
}

void print_tree_align_center(int data[])
{
    int index = 0;

    cout << "             " << data[index++] << endl;
    cout << "       ______|______" << endl;
    cout << "       |           |" << endl;
    cout << "       " << data[index++];
    cout << "           " << data[index++] << endl;
    cout << "    ___|___     ___|___" << endl;
    cout << "    |     |     |     |" << endl;
    cout << "    " << data[index++];
    cout << "     " << data[index++];
    cout << "     " << data[index++];
    cout << "     " << data[index++] << endl;
    cout << "   _|_   _|_   _|_   _|_" << endl;
    cout << "  |   | |   | |   | |   |" << endl;
    for(int i=0;i<8;i++)
    	cout << "  " << data[index++];
    cout << endl;
}

int main(int argc, char *argv[])
{
    BinaryTreeNode *p_headnode;

    cout << "Build BinaryTree...";
    p_headnode = build_BinaryTree(x);
    cout << "\tDone." << endl;

    print_tree_align_center(x);

    if (p_headnode != NULL) {
        cout << endl << "Print BinaryTree by layer: " << endl << " ";
        print_BTnodes_by_layer(p_headnode);
        cout << endl;

        cout << "* Expected output:  8 6 10 5 7 9 11 1 2 3 4 12 15 17 19 *" << endl;

        cout << endl << "Delete BinaryTree...";
        delete_BTnodes(p_headnode);
        p_headnode = NULL;
        cout << "\tDone." << endl;
    }

    return 0;
}
