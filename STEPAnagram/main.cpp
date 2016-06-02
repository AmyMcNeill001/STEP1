#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

const string dictionaryLocation = "//Users//amymcneill//Desktop//AnagramProject//AnagramProject//dictionary.txt";


int main()
{
    //string variables
    string inputWord = "";
    string dictionaryWord = "";
    string winner = "";
    
    //variables for exception handling
    unsigned long notSixteen = 111111;
    long wordTooLong = 111;
    unsigned char noWord;
    
    try
    {
        //gather user input for 16 letters
        cout << "Please enter exactly 16 letters: ";
        cin >> inputWord;
        
        cout << "Reading fine" << endl;
        
        //exception handling
        if (inputWord.length() != 16)
            throw notSixteen;
            
    
        //open the dictionary
        fstream inFileStream;
        inFileStream.open(dictionaryLocation.c_str());
        while(inFileStream)
        {
            try
            {
               inFileStream >> dictionaryWord;
            
               if(dictionaryWord.length() > 16)
                   throw wordTooLong;
                
               else if(dictionaryWord == inputWord)
               {
                   winner = dictionaryWord;
                   break;
               }
                
               else
               {
                   cout << "Getting to else statement" << endl;
                   //boolean array to avoid invalid double letter
                   bool inputBin[15];
                   
                   for(int ii = 0; ii < 16; ii++)
                   {
                       inputBin[ii] = false;
                   }
                   
                   cout << "Initializing inputBin fine" << endl;
                   //binary array to ensure every letter is in the input
                   bool* binary = new bool[dictionaryWord.length()];
                   for (int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       binary[ii] = false;
                   }
                   
                   cout << "No issue with dynamic allocation" << endl;
                   
                   for(int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       for(int xx = 0; xx < 16; xx++)
                       {
                           cout << "ii: " << ii << "xx: " << xx << endl;
                           cout << "InputBin: " << inputBin[xx] << endl;
                           cout << "inputword: " << inputWord[xx] << endl;
                          if(inputBin[xx] == false && dictionaryWord[ii] == inputWord[xx])
                          {
                              binary[ii] = true;
                              inputBin[xx] = true;
                          }//END if statement for new match found
                       }//END for loop for comparison of each letter (inner)
                   }//END for loop for comparison of each letter (outer)
                   
                   cout << "Making it past checkpoint 1" << endl;
                   bool flag = false;
                   cout << "bool assignment fine" << endl;
                   for (int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       cout << "For loop entered: " << ii << " times" << endl;
                       if(binary[ii] == false)
                       {
                           flag = true;
                       }
                   }
                   delete binary;
                   
                   if(flag == false && dictionaryWord.length() > winner.length())
                       winner = dictionaryWord;
               }
            }//END try block for wordTooLong
            
            catch(long)
            {
                //nothing to do here, just for efficiency
            }//END catch block for wordTooLong
        
        }//END while loop for exception handling
        
        //exception handling for no word found
        if (winner == "not a word")
            throw noWord;
        
        //announce the winner
        cout << "The longest word composed of only your sixteen letters is: " << winner << endl;
    }//END try block for notSixteen and noWord
    
    //exception handling
    catch(unsigned long)
    {
        cout << "I told you to put in 16 letters!" << endl;
    }
    
    catch(unsigned char)
    {
        cout << "I'm sorry, those letters make absolutely no words." << endl;
    }
    return 0;
}//END function main
