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
    |           |
    6           10
    |______     |______
    |     |     |     |
    5     7     9     11
    |____ |____ |____ |____
    |   | |   | |   | |   |
    1   2 3   4 12 15 17  19
    
               8
         ______|______
         |           |
         6           10
      ___|___     ___|___
      |     |     |     |
      5     7     9     11
    __|__ __|__ __|__ __|__
    |   | |   | |   | |   |
    1   2 3   4 12 15 17 19

    Expected output:  8 6 10 5 7 9 11 1 2 3 4 12 15 17 19
*/

int x[] = { 8, 6, 10, 5, 7, 9, 11, 1, 12, 3, 14, 2, 15, 4, 19 };
//int x[] = { 8, 10, 6, 25, 37, 11, 29, 31, 12, 3, 14, 2, 15, 4, 19 };
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

	if (leftvalue != 0xff)
	{
		p_leftnode = new(BinaryTreeNode);
		if (p_leftnode == NULL)
		{
		    cout << "Failed to new memory to store BTnode!" << endl;
		    return;
		}
		p_leftnode->m_value = leftvalue;
		p_leftnode->m_pLeft = NULL;
		p_leftnode->m_pRight = NULL;

		p_parentnode->m_pLeft = p_leftnode;
	}

	if (rightvalue != 0xff)
	{
		p_rightnode = new(BinaryTreeNode);
		if (p_rightnode == NULL)
		{
		    cout << "Failed to new memory to store BTnode!" << endl;
		    return;
		}
		p_rightnode->m_value = rightvalue;
		p_rightnode->m_pLeft = NULL;
		p_rightnode->m_pRight = NULL;

		p_parentnode->m_pRight = p_rightnode;
	}
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

void indent_print(int data[], int index)
{
	int iDat1, iDat2;
	int i = index;

	for(int n=0;n<4;n++)
	{
		iDat1 = data[i++];
		cout << " " << iDat1;
		iDat2 = data[i++];
		if (iDat1 < 10)
		{
			if (iDat2 < 10)
				cout << "   " << iDat2;
			else
				cout << "  " << iDat2;
		}
		else
		{
			if (iDat2 < 10)
				cout << "  " << iDat2;
			else
				cout << " " << iDat2;
		}
	}
}

void print_tree_align_left(int data[])
{
    int index = 0;
	int iDat, iDat2;

    cout << "  " << data[index++] << endl;
    cout << "  |____________" << endl;
    cout << "  |           |" << endl;

	iDat = data[index++];
    cout << "  " << iDat;
	if (iDat < 10)
	    cout << "           " << data[index++] << endl;
	else
		cout << "          " << data[index++] << endl;
    cout << "  |______     |______" << endl;
    cout << "  |     |     |     |" << endl;

	iDat = data[index++];
    cout << "  " << iDat;
	iDat2 = data[index++];
	if (iDat < 10)
		if (iDat2 < 10)
		    cout << "     " << iDat2;
		else
		    cout << "    " << iDat2;
	else
		if (iDat2 < 10)
	    	cout << "    " << iDat2;
		else
	    	cout << "   " << iDat2;

	iDat = data[index++];
    cout << "     " << iDat;
	iDat2 = data[index++];
	if (iDat < 10)
		if (iDat2 < 10)
		    cout << "     " << iDat2 << endl;
		else
		    cout << "    " << iDat2 << endl;
	else
		if (iDat2 < 10)
	    	cout << "    " << iDat2 << endl;
		else
	    	cout << "   " << iDat2 << endl;

    cout << "  |____ |____ |____ |____" << endl;
    cout << "  |   | |   | |   | |   |" << endl;

	cout << " ";
	indent_print(data, index);

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
    cout << "  __|__ __|__ __|__ __|__" << endl;
    cout << "  |   | |   | |   | |   |" << endl;

	cout << " ";
	indent_print(data, index);

    cout << endl;
}

int main(int argc, char *argv[])
{
    BinaryTreeNode *p_headnode;

    print_tree_align_left(x);
	print_tree_align_center(x);

    cout << endl << "Build BinaryTree...";
    p_headnode = build_BinaryTree(x);
    cout << "\tDone." << endl;

    if (p_headnode != NULL) {
        cout << endl << "Print BinaryTree by layer: " << endl << " ";
        print_BTnodes_by_layer(p_headnode);
        cout << endl;

        //cout << "* Expected output:  8 6 10 5 7 9 11 1 2 3 4 12 15 17 19 *" << endl;

        cout << endl << "Delete BinaryTree...";
        delete_BTnodes(p_headnode);
        p_headnode = NULL;
        cout << "\tDone." << endl;
    }

    return 0;
}
