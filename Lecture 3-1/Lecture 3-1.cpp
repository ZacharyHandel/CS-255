R//Algorithm Complexity
    //Algorithm A is faster than Algorithm B
    //Which one do we use?
    //Large problem size, what happens?

//Big O notation- describes worst-case scenario
    //Look at the time  it takes for an algorithm when the problem size gets larger (N)
///Examples

//Search
    //We have an unordered array and we have a key we are looking for within the array
    //use linear search
        //There are N items in our array
        //In Big O notation: O(N)
    //If it is ordered:
        //Use binary search
        //In Big O notation: O(LogN)

//Insert (allow duplicates)
    //Unordered
        //add to end of array (simple)
        //O(1)
    //Ordered
        //Search first which is O(LogN)
        //O(LogN)+O(N) = O(N) because you might have to shift them all

//Insert (do not allow duplicates)
    //Unordered
        //O(N) + O(1) = O(N)
    //Ordered
        //O(LogN) + O(N) = O(N)

//Delete
    //Unordered
        // Remove Item, take bottom and override deleted value and subtract 1 from array size
        // O(N) + O(1) = O(N)
    //Ordered
        //O(LogN) + O(N) = O(N)

//Linked List
    //Think about these same situations with Linked List

    //Dynamic Structure
    //Collection of nodes
    //Nodes consist of 2 things:
        //1: Data
        //2: Pointer to the next node on the list
    //When initializing a linked list, a pointer is created called the "head" of the list
    //Null pointer indicates the end of a linked list



//See New Project!!



