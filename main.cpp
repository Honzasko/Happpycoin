#include <iostream>
#include <stdlib.h>
#include <vector>
#include "include/sha256.h"
using namespace std;

unsigned int parts_end[255];
unsigned int parts_current[255];
bool parts_finishes[255];
bool found = false;

int zero(std::string hash_text)
{
  int for_return = 0;
  for(unsigned int i = 0;i < hash_text.size();i++)
  {
    if(hash_text[i] == '0')
    {
      for_return++;
    }
    else
    {
      i = hash_text.size();
    }
  }
  return for_return;
}
std::string world = "";//string with chain
int zeros = 5;//chain require number of zeros
void calc(int p_number)
{
    if(!parts_finishes[p_number])
      {
         std::string hs = sha256(world + to_string(parts_current[p_number]));
         cout << hs << endl;
         if(zero(hs) == zeros)
         {
           parts_finishes[p_number] = true;
           cout << parts_current[p_number] << endl;
         }
         else
         {
           if(parts_current[p_number] == parts_end[p_number])
           {
             parts_finishes[p_number] = true;
           }
           else
           {
             parts_current[p_number]++;
           }
         }

   }
}

int main()
{
    for(int i = 0;i < 255;i++)
    {
       parts_end[i] = false;
    }
    for(unsigned int i = 0;i < 255;i++)
    {
      parts_current[i] = 16843009*i;
    }
    for(unsigned int i = 1;i < 256;i++)
    {
      parts_end[i-1] = 16843009*i;
    }
     for(unsigned int i = 0;i < 16843009;i++)
     {
       for(int h = 0;h < 51;h++)
       {
         if(!parts_finishes[h])
      {
         std::string hs = sha256(world + to_string(parts_current[h]));
         cout << hs << endl;
         if(zero(hs) == zeros)
         {
           cout << parts_current[h] << endl;
           return 0;
         }
         else
         {
           if(parts_current[h] == parts_end[h])
           {
             parts_finishes[h] = true;
           }
           else
           {
             parts_current[h]++;
           }
         }

      }
       }

     }
    return 0;
}
