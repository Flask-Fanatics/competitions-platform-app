#include <iostream>

#include <fstream>



using namespace std;



struct Node {

    string name;

    int mark;

    Node * next;

};





Node * createNode (string name, int mark) {

    Node * newNode;



    newNode = new Node;

    newNode->name = name;

    newNode->mark = mark;

    newNode->next = NULL;

    

    return newNode;

}





void printList (Node * top) {



    while (top != NULL) {

        cout << top->name << "    \t\t" << top->mark << endl;

        top = top->next;

    }

    

    cout << endl;

}





int sumList (Node * top) {



    int sum;

    

    sum = 0;

    while (top != NULL) {

        sum = sum + top->mark;

        top = top->next;

    }

    

    return sum;

}





Node * insertList (Node * top, string name, int mark) {

    Node * newNode;



    newNode = createNode (name, mark);

    newNode->next = top;

    top = newNode;



    return top;

}





Node * deleteList (Node * top) {



    Node * toDelete;

    

    if (top != NULL) { 

        toDelete = top;

        top = top->next;

        delete toDelete;

    }



    return top;

}





int sizeList (Node * top) {



    int count;

    

    count = 0;

    while (top != NULL) {

        count = count + 1;

        top = top->next;

    }

    

    return count;

}





Node * getLast (Node * top) {



    if (top == NULL)

        return NULL;

        

    while (top->next != NULL)

        top = top->next;

        

    return top;

}





Node * appendList (Node * top, string name, int mark) {



    Node * last = getLast (top);

    Node * newNode = createNode (name, mark);

    

    if (last == NULL)

        return newNode;

    

    last->next = newNode;

    

    return top;

}





bool containsList (Node * top, string name) {



    while (top != NULL) {

        if (top->name == name)

            return true;

        top = top->next;

    }

    

    return false;

}





int numOccurList (Node * top, int mark) {



    int count = 0;

    

    while (top != NULL) {

        if (top->mark == mark)

            count = count + 1;

        top = top->next;

    }

    

    return count;

}





// Function for Question 2(a)



Node * predecessor (Node * top, int mark) {

    Node *prev = NULL;



    while (top != NULL && top->mark < mark)

    {

        prev = top;

        top = top->next;

    }



    return prev;

}





// Function for Question 2(b)



Node * insertListSorted (Node * top, string name, int mark) {

Node *newNode;

    Node *pred;



    newNode = createNode(name, mark);

    pred = predecessor(top, mark);



    if (pred == NULL) // insert at top

        top = insertList(top, name, mark);

    else

    {

        newNode->next = pred->next;

        pred->next = newNode;

    }



    return top;

}





// Function for Question 3(a)



bool isSortedList (Node * top) {

if (top == NULL || top->next == NULL)

        return true;



    Node *prev = top;

    top = top->next;



    while (top != NULL)

    {

        // check stuff

        if (prev->mark > top->mark)

            return false;



        prev = top;

        top = top->next;

    }



    return true;

}





// Function for Question 3(b)



bool isSortedListRec (Node * top) {

// base case(s)

    if (top == NULL || top->next == NULL)

        return true;



    Node *prev = top;

    top = top->next;



    if (prev->mark > top->mark)

        return false;



    // recursive call(s)

    return isSortedListRec(top);

}





int main () {



    ifstream inputFile;

    Node * top;

    Node * top2;

    string name;

    int mark;

    int max1, max2;

    double averageMark;

    bool sorted;

    

    cout << "Question 1:" << endl << endl;

    inputFile.open("Marks.txt");



    top = NULL;



    inputFile >> name;

    while (name != "END")

    {

        inputFile >> mark;



        // do stuff

        top = insertList(top, name, mark);



        inputFile >> name;

    }

    inputFile.close();



    printList(top);



    averageMark = (sumList(top) * 1.0 )/ sizeList(top);

    cout << "The average mark in the course is: " << averageMark << endl;



    cout << endl;

    cout << "Question 2:" << endl << endl;

    
inputFile.open("Marks.txt");



    top2 = NULL;



    inputFile >> name;

    while (name != "END")

    {

        inputFile >> mark;



        // do stuff

        top2 = insertListSorted(top2, name, mark);



        inputFile >> name;

    }

    inputFile.close();



    printList(top2);



    cout << endl;

    cout << "Question 3:" << endl << endl;

    

    // Question 3(c)

sorted = isSortedListRec (top);

    if (sorted)

        cout << "The first linked list is in sorted order." << endl;

    else

        cout << "The first linked list is NOT in sorted order." << endl;



    sorted = isSortedListRec (top2);

    if (sorted)

        cout << "The second linked list is in sorted order." << endl;

    else

        cout << "The second linked list is NOT sorted order." << endl;

    return 0;   

}