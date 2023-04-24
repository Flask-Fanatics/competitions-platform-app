Node *copyListRec(Node *top)

{

    // base case(s)

    if (top == NULL)

        return NULL;



    // recursive call(s)

    Node *newNode = createNode(top->data);

    newNode->next = copyListRec(top->next);



    return newNode;

}


bool isEqualList(Node *top1, Node *top2)

{

    // if(sizeList(top1) != sizeList(top2))

    //  return false;



    while (top1 != NULL && top2 != NULL)

    {

        if (top1->data != top2->data)

            return false;



        top1 = top1->next;

        top2 = top2->next;

    }



    if (top1 == NULL && top2 == NULL)

        return true;



    return false;

}



// Function for Question 2(b)



bool isEqualListRec(Node *top1, Node *top2)

{

    // base case(s)

    // both empty, return true

    if (top1 == NULL && top2 == NULL)

        return true;



    // one list has fewer elements, return false

    if (top1 == NULL || top2 == NULL)

        return false;



    // data at some position in lists is different, return false

    if (top1->data != top2->data)

        return false;



    // recursive call(s)

    return isEqualListRec(top1->next, top2->next);

}

isEqual = isEqualList (top, top2);

    

    if (isEqual)

        cout << "The original linked list and its copy are equal." << endl;

    else

        cout << "The original linked list and its copy are NOT equal." << endl;

        

    isEqual = isEqualListRec (top, top2);

    

    if (isEqual)

        cout << "The original linked list and its copy are equal (recursive check)." << endl;

    else

        cout << "The original linked list and its copy are NOT equal (recursive check)." << endl;   
        
    
    
    
    reverse = reverseList (top);

    

    cout << "The following are the elements of the reversed linked list: " << endl;

    printList (reverse);

    

    reverse = reverseListRec (top2);

    

    cout << endl;

    cout << "The following are the elements of the reversed linked list (recursive): " << endl;

    printList (reverse);
