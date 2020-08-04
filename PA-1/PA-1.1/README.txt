First Name      Last Name       UIN             Section     User Name       E-mail address
Cora            English         127007634       508         coraenglish     coraenglish@tamu.edu


Aggie Honor statement:
I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
    Cora English 1/22/19


Resources used (provide URL):
We did not learn enums or enum classes in my 121 class last semester so this was a bit of a struggle.
https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/
https://en.cppreference.com/w/cpp/language/enum


Known problems with the assignment (include short explanation):
N/A


Short description or pseudocode:
This program creates stress balls of random or specified color and size.


Testing process:
    1. Created Stress_ball header/class and enum class headers
    2. Created default and parameterized constructor
    3. Overloaded the << operator
        a. Had trouble figuring out how to access members of the enum classes but found useful info in linked sources
        b. [TEST] Tested the << operator first with parameterized constructor then with default constructor
            i. Noticed there was a problem with randomizing the default when going through a loop and realized this was from including 
            srand(time(NULL)) in the constructor. Removed this and had no issues.
    4. Overloaded the == operator
        a. [TEST] Tested this with responses that should return true and ones that should return false for parameterized constructor
        b. [TEST] Tested with the array of stress balls created by the default constructor given the sample main code on ecampus
