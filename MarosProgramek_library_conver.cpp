// Example program
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm> 

using std::cin;                     
using std::cout;                    
using std::endl;
using std::string;    
using std::vector;
using std::reverse;

char convert(const char& c)
{
    //List of all vowels
    static const string wovel_list = "aeiouyAEIOUYýáíéúóÝÁÍÉÓÚůŮ";
    //If no change is done, the convert is dummy
    char modified_c=c;
    //Condition for vowel: find(wovel_list.begin(), wovel_list.end(), c) != wovel_list.end()
    if(isalpha(c) && !(find(wovel_list.begin(), wovel_list.end(), c) != wovel_list.end()) && isupper(c)) modified_c=tolower(c);    
    if(isalpha(c) &&  (find(wovel_list.begin(), wovel_list.end(), c) != wovel_list.end()) && islower(c)) modified_c=toupper(c);
    //Return modified c
    return(modified_c);
}

vector<string> splitAndReverse(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = s.size()-1;
    //Until we are on first character, we are serching in revers
    while (i > 0) 
    {
        //Ignoring trailing spaces
        while (i > 0 && isspace(s[i]))
        {
            i--;
        }
        //Now i dentores the end of the last word
        string_size j = i;
        //Until we are on first character and we have not found space
        while (j > 0 && !isspace(s[j]))
        {
            j--;
        }
        // If we have found some nonwhitespace characters 
        // i is the end of the word, j is the begging
        if (i != j) 
        {
            string word;
            //Now let's go backwards and store converted value
            while(i>j)
            {
                char letter = s[i];                 
                word = word + convert(letter);                
                i--;                
            } 
            //On this place i = j. Only issue is with s[0] here
            if(i==0 && !isspace(s[0]))
            {
                word = word + convert(s[0]); 
            }
            //Now the whoel world is herer
            ret.push_back(word);
         }
    }
    return ret;
}

void MarosFunction(const string& word_delim)
{
  string input;
  vector<string> words;
  //Getting input
  cout << "Please provide input: " <<endl;
  getline (std::cin, input);
  //Transformation
  words=splitAndReverse(input);
  //Writing output
  for (vector<string>::size_type i = 0; i != words.size(); ++i)
  {
      cout << words[i] << word_delim;
  }  
}

int main()
{
  string dummy;
  //Configurable word delimeter - requested was " "     
  MarosFunction(" ");
  cout <<"\nEnd of this program." << endl;
  getline(cin,dummy);
}
