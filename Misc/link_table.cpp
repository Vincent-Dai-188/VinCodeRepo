#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int Data;
    Node *next;
};

class list
{
    Node *head;
    public:
        list() { head = NULL; }
        void insertitem(int newData);
        void insertitem(int aData, int bData);
        void deleteitem(int aData);
        void outputlist();
        Node *gethead() { return head; }
};

/*
 * Insert newData at the end of the list.
 */
void list::insertitem(int newData)
{
    Node *p_Node_new, *p_tmp;
    p_Node_new = (Node*) new(Node);     //assign a new node (Node_b)
    p_Node_new->Data = newData;
    p_Node_new->next = NULL;
    if(head == NULL)                    //empty list, set *head to Node_b (the first Node)
    {
        head = p_Node_new;
        p_Node_new->next = NULL;
    }
    else
    {
        p_tmp = head;
        while(p_tmp->next != NULL)  //search for the aData in the list
        {
            p_tmp = p_tmp->next;
        }
        p_tmp->next = p_Node_new;
        p_Node_new->next = NULL;
    }
}

/*
 * If aData exists in the list, insert bData in front of aData. If aDate doesn't exist,
 * insert bData at the end of the list.
 */
void list::insertitem(int aData, int bData) //aData: data in node_a, bData: data in node_b
{
    Node *p_Node_a, *p_Node_b, *p_tmp;
    p_Node_b = (Node*) new(Node); 	//assign a new node (Node_b)
    p_Node_b->Data = bData; 		//assign bData to this Node_b
    p_Node_a = head;
    if(head == NULL)                //empty list, set *head to Node_b (the first Node)
    {
        head = p_Node_b;
        p_Node_b->next = NULL;
    }
    else
    {
        if(p_Node_a->Data == aData) //Node_a is currently the first Node, exchange their positions
        {
            p_Node_b->next = p_Node_a;
            head = p_Node_b;
        }
        else
        {
            while(p_Node_a->Data != aData && p_Node_a->next != NULL)  //search for the aData in the list
            {
                p_tmp = p_Node_a;
                p_Node_a = p_Node_a->next;
            }
            if(p_Node_a->Data == aData)     //aData is found, place bData in front of aData
            {
                p_tmp->next = p_Node_b;
                p_Node_b->next = p_Node_a;
            }
            else    //no such aData
            {
                p_Node_a->next = p_Node_b;
                p_Node_b->next = NULL;
            }
        }
    }
}

void list::deleteitem(int aData)    //delete Node which Data value equals to aData
{
    Node *p_Node, *p_prior;

    if(head == NULL)            //empty list
        return;

    p_Node = head;
    if(head->Data == aData)     //it is the first Node
    {
        head = p_Node->next;
        delete p_Node;
    }
    else
    {
        while(p_Node->Data != aData && p_Node->next != NULL)    //search for Node_a
        {
            p_prior = p_Node;       //store this pointer as the prior one
            p_Node = p_Node->next;
        }
        if(p_Node->Data == aData)  //Node_a is found
        {
            p_prior->next = p_Node->next;
            delete p_Node;
        }
    }
}

void list::outputlist()
{
    Node *cur_pt = head;
    while(cur_pt != NULL)
    {
        cout << cur_pt->Data << " ";
        cur_pt = cur_pt->next;
    }
    cout << endl;
}

/*  execution result:
List A: 25 41 16 98 5 67 9 55 1 121
After removed element value '55': 25 41 16 98 5 67 9 1 121

List B: 121 1 55 9 67 5 98 16 41 25 999
After removed element value '67': 121 1 55 9 5 98 16 41 25 999
*/

void vector_test(int *pi, int len)
{
	vector<int> iVec;
	vector<int>::iterator iter;
	int i;

    for(i=0;i<len;i++)
       iVec.push_back(*(pi++));

    iter = iVec.begin();
    cout << "Content of iVec: ";
    while(iter != iVec.end())
    {
    	cout << *iter << " ";
    	iter++;
    }
    cout << endl;
}

void vector_erase_test( )
{
    vector <int> v1;
    vector <int>::iterator Iter;

    v1.push_back( 10 );
    v1.push_back( 20 );
    v1.push_back( 30 );
    v1.push_back( 40 );
    v1.push_back( 50 );
    cout << "v1 =" ;
    for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
        cout << " " << *Iter;
    cout << endl;

    Iter = v1.begin();
    v1.erase(Iter);
    v1.erase(Iter+1);
    cout << "v1 =";
    for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
    cout << endl;

    v1.erase( v1.begin( ) + 1, v1.begin( ) + 3 );
    cout << "v1 =";
    for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )
      cout << " " << *Iter;
    cout << endl;
}

void vector_insert_test()
{
    vector<int> myvector (3,100);
    vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);
    myvector.insert (it, 2, 300);

    cout << "[1] myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
    	cout << ' ' << *it;
    cout << '\n';

    // "it" no longer valid, get a new one:
    it = myvector.begin();
    vector<int> newvector (2,400);
    myvector.insert (it+2, newvector.begin(), newvector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    cout << "[2] myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
    	cout << ' ' << *it;
    cout << '\n';
}

int main()
{
    list A,B;
    int Data[10] = {25,41,16,98,5,67,9,55,1,121};
    //int i;

    vector_test(Data, 10);

    vector_erase_test();

    vector_insert_test();

    /*for(i=0;i<10;i++)
        A.insertitem(Data[i]);    //insert Data[1-9] into List A one by one
    cout << "\nList A: ";
    A.outputlist();

    A.deleteitem(Data[7]);
    cout << "After removed element value '" << Data[7] << "': ";
    A.outputlist();

    B.insertitem(0,999);        	//create the first Node with data 999 in List B
    for(i=0;i<10;i++)
    	B.insertitem(B.gethead()->Data, Data[i]);    //insert Data[0-9] into List B one by one in the reversed order
    cout << "\nList B: ";
    B.outputlist();

    B.deleteitem(67);
    cout << "After removed element value '67': ";
    B.outputlist();*/

    return 0;
}
