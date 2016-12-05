#include <iostream>
#include "PigLatinTranslator.h"
using namespace std;
string pigLatin(string engWord)
 {
   string pigWord;
   int wordLen = engWord.length( ), letter = 0;
   bool found = false;
   while (!found && letter < wordLen) // look for first vowel in word in word
     {
       if (engWord.substr(letter,1) == "a" ||
       engWord.substr(letter,1) == "e" ||
       engWord.substr(letter,1) == "i" || // check to see if letter is vowel
       engWord.substr(letter,1) == "o" ||
       engWord.substr(letter,1) == "u" ||
       engWord.substr(letter,1) == "y" )
           found = true;
       else
           letter++; // if not vowel, go to next letter
     }
   if (letter > wordLen)
       pigWord = engWord + "ay "; // add ay to end of word
   else
   // move front to end and add ay
   pigWord = engWord.substr(letter, wordLen-letter) + engWord.substr(0,letter)+ "ay " ;
   return pigWord; // print pig latin word
 }

string latin(const string& sentence){
 string engWord, engWords, output;
 engWords = sentence;
 bool finished = false;
 int position;
   while (!finished) // while all words not finished continue the loop
   {
     position = engWords.find(" "); // look for space separating words
     if (position == -1) // if no spaces left, set finished to true
       {
         finished = true;
         position = engWords.length( ); // set position to remaining length of phrase
       }
     engWord = engWords.substr(0, position); // separate word
     output += pigLatin(engWord); // call function to translate word
     // delete processed word and move to next word
     if (!finished)
         engWords = engWords.substr(position + 1, engWords.length( ) - position + 1);
   }
 return output;
}

// int main( )
//  {
//    string sentence, piglatin;
//    cout << "Pig Latin Program " << endl << endl;
//    cout << "Enter English text to translate: ";
//    getline(cin, sentence); // enter phrase to be translated
//    piglatin= latin(sentence);
//    cout<<piglatin<<endl;
//    return(0);
//  }