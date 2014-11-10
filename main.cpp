/*

Author: Tyler Arseneault
Date: November 10, 2014
Assignment 3

Purpose: This program will take text from a text file and store it into a dictionary. It will sort the dictionary alphabetically, and display the words in the dictionary along with their frequency of occurence.

*/


#include <stdio.h>

#include <stdlib.h>

#include <string>

#include <iostream>

#include <iomanip>

using namespace std;


const int MAX = 100;


typedef string STRING;

typedef bool BOOL;

typedef string WORD;    

/*

    structure describing a word entry in the dictionary

*/

typedef struct entry {

      int count;                  /* frequency count for a particular word */

      WORD w;                     /* the word itself */

      struct entry *nextWord;     /* pointer to next entry */

} ENTRY;


/*

    structure describing the dictionary

*/


typedef struct dict {

     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */

                                   /* link lists can be as big as you want. This limit ensures that   */

                                   /* this code tries to behave like the previous ones */

                                   

     int numWords;                 /* number of words in the dictionary */

     ENTRY *Words;                 /* pointer to the entries in the dictionary */

} DICT;


ENTRY *LocateWord(DICT&,WORD);

BOOL FullDictionary(DICT&);

BOOL InsertWord(DICT&,WORD);

WORD GetNextWord(void);

void DumpDictionary(DICT&);

void SortDict(DICT&); //Sorts the dictionary


DICT dictionary={MAX,0,0};  /* your dictionary */

WORD word;                 /*   */


int main (void) {

    ENTRY *pos;


    while (1) {

       word = GetNextWord();

       if ( word.empty() )  {

           DumpDictionary(dictionary);

           break;

       }

       if ((pos = LocateWord(dictionary,word)) >  0 ) 

           pos->count++;

       else

           if (!InsertWord(dictionary,word)) cout << "dictionary full" << word <<  "cannot be added\n";

    }

    return 0;

}
