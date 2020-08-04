First Name      Last Name       UIN             Section     User Name       E-mail address
Cora            English         127007634       508         coraenglish     coraenglish@tamu.edu


Aggie Honor statement:
I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
    Cora English 3/6/20


Resources used (provide URL):
Slides from class


Known problems with the assignment (include short explanation):
N/A


Short description or pseudocode:
This program creates a templated queue adapted from a doubly linked list with dummy header and trailer nodes.


Justification of runtimes:
    Constructor: The constructor only creates a new, empty dll in the minqueue class by pointing the header node to the 
    trailer node which makes it O(1).
    Destructor: The destructor points the header to the trailer, which makes it O(1).
    Enqueue: Enqueue adds an element to the end of the list by changing where the pointer to the trailer and trailer point, 
    which makes it O(1).
    Dequeue: Dequeue removes an element from the beginning of the list by changing where the pointer to the header and header next point, 
    which makes it O(1).
    Size: Size only returns the private variable from the dll class which makes it O(1).
    isEmpty: isEmpty checks to see if header is pointing at trailer which makes is O(1).
    Min: Min in the worst case has to go through every element in the linked list in order to check and see if it is less than the current min.
    This makes min O(n) in the worst case, O(1) in the best case and O(n/2) in the average case.

Testing process
    1. I started by deleting all of the unnecessary functions in the TemplatedDLList header.
    2. Then, I followed the lecture slides and adapted the DLL class to fit the MinQueue class.
    3. After that I fixed the << operator to allow the MinQueue class to be printed to the terminal.
        a. There was a little bit of trouble overloading the operator so I added the first and last functions which also
        adapted functions already written in the DLL class to output header and trailer pointers.
    4. Once the output operator was working
