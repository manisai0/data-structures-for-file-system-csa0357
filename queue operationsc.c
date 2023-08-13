#include<stdio.h>
 
#define SIZE 3
 
//queue structure 
struct queue
{
    int values[SIZE];
    int front;
    int rear;
};
 
void enqueue(int);
int dequeue();
int isEmpty();
int isFull();
void display();
 
//glob
struct queue q;
 
int main()
{
    q.front = -1;
    q.rear = -1;
    int user_choice, data;
    char user_active = 'Y';
 
    while (user_active == 'Y' || user_active == 'y')
    {
        printf("\n--------Queue Program------\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
 
        printf("\n\nEnter your choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice)
        {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
 
            case 2:
                if (!isEmpty())
                {
                    data = dequeue();
                    printf("\n* %d was removed!\n", data);
                }
                else
                {
                    printf("\nQueue is Empty!\n");
                }
                break;
 
            case 3:
                display();
                printf("\n");
                break;
 
            case 4:
                printf("\n\tProgram was terminated!\n\n");
                return 1;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\nDo You want to continue? ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
    return 0;
}
 
int isEmpty()
{
    if (q.front == -1 || q.front > q.rear)
    {
        return 1;
    } 
    return 0;    
}
 
int isFull()
{
    if (q.rear == SIZE - 1)
    {
        return 1;
    } 
    return 0;    
}
 
void enqueue(int data)
{
    if (isFull())
    {
        printf("\nQueue is Full!\n");
        return;
    } 
    if (isEmpty())
    {
        q.front += 1;    
    } 
    q.rear += 1;
    q.values[q.rear] = data;
    printf("\n* %d was inserted!\n", data);
}
 
int dequeue() 
{
    if (!isEmpty())
    {    
        int data = q.values[q.front];
        q.front += 1;
        return data;
    }
}
 
void display()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\n");
    int begin = q.front;
    while (begin <= q.rear)
    {
        printf("%d ", q.values[begin]);
        begin += 1;
    }
}
Program Explanation
Let’s discuss the main functions of the program in detail with examples and their complexities.


enqueue() Function
Enqueue is the operation to insert the new item to the queue from the rear. To perform the enqueue operation, we need to follow the given steps:

Increment the rear by one.
Insert the new item at the rear index of the array.
Example: Insert the new element 23 in the given queue. Here, the size of the queue is 6.

Step 1: Rear is incremented by one, and moved from index 3 to 4.

Array Implementation of the Queue - enqueue() Function

Step 2: Insert the data at rear

Array Implementation of the Queue - enqueue() Function

Time Complexity: O(1)
It takes constant time to shift the rear and insert new data into the queue. So, the time complexity of queue program is O(1).

Space Complexity: O(1)
Only temporary space is used for inserting a new node into the queue. So, the space complexity of queue program is O(1).

Run Time Testcases
In this case, we are performing the enqueue operation of queue using array.

--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 34 
 
* 34 was inserted!       
 
Do You want to continue? y
 
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 90
 
* 90 was inserted!       
 
Do You want to continue? y
 
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 12
 
* 12 was inserted!       
 
Do You want to continue? y
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
34 90 12
 
Do You want to continue? n

dequeue() Function
The Dequeue operation is used to remove an item from the front of the queue. To perform the dequeue operation we have to follow the given steps:

Store the value at the front index in a temporary variable called data.
Increment the front by one.
Return the stored value.
Example: Remove an element from the given queue. Here, the front is at index 0 and after performing the dequeue operation, the front will be shifted from index 0 to 1.

Note that the last front value will not be erased after shifting the front.

Step 1: Store the value of front in data

Array Implementation of the Queue - dequeue() Function

Step 2: Increment the front by one

Array Implementation of the Queue - dequeue() Function

Time Complexity: O(1)
It takes constant time to shift the front and remove the data from the queue. So, the time complexity is O(1).

Space Complexity: O(1)
Only temporary space is used for inserting a new node into the queue. So, the space complexity is O(1).

Run Time Testcases
In this case, we are performing the dequeue operation of queue using array.

--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
34 90 12
 
Do You want to continue? y
 
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 2
 
* 34 was removed!
 
Do You want to continue? y
 
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
90 12
 
Do You want to continue? y
 
--------Queue Program------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 4
 
        Program was terminated!

Method 2: Queue Program in C using Linked List
In this approach, we will use the concept of the linked list. We have to create the front and rear pointers to keep track of the queue on dequeue and enqueue operations respectively.

The front and rear pointers will be initialized by NULL. The front pointer will point to the first node and the rear pointer will point to the last node of the queue. On enqueue operation, we have to insert a new node at the end of the list while in dequeue, the first node will be removed from the queue.

Let’s see the linked list implementation of the queue using the C programming language.

Program/Source Code
Here is the C program implementation of the queue using a linked list. The C program is successfully compiled and run on a Linux system. The program output is also shown below.

/*
 * C program to implement queue using a linked list
 */
 
#include<stdio.h>
#include<stdlib.h>
 
// structure of a node
struct node
{ 
    int data;
    struct node* next;
};
 
// globally declared pointers
struct node* front = NULL;
struct node* rear = NULL;
 
// function prototyping
void enqueue(int);
int dequeue();
void display();
struct node* create(int);
int isEmpty();
 
int main()
{
    int user_choice, data;
    char user_active = 'Y';
 
    while (user_active == 'Y' || user_active == 'y')
    {
        printf("\n--------> Queue Program <------\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
 
        printf("\n\nEnter your choice: ");
        scanf("%d", &user_choice);
 
        switch(user_choice)
        {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
 
            case 2:
                if (!isEmpty())
                {
                    data = dequeue();
                    printf("\n* %d was removed\n", data);
                }
                else
                {
                    printf("\nQueue is Empty!\n");
                }
                break;
 
            case 3:
                display();
                printf("\n");
                break;
 
            case 4:
                printf("\n\tProgram was Terminated!\n\n");
                return 1;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\nDo You want to continue? ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
    return 0;
}
 
 
// creates a new node
struct node* create(int data)
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
 
    return new_node;
}
 
// check if the queue is empty
int isEmpty()
{
    if (front == NULL || rear == NULL)
    {
        return 1;
    }
    return 0;
}
 
// inserts an item to the queue
void enqueue(int data)
{
    struct node* new_node = create(data);
 
    if (new_node != NULL)
    {
        // if the queue is empty
        if(front == NULL)
        {
            front = new_node;
        }
        else
        {
            rear->next = new_node;
        }
        // rear pointing to the new node
        rear = new_node;
        printf("\n* %d was inserted!\n", data);
    }
}
 
// removes an item to the queue
int dequeue()
{
    if (!isEmpty())
    {
        int data = front->data;
        front = front->next;
        return data;
    }
}
 
// display the queue 
void display()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\n");
    struct node* temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
Program Explanation
Let’s discuss the main functions of the program in detail with examples and their complexities.


enqueue() Function
To perform the enqueue operation, we have to follow the given steps:

Update the next pointer of the rear node to the new node.
Update the rear pointer to the new node.
Example: Insert the new node with data 77 at the end of the given queue.

Step 1: Updating the next of the rear node to the new node.

Linked List Implementation of the Queue - enqueue() Function

Step 2: Update the rear pointer to the new node.

Linked List Implementation of the Queue - enqueue() Function

Time Complexity: O(1)
Updating the rear pointer does take a constant amount of time. So, the time complexity is O(1).

Space Complexity: O(1)
Since using the temporary variables to perform the enqueue operation so space is constant. So, the space complexity is O(1).

Run Time Testcases
In this case, we are performing the dequeue operation of queue using array.

--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 90
 
* 90 was inserted!       
 
Do You want to continue? y
 
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 56
 
* 56 was inserted!       
 
Do You want to continue? y
 
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 1
 
Enter Data: 12
 
* 12 was inserted!       
 
Do You want to continue? y
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
90 56 12
 
Do You want to continue? n

dequeue() Function
To perform the dequeue operation we have to follow the given steps:

Store the value at the front node.
Move the front node to its next node.
Example: Let’s see an example of the dequeue operation in the given queue.

Step 1: Store the data of the front node.

Linked List Implementation of the Queue - dequeue() Function

Step 2: Move the front pointer to next node.

Linked List Implementation of the Queue - dequeue() Function

Time Complexity: O(1)
Updating the front pointer does take a constant amount of time. So, the time complexity is O(1).

Space Complexity: O(1)
Since using the temporary variables to perform the dequeue operation, space is constant i.e. O(1).

Run Time Testcases
In this case, we are performing the dequeue operation of queue using linked list.

--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
90 56 12
 
Do You want to continue? y
 
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 2
 
* 90 was removed
 
Do You want to continue? y
 
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 3
 
56 12
 
Do You want to continue? y
 
--------> Queue Program <------
 
1. Enqueue
2. Dequeue
3. Display
4. Exit
 
Enter your choice: 4
 
        Program was Terminated!
To practice programs on every topic in C, please visit “Programming Examples in C”, “Data Structures in C” and “Algorithms in C”.

« Prev - C Program to Implement Stack» Next - Graph Representation using 2D Arrays in C
Next Steps:

Get Free Certificate of Merit in Data Structure I
Participate in Data Structure I Certification Contest
Become a Top Ranker in Data Structure I
Take Data Structure I Tests
Chapterwise Practice Tests: Chapter 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Chapterwise Mock Tests: Chapter 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Related Posts:

Buy Computer Science Books
Practice Design & Analysis of Algorithms MCQ
Apply for Information Technology Internship
Practice Programming MCQs
Buy Data Structure Books
CategoriesC Programs - Queue, Data Structures in C
Recommended Articles:
Python Program to Implement Queue
C Program to Implement Queue using Linked List
Python Program to Implement Queue using Linked List
C Program to Implement Queue Functions using Dynamic Memory Allocation
Java Program to Implement Doubly Ended Queue
C Program to Implement Queue Functions using Arrays and Macros
Data Structure Questions and Answers – Queue using Array
C Program to Implement Priority Queue Operations
Java Questions & Answers – Data Structures-Queue
C Program to Implement Queue using Two Stacks
Subscribe: Data Structure Newsletter

Name
Email
Subscribe
Subscribe to our Newsletters (Subject-wise). Participate in the Sanfoundry Certification contest to get free Certificate of Merit. Join our social networks below and stay updated with latest contests, videos, internships and jobs!

Youtube | Telegram | LinkedIn | Instagram | Facebook | Twitter | Pinterest
Manish Bhojasia - Founder & CTO at SanfoundryManish Bhojasia, a technology veteran with 20+ years @ Cisco & Wipro, is Founder and CTO at Sanfoundry. He lives in Bangalore, and focuses on development of Linux Kernel, SAN Technologies, Advanced C, Data Structures & Alogrithms. Stay connected with him at LinkedIn.

Subscribe to his free Masterclasses at Youtube & discussions at Telegram SanfoundryClasses.
C Programming
C Programs
1000 C Programs
1000 C Algorithms
Data Structures in C
Simple C Programs
C - Array Programs
C - Matrix Programs
C - String Programs
C - Bitwise Operations
C - Linked List Programs
C - Searching & Sorting
Tree Programs in C
C - File Handling Programs
C - Mathematical Functions
C - Recursion Programs
C Programs - Heap
Heap in C
Binary Heap in C
Binomial Heap in C
Binomial Heap Tree in C
Heap Operations in C
C Programs - Linked List
Create and Display Linked List in C
Search an Element in Linked List in C
Search an Element in Linked List using Recursion in C
Search an Element in Linked List without Recursion in C
Reverse a Linked List in C
Reverse First N Elements of a Linked List in C
Remove Duplicates from Linked List in C
Check if Two Lists are Equal in C
Count Occurrences of Elements in a Linked List in C
Count Occurrences of Elements in a Linked List using Recursion in C
Count Occurrences of Elements in a Linked List without Recursion in C
Common Element in Two Linked Lists in C
Length of Linked List using Recursion in C
Length of Linked List without Recursion in C
Intersection & Union of 2 Linked Lists in C
Add Positioned Elements of 2 Linked Lists in C
Detect Cycle in Linked List in C
Josephus Problem using Linked List in C
Segregate Even and Odd Nodes in a Linked List in C
Adjacency List in C
Skip List in C
Vlist in C
Xor Linked List in C
Stack using Linked List in C
Queue using Linked List in C
Binary Tree using Linked List in C
Find Middle Element of a Linked List in C
Find Nth Node from End of Linked List in C
Swap Adjacent Nodes in a Circular Linked List in C
Swap Elements of List without Key Field in C
Arbitrary Precision Arithmetic in C
Print All Nodes of Linked List using Recursion in C
Print All Nodes of Linked List without Recursion in C
Reverse a Linked List using Recursion in C
Reverse a Linked List without Recursion in C
Print Alternate Nodes of a Linked List using Recursion in C
Print Alternate Nodes of a Linked List without Recursion in C
C Programs - Singly Linked List
Singly Linked List in C
Circular Single Linked List in C
Check if Singly Linked List is Palindrome in C
Singly Linked List to Circular List in C
Singly Linked List using Dynamic Memory Allocation in C
Convert Binary Tree to Singly Linked List in C
C Programs - Doubly Linked List
Doubly Linked List in C
Circular Doubly Linked List in C
Largest Element in a Doubly Linked List in C
Doubly Linked List using Singly Linked List in C
Doubly Linked List to Balanced BST in C
Convert Binary Tree to Circular Doubly Linked List in C
C Programs - Hashing
Hash Tables in C
Double Hashing in C
Hash Tables with Singly Linked Lists in C
Hash Tables with Doubly Linked Lists in C
Hash Tables with Binary Trees in C
Hashing with Linear Probing in C
Hashing with Quadratic Probing in C
C Programs - Stack
Stack Program in C
Stack using Two Queues in C
Reverse a Stack using Recursion in C
Reverse a Stack without Recursion in C
Stack Operations using MACROS in C
Stack Operations using Dynamic Memory Allocation in C
Implement Two Stacks in a Single Array in C
Balanced Parenthesis in C
Tower of Hanoi Program in C
C Programs - Queue
Queue Program in C
Priority Queue Operations in C
Queue using Array in C
Queues using Stack in C
Queue Using Two Stacks in C
Queue using Array and Macros in C
Queue using Dynamic Memory Allocation in C
Data Structure Misc
Priority Scheduling Program in C
SJF Scheduling Program in C
Round Robin Scheduling Program in C
FCFS Scheduling Program in C
Vector Program in C
Trie Program in C
Magic Squares Puzzle without Recursion in C
C Resources
1000 C MCQ
C Programming Tests
C Certification Test
C Internship
C Tutorial
Best C Programming Books
C Videos
Advanced C Programming
C Interview Questions



Related Topics
Java Programs on Collections
C++ STL
Data Structures in Java
Data Structures in C
Data Structures in C++

Popular Pages
Linked List Programs in C
Linked List Programs in Python
Data Structure MCQ Questions
Python Programming Examples
Tree Programs in Java

.
About | Certifications | Internships | Jobs | Privacy Policy | Terms | Copyright | Contact
© 2011-2023 Sanfoundry. All Rights Reserved.
Scroll back to top
Branchwise MCQs
School MCQs
DSA
Tests
Jobs
Internship
Training
Videos
Books
Contact
C Programming
C Programs
C Programs - Heap
C Programs - Linked List
C Programs - Singly Linked List
C Programs - Doubly Linked List
C Programs - Hashing
C Programs - Stack
C Programs - Queue
Data Structure Misc
C Resources
C Videos
}
