
#include"HashManager.h"
#include"CountAsciiHash.h"
#include"CountConsonantHash.h"
#include"CountVowelsHash.h"
#include"EasyHash.h"
#include"Hash.h"
/*
Write the followind classes in C++:
- An abstract class Hash that has a method that calculates a hash from a string and returns the appropriate number type;
- Derive from this class several classes that can calculate a hash from:
  - counting the number of vowels in the string;
  - counting the number of consonants in the string;
  - adding the ascii codes of each character;
  - add together the chars as: each vowel will be mutiplied by 10, each consonant will be mutiplied by 11, each other
char will be mutiplied by 12;
- A class HashManager that keeps a list of hashes with names:
  - has the appropriate operators implemented;
  - has a function print_hashes that prints the name of the hash and the hash for each hash;
- Organize the code in the following way:
  - a .h and a .cpp (where is needed) for each class;
  - a main.cpp for the main function;
- You may NOT use from std: any templated function/class, functions for string manipulation, malloc, calloc, free.
*/

int main() {
    HashManager hashes;
    hashes["count_vowels"] = new CountVowelsHash();
    hashes["count_consonant"] = new CountConsonantHash();
    hashes["count_ascii"] = new CountAsciiHash();
    hashes["easy_ascii"] = new EasyHash();

    hashes.print_hashes("Did you ever hear the tragedy of Darth Plagueis the Wise?");
}

/*
How are points divided:
- Declare abstract class 1p
    - declare class 0.3p
    - declare function correctly 0.7p
- Define derived classes 1.25p for each, in total 5p
    - for each derived class:
        - 0.25p only for declaration + correct access modifiers
        - 0.25p inheritance
        - 0.75p define required methods / members
- Define the class HashManager 2p
    - 0.7 storing the hashes
        - 0.3 for only the declaration
        - 0.4 correct implementation
    - 0.65 for implementing the operator
        - 0.25 for only the declaration
        - 0.4 correct implementation
    - 0.65 for print_hashes
        - 0.25 for only the declaration
        - 0.4 correct implementation
- 1p for using .cpp and .h files
- 1p compiling and running correctly (with all the required code)
*/