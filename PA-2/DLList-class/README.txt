First Name      Last Name       UIN             Section     User Name       E-mail address
Cora            English         127007634       508         coraenglish     coraenglish@tamu.edu


Aggie Honor statement:
I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
    Cora English 2/28/19


Resources used (provide URL):
Old 121 Code


Known problems with the assignment (include short explanation):
N/A


Short description or pseudocode:
This program creates a doubly linked list with a dummy node for the head and tail and performs some basic operations on it.


Testing process:
    1. First I finished all of the functions I could from looking at the lecture slides.
    2. Then I finished the basic constructors and destructors along with the copy constructor/assignment operator.
    3. I tested all of these with the main starter code file given.
    4. After all of these original functions were working correctly I wrote the before/after functions and tested those.
        a. I actually added a helper function which overloaded the [] operator in order to get to a certain node in the list.
        b. I also added a size variable for the DLList and a getter function to loop through when testing outputs.
    5. I finished the move constructor/assignment operator and had some issues with seg faulting which are all fixed now. I 
       was not assigning the header.next->prev to header and same with trailer.
    6. I added an extra test case to make sure the original lists were empty after calling the move constructor/assignment operator as well.
    7. Then I checked some of the scenarios to make sure the exceptions were being thrown and caught when they should be.
