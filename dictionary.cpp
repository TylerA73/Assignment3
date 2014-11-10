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





/*

  you will have to write code for these 5 functions. 

*/


ENTRY *LocateWord(DICT&,WORD);

BOOL FullDictionary(DICT&);

BOOL InsertWord(DICT&,WORD);

WORD GetNextWord(void);

void DumpDictionary(DICT&);

void SortDict(DICT&); //Sorts the dictionary



BOOL InsertWord(DICT &dict, WORD word)

{

/* 

  adds word to dictionary , if word can't be added returns false else returns true


*/

   if( !FullDictionary(dict) ){
      
      if(dict.numWords == 0){/* adds ENTRY if first position is free */

         dict.Words = new ENTRY;
         dict.Words->w = word;
         dict.Words->count = 1;
         dict.Words->nextWord = NULL;
         dict.numWords = 1;
         
      }

      else { /* adds ENTRY if first position is occupied */
         
         ENTRY *p = dict.Words;
         while(p->nextWord != NULL) p = p->nextWord;
         p->nextWord = new ENTRY;
         p = p->nextWord;
         p->w = word;
         p->count = 1;
         p->nextWord = NULL;
         dict.numWords++;
        
      }


      return true;

   }

   return false;

}


void DumpDictionary(DICT &dict) {

/* 

  will sort the dictionary, and display the contents

*/

   SortDict(dict);

   ENTRY *p = dict.Words;
   const int WIDTHFORMAT = 70;
   
   /*prints out the dictionary*/

   cout << left << setfill('-');
   cout << setw(WIDTHFORMAT);
   cout << "Word";
   cout << "Frequency";
   cout << endl;
   cout << endl;

   while(p != NULL){ /* prints out each ENTRY from the DICT */
      cout << left << setfill(' ');
      cout << setw(WIDTHFORMAT);
      cout << p->w;
      cout << p->count << endl;

      ENTRY *visited = p;
      p = p->nextWord;

      delete visited; /* frees memory for printed ENTRY */

   }
   cout << endl;

}


WORD GetNextWord(void){

/* 

   will retrieve next word in input stream. Word is defined just as in assignment #1 

   returns WORD or empty string if no more words in input stream

*/

   bool inputSuccess = false;
   char letter;
   WORD tmp;

   while( cin.good() ){

      letter = cin.get();

      if( isalpha(letter) ){

         letter = tolower(letter); //transforms letter to lowercase
         tmp.push_back( letter ); //pushes letter into word
         inputSuccess = true;

      }

     else if ( inputSuccess )
        return tmp;
   }

   return tmp;

}


BOOL FullDictionary(DICT &dict) {

/* 

   if dictionary is full, return true else false 

 */

   if(dict.numWords == dict.maxEntries) 
      return true;

   return false;

}


ENTRY *LocateWord(DICT &dict, WORD word) {

/*

   will determine if dictionary contains word. if found, returns pointer to entry else returns  0

*/

    ENTRY *p = dict.Words;
    
    while(p != NULL){
    
       if (p->w == word) return p;
       else p = p->nextWord;

    }

    return 0;

}

void SortDict(DICT &dict) { /* this function was added added by me. Will sort the dictionary
alphabetically */

   ENTRY *tmp = new ENTRY;
   ENTRY *i   = new ENTRY;
   i = dict.Words;

   /* sorts the dictionary alphabetically using selection sort */
   while ( i->nextWord != NULL ){
   
      ENTRY *j = new ENTRY;
      j = i->nextWord;

      while ( j != NULL ){

         if( (j->w) < (i->w)){

            tmp->w = j->w;
            tmp->count = j->count;
            j->w = i->w;
            j->count = i->count;
            i->w = tmp->w;
            i->count = tmp->count;

         }

         j = j->nextWord;
      }
      delete j;

   
      

      i = i-> nextWord;
   }
   delete tmp;


}
