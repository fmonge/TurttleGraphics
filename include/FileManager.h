#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <stdexcept>

using namespace std;

class FileManager
{

    private:
        int GetCharOcurrenceCount(char pCharacter, string pLine){
            int res = 0;

            for(unsigned int index = 0; index < pLine.size(); index++){

                if(pLine[index] == pCharacter){

                    res++;
                }
            }
            return res;
        }

    public:

        string* StringSplit(char pCharacter, string pLine, int &arraySize){
            arraySize = GetCharOcurrenceCount(pCharacter, pLine)+1;

            string* result = new string[arraySize];


            int spotIndex = 0;
            for(int index = 0; index < pLine.size(); index++){

                if(pLine[index] != pCharacter){

                    result[spotIndex] += pLine[index];

                }
                else{
                    spotIndex++;
                }
            }

            return result;
        }



};

#endif // FILEMANAGER
