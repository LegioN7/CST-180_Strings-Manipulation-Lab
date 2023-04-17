// Name: Aaron Pelto
// Week: 10
// Program: String Manipulation Lab

/*
*****************************************************************************************************************
Goal of Program
Declare an array to store a sentence (up to 80 characters). Prompt operator to enter a sentence (store
in the array). Utilize the following functions to perform analysis on the input sentence.
*****************************************************************************************************************

*****************************************************************************************************************
FindLength - Done

Primary responsibility: Return the length of the sentence. (Display length in main).

HOW: Pass the sentence array to the function. Use a loop counter as a subscript to
access each character: Initialize to zero and increment to locate the NULL character
(end of string terminator '\0'). Return the counter value for display.
*****************************************************************************************************************

*****************************************************************************************************************
ConvertCaps - Done

Primary responsibility: Convert the sentence to all capitals. (Display from main).

HOW: Pass the sentence array to the function. Set up a loop looking for the NULL.
Within the loop, examine each character of the string. If it is lower case (between 'a'
and 'z'), convert to upper case by a simple math operation (see ASCII table).
*****************************************************************************************************************

*****************************************************************************************************************
CountLetters - Done

Primary responsibility: Determines the number of letters contained in the sentence.
(Display the results from main).

How: Pass the sentence array to the function. Set up a loop to look for the NULL
character. Inside the loop, use a decision construct to examine each character and
determine whether the character is with the range of ‘A-Z’.
*****************************************************************************************************************

*****************************************************************************************************************
CountVowels

Primary responsibility: Count the number of each vowel. # of A's, # of E's, etc. (Display
the results from main).

HOW: Pass the sentence array and 5 counters to the function. (Use referenece variables
for the 5 counters because you can only return one thing via the return statement). Set
up a loop to look for the NULL character. Inside the loop, use a decision construct to
examine each character and determine which vowel counter (if any) should be
incremented.
*****************************************************************************************************************

*****************************************************************************************************************
CountWords

Primary responsibility: Count the number of words in the sentence. (Display the
results from main).

HOW: Pass the sentence array to the function. Set up a loop looking for the NULL.
Within the loop, examine each character of the string. Inside the loop, use a decision
construct to examine each character and determine whether the character is a
separator between words. Return the word count for display in main.
*****************************************************************************************************************

*****************************************************************************************************************
ReverseString

Primary responsibility: Copy the sentence in reverse order. (Display original sentence
and reversed sentence from main).

HOW: Pass the sentence array, an empty array, and the result from your FindLength
function into this function. Initialize your loop counter to (string length - 1) and count
down to zero. Use the loop counter as a subscript to access each character of the
sentence from last to first. Assign that character to the empty array from first to last.
(Note that you will need a second subscript for the second array.)
*****************************************************************************************************************

*****************************************************************************************************************
In addition to the above functions, you should also have your program determine the number of
consonants that the string contains and output this value as well as the others. This is easily determined
once you know the number of letters and the total number of vowels.
*****************************************************************************************************************
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Functions
void sentenceInput(char[], int);
void stringCopy(char[], char[]);
int findLength(char[], int);
void convertCaps(char[], int);
int countLetters(char[], int);
int countVowels(char[], int, char);
int countConsonants(char[], int);
int countWords(char[], int);
void reverseString(char[], char[], int);

// Constants being Declared
const int SIZE = 81;

// This is my test sentence
// I really think this sentence is eighty characters long and its a beautiful day today
int main()
{

    char wordFirst[SIZE] = "";
    char wordSecond[SIZE] = "";
    char sentenceReverse[SIZE] = "";

    char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u';

    // Input the Sentence into the wordFirst Array
    sentenceInput(wordFirst, SIZE);
    cout << "The sentence you entered is - " << wordFirst << ".\n";

    // Copy the String to prevent overwriting the sentence
    stringCopy(wordFirst, wordSecond);

    // Convert the array to Uppercase
    convertCaps(wordSecond, SIZE);

    // get the length for Reverse String
    int k = findLength(wordFirst, SIZE);

    // Shows the sentence reversed
    cout << "The sentence reversed is - ";
    reverseString(wordFirst, sentenceReverse, k);

    // Counting the Length of the Array
    cout << "\nThe total amount of characters in your sentence is " << findLength(wordFirst, SIZE) << ".\n";

    cout << "\n*******************************************************************************\n";
    cout << "There are " << countLetters(wordFirst, SIZE) << " letters in this sentence.\n";
    cout << "\n*******************************************************************************\n";

    cout << "\n*******************************************************************************\n";
    cout << "There are " << countVowels(wordFirst, SIZE, a) << " A vowel(s) in this sentence.\n";
    cout << "There are " << countVowels(wordFirst, SIZE, e) << " E vowel(s) in this sentence.\n";
    cout << "There are " << countVowels(wordFirst, SIZE, i) << " I vowel(s) in this sentence.\n";
    cout << "There are " << countVowels(wordFirst, SIZE, o) << " O vowel(s) in this sentence.\n";
    cout << "There are " << countVowels(wordFirst, SIZE, u) << " U vowel(s) in this sentence.\n";
    cout << "\n*******************************************************************************\n";

    cout << "\n*******************************************************************************\n";
    cout << "There are " << countConsonants(wordFirst, SIZE) << " Consonant(s) in this sentence.\n";
    cout << "\n*******************************************************************************\n";

    cout << "\n*******************************************************************************\n";
    cout << "There are " << countWords(wordFirst, SIZE) << " words(s) in this sentence.\n";
    cout << "\n*******************************************************************************\n";
}

// This is to input the sentence
void sentenceInput(char wordFirst[], int SIZE)
{

    cout << "Enter a Sentence no larger than " << (SIZE - 1) << " characters." << endl;
    cin.getline(wordFirst, SIZE);
    cout << "\n";
}

// This is just to copy the two strings
void stringCopy(char string1[], char string2[])
{

    int index = 0;

    while (string1[index] != '\0')
    {
        string2[index] = string1[index];
        index++;
    }

    string2[index] = '\0';
}

// This finds the length of the entire array with any characters
int findLength(char wordFirst[], int SIZE)
{

    int i;
    int count;

    count = 0;

    for (i = 0; wordFirst[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

// This converts the sentence to Caps and puts it in its own array
void convertCaps(char wordSecond[], int SIZE)
{

    int i;

    for (i = 0; wordSecond[i] != '\0'; i++)
        wordSecond[i] = toupper(wordSecond[i]);

    cout << "The sentence in all capitals is - " << wordSecond << ".\n";
}

// This counts the letters if it begins with A, and ends with z
int countLetters(char wordFirst[], int SIZE)
{
    int i;

    int letters;
    letters = 0;

    // a starts at 65 and goes to 122
    for (i = 0; i < SIZE; i++)
    {
        if (wordFirst[i] >= 'A' && wordFirst[i] <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

// This users the vowel from the input, and increments only if it meets the criteria for the vowel
int countVowels(char wordFirst[], int SIZE, char vowel)
{
    int i;
    int j;
    int count;
    count = 0;

    for (i = 0; i < SIZE; i++)
    {
        wordFirst[i] = tolower(wordFirst[i]);
    }

    for (j = 0; wordFirst[j] != '\0'; j++)
    {
        if (vowel == 'a' && wordFirst[j] == 'a')
        {
            count++;
        }
        else if (vowel == 'e' && wordFirst[j] == 'e')
        {
            count++;
        }
        else if (vowel == 'i' && wordFirst[j] == 'i')
        {
            count++;
        }
        else if (vowel == 'o' && wordFirst[j] == 'o')
        {
            count++;
        }
        else if (vowel == 'u' && wordFirst[j] == 'u')
        {
            count++;
        }
    }
    return count;
}

// This will count the words by using space as the option
int countWords(char wordFirst[], int SIZE)
{

    int words = 0;
    int i;
    int j;

    for (i = 0; wordFirst[i]; ++i)
    {
        wordFirst[i] = tolower(wordFirst[i]);
    }

    for (j = 0; j < SIZE; j++)
    {
        if (wordFirst[j] == ' ')
        {
            words++;
        }
    }
    words = words + 1;
    return words;
}

// This will reverse the original array and output the reverse string in a output array
void reverseString(char input[], char output[], int length)
{

    int i;
    int j = 0;
    for (i = length - 1; i >= 0; i--, j++)
    {
        output[j] = input[i];
    }

    cout << output;
}

// This will count the Consonants in the original array
int countConsonants(char wordFirst[], int SIZE)
{

    int i;
    int j;
    int count;
    count = 0;

    for (i = 0; i < SIZE; i++)
    {
        wordFirst[i] = tolower(wordFirst[i]);
    }

    for (j = 0; wordFirst[j] != '\0'; j++)
    {
        if (wordFirst[j] != 'a' && wordFirst[j] != 'e' && wordFirst[j] != 'i' && wordFirst[j] != 'o' && wordFirst[j] != 'u' && wordFirst[j] != ' ')
        {
            count++;
        }
    }
    return count;
}
