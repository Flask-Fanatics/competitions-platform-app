#include <iostream>

using namespace std;



struct Node

{

    int data;

    Node *next;

};



Node *createNode(int n)

{

    Node *newNode;



    newNode = new Node;

    newNode->data = n;

    newNode->next = NULL;



    return newNode;

}



void printList(Node *top)

{

    while (top != NULL)

    {

        cout << top->data << " ";

        top = top->next;

    }

    cout << endl;

}



// Function for Question 4(a)



void printListRec(Node *top)

{
if (top == NULL)

        return;



    cout << top->data << " ";



    printListRec(top->next);
}



// Function for Question 4(b)



void printListRecReversed(Node *top)

{
if (top == NULL)

        return;



    printListRecReversed(top->next);



    cout << top->data << " ";
}



// Function for Question 5(a)



int sizeList(Node *top)

{
int count = 0;

    while (top != NULL)

    {

        count = count + 1;

        top = top->next;

    }



    return count;
}



// Function for Question 5(b)



int sizeListRec(Node *top)

{
if (top == NULL)

        return 0;


        int countSoFar = sizeListRec(top->next);

        return countSoFar + 1;

}



int main()

{

// Question 1 (a)

    Node *node1;

    Node *node2;

    Node *node3;

    Node *node4;



    node1 = createNode(20);

    node2 = createNode(50);

    node3 = createNode(40);

    node4 = createNode(10);



    // Question 1 (b)

    node1->next = node2;

    node2->next = node3;

    node3->next = node4;



    // Question 1 (c)

    Node *top;

    top = node1;



    // Question 1 (d)

    printList(top);



    // Question 2 (a/b)

    // The address of top was passed by value. So, a copy of the address was made in the printList function. Modifications to the copy in the printList function did  not affect the value of top in the main function.

    printList(top);



    // Question 3 (a)

    // diplays all of the nodes in our list except the first one

    printList(top->next); // 50 40 10



    Node *top2 = top->next; // i.e. top2 = node2;

    printList(top2);        // 50 40 10

    printList(top2->next);  // 40 10



    Node *top3 = top2->next; // i.e. top3 = node3;

    printList(top3);         // 40 10

    printList(top3->next);   // 10



    // printList will display the value of each node, starting with the node that is passed as a parameter, and ending at the last node in the list.



    // Question 4 (a)

    printListRec(top); // 20 50 40 10



    cout << endl;



    // Question 4 (a)

    printListRecReversed(top); // 10 40 50 20


// Function for Question 4(a)



/*void printListRec(Node *top)

{

    if (top == NULL)

        return;



    cout << top->data << " ";



    printListRec(top->next);

} */



// Function for Question 4(b)



/*void printListRecReversed(Node *top)

{

    if (top == NULL)

        return;



    printListRecReversed(top->next);



    cout << top->data << " ";

} */

    return 0;

}





#include <iostream>

using namespace std;



struct Node

{

    int data;

    Node *next;

};



Node *createNode(int n)

{

    Node *newNode;



    newNode = new Node;

    newNode->data = n;

    newNode->next = NULL;



    return newNode;

}



void printList(Node *top)

{

    while (top != NULL)

    {

        cout << top->data << " ";

        top = top->next;

    }



    cout << endl;

}



// Function for Question 4(a)



void printListRec(Node *top)

{

    if (top == NULL)

        return;



    cout << top->data << " ";



    printListRec(top->next);

}



// Function for Question 4(b)

void printListRecReversed(Node *top)

{

    if (top == NULL)

        return;



    printListRecReversed(top->next);



    cout << top->data << " ";

}



// Function for Question 5(a)

int sizeList(Node *top)

{

    int count = 0;

    while (top != NULL)

    {

        count = count + 1;

        top = top->next;

    }



    return count;

}



// Function for Question 5(b)

int sizeListRec(Node *top)

{

    if (top == NULL)

        return 0;

    else

    {

        int countSoFar = sizeListRec(top->next);

        return countSoFar + 1;

    }

}



int main()

{



    // Question 1 (a)

    Node *node1;

    Node *node2;

    Node *node3;

    Node *node4;



    node1 = createNode(20);

    node2 = createNode(50);

    node3 = createNode(40);

    node4 = createNode(10);



    // Question 1 (b)

    node1->next = node2;

    node2->next = node3;

    node3->next = node4;



    // Question 1 (c)

    Node *top;

    top = node1;



    // Question 1 (d)

    printList(top);



    // Question 2 (a/b)

    // The address of top was passed by value. So, a copy of the address was made in the printList function. Modifications to the copy in the printList function did  not affect the value of top in the main function.

    printList(top);



    // Question 3 (a)

    // diplays all of the nodes in our list except the first one

    printList(top->next); // 50 40 10



    Node *top2 = top->next; // i.e. top2 = node2;

    printList(top2);        // 50 40 10

    printList(top2->next);  // 40 10



    Node *top3 = top2->next; // i.e. top3 = node3;

    printList(top3);         // 40 10

    printList(top3->next);   // 10



    // printList will display the value of each node, starting with the node that is passed as a parameter, and ending at the last node in the list.



    // Question 4 (a)

    printListRec(top); // 20 50 40 10



    cout << endl;



    // Question 4 (b)

    printListRecReversed(top); // 10 40 50 20

    cout << endl;



    // Question 5 (c)

    int s = sizeList(top);

    cout << "The size of list from node1 is " << s << endl;



    s = sizeListRec(top);

    cout << "The size of list from node1 is " << s << endl;



    // Question 6 (a)

    Node *toDelete = top->next;

    top->next = toDelete->next;

    delete toDelete;

    cout << endl;

    cout << "Linked list after deletion of the second node: ";

    printList(top);



    // Question 6 (b)

    Node *newNode = createNode(70);

    // top->next->next->next = newNode; works for only list

5:30 PM
// top->next->next->next = newNode; works for only list with 3 nodes



    Node *curr = top;

    Node *last;

    while (curr != NULL)

    {

        last = curr;

        curr = curr->next;

    }

    last->next = newNode;



    printListRec(top);



    return 0;

}

Press Shift + Tab to navigate to chat history.
so #include<fstream> at the top

5:33 PM
and in main

5:34 PM
ifstream fin;

5:34 PM
fin.open("file_name.txt")
fin >> some_variable;

5:34 PM
etc
fin.close();
