First Name      Last Name       UIN             Section     User Name       E-mail address
Cora            English         127007634       508         coraenglish     coraenglish@tamu.edu


Aggie Honor statement:
I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
    Cora English 2/5/19


Resources used (provide URL):
https://en.cppreference.com/w/cpp/language/move_constructor
https://en.cppreference.com/w/cpp/language/move_assignment
http://www.cplusplus.com/doc/tutorial/exceptions/
https://www.geeksforgeeks.org/insertion-sort/
https://www.geeksforgeeks.org/selection-sort/



Known problems with the assignment (include short explanation):
N/A


Short description or pseudocode:
This program creates a Collection class that serves as a dynamic array to hold stress balls. It can copy, remove, and sort the elements.


Testing process:
    1. Being honest here, didn't try to complie this until I finished all of the functions including the overloaded istream and ostream operators.
    2. I wrote the test file where the main is next and followed the guidlines for what I had finished which included reading in from files, 
       outputting to console, and making unions of collections.
    3. When I did compile and test it, the only things that were a little bit broken were the resize and remove this element functions.
        i. The resize function did not account for the case when size == 0. So that was fixed after realizing that's why my program was seg faulting.
        ii. The remove this element function was not removing the correct element when I did not have my for loops nested. I nested them and moved the
            size decrement inside the if statement and that fixed the problem that was occurring.
    4. Next, I wrote the sorting functions and tested those. This was before we talked about insertion and selection sort in class so the resources I 
       used to educate myself are listed above. All 3 of these worked, the selection sort had to be tweaked a little bit as I tested it, but other than
       that there weren't too many problems.
