Student Information
####################
Spencer Ploeger
sploeger@uoguelph.ca
0969141

Program Description
###################
Assignment 3 - CIS2520, University of Guelph
Last Edited: Oct/22/2017
- Spell Checker, implementing a hashtable with the supplied API.

Additional Program Details
##########################
TO RUN THE MAIN: from the main directory of the program, open terminal and type 'make' and press enter, then type 'make run' and press enter. **to update the dictionary file to use
open up the MAKEFILE and change the file directory to use and then save.

TO RUN THE MAIN TEST: from the main directory of teh program, open terminal and type 'make' and press enter, then type 'make test' and press enter.

FILE TO SPELLCHECK:  User supplied data file to spell check is output to a file in ./assets/ called "output.txt"

Assumptions
###########
1. The same words with lowercase versus capital letters will be treated as seperate words.  This instruciton was not explicity stated, so I made this assumption.  It would be a quick fix to add tolower to the user input to the dictionary if this assumtion turns out to be wrong.
2. The user will only enter alphabetic characters



Future Improvements
###################
In future revisions of this program, the following errors will be fixed:
1. The user will not be be allowed to enter non-alphabetic input, for now it will just cause an error
2. Delete list is encountering an error where no matter what, it is not setting the list to null.  This will be fixed in the next revision
3. Defensively program user input so the program will not crash when improper input is entered.


Hash Function and Collision Resolution Strategy
###############################################
The hash function in this program adds the ascii values of the first and last letter of each word (upper and lower case treated differently), and adds them together, then subtracts 115. This allows there to be 114 unique indexes in the hash table, with the lowest being index 0 and the highest being 114.  This is a very basic hash (but it was reccomended to me by my TA, Devin), although it still reduces search time by 1/114th of a straight O(N) search.

The collision resolution strategy is a type of linear probing.  I used the word it self as the key.  This way, there are no two entries with the same key.  The only collision that may occur is a word that is hashed to the same index of another word.  The resolution to this is linear probing.  If there is an node in the index where a word is to be inserted, the insert function will keep incrementing nodes until the end of the index is reached, and it will insert the word there.