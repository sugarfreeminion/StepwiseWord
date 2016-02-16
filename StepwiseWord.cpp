/*
 * Stepwise Word Code Eval Challenge
 * Prints the longest word in a stepwise manner
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void PrintStepwise(const string longestWord)
{
    unsigned int index = 0;
    unsigned int tempIndex = 0;

    while(index < longestWord.size())
    {
        while(tempIndex < index)
        {
            cout << "*";

            ++tempIndex;
        }

        if(index != (longestWord.size()-1))
        {
            cout << longestWord[index] << " ";        
        }
        else
        {
            cout << longestWord[index] << endl;
        }

        tempIndex = 0;
        ++index;
    }
}

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;
        
        while(getline(inputFile,line))
        {
            stringstream lineStream(line);
            unsigned int longestIndex = 0;
            unsigned int index = 0;
            string temp;
         
            vector<string> data;

            while(getline(lineStream,temp,' '))
            {
                data.push_back(temp);
            }

            for(vector<string>::const_iterator itr=data.begin();
                itr != data.end();
                ++itr)
            {
                //cout << "Size of " << *itr << " is: " << (*itr).size() << endl;
                
                if((*itr).size() > data[longestIndex].size())
                {
                    longestIndex = index;
                }

                ++index;

                //cout << *itr << endl;
            }

            PrintStepwise(data[longestIndex]);

            //cout << "Longest word is: " << data[longestIndex] << endl;
        }
        inputFile.close();
    }

    return 0;
}
