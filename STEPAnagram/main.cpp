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

                   //binary array to ensure every letter is in the input
                   bool* binary = new bool[dictionaryWord.length()];
                   for (int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       binary[ii] = false;
                   }
                   
                   //binary array to guard against invalid repeats
                   bool inputBin[16];
                   inputBin[0] = true;
                   inputBin[1] = true;
                   inputBin[2] = true;
                   inputBin[3] = true;
                   inputBin[4] = true;
                   inputBin[5] = true;
                   inputBin[6] = true;
                   inputBin[7] = true;
                   inputBin[8] = true;
                   inputBin[9] = true;
                   inputBin[10] = true;
                   inputBin[11] = true;
                   inputBin[12] = true;
                   inputBin[13] = true;
                   inputBin[14] = true;
                   inputBin[15] = true;
              
                   
                   for(int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       for(int xx = 0; xx < 16; xx++)
                       {
                           if(inputBin[xx] == true && dictionaryWord[ii] == inputWord[xx])
                          {
                              binary[ii] = true;
                              inputBin[xx] = false;
                          }//END if statement for new match found
                       }//END for loop for comparison of each letter (inner)
                   }//END for loop for comparison of each letter (outer)
                   
                   bool flag = false;
                   for (int ii = 0; ii < dictionaryWord.length(); ii++)
                   {
                       if(binary[ii] == false)
                       {
                           flag = true;
                       }
                   }
        
                   delete [] binary;
                   
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
