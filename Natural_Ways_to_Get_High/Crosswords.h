﻿#pragma once

/*You are given two words.Find the first matching character between the two words in respect to the first word, and then output
the one with the largest length of the two horizontallyand
the smallest length vertically(if both words are of the same length then the second word given should be placed horizontally).

Both outputs have to separate each character with a spaceand be all uppercase, all while making a crossword from the two words.

If the two words given do not having a matching character, then output :
NO COMMON CHARACTER
Input
Line 1 : A string, words, separated by a space representing the words in order.
Output
The crossword from the two words
or
NO COMMON CHARACTER
Constraints
1 ≤ words length ≤ 14
Example
Input
cinnamon apple
Output
C I N N A M O N
        P
        P
        L
        E
*/

#include <iostream>
#include <string>
#include <algorithm> 

class Crosswords {
public:
    Crosswords(){}
    ~Crosswords(){}

    void crosswordsExec();

private:
};