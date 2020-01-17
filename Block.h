#ifndef BLOCK_H
#define BLOCK_H

#include "sha256.h"

#include <iostream>
#include <iomanip> // For std::setw()
#include <sstream> //implements input/output operations on memory (string) based streams. stringstream can be helpful in parsing.
#include <cstdlib>
#include <ctime>
#include <string>

class Block  //class method is much easier and reliable
{
public:

    Block(); // Constructor
   ~Block(); // Distructor
    
    std :: string data;                         //Member Data
    std :: string hash;
    std :: string prevHash;
    std :: string timeStamp;
                                               //Member Functions

   std :: string getTimeStamp();               
   std :: string calculateHash(std :: string data ,std :: string timeStamp, std::string prevHash,int index);

   void addBlock(Block block[], std :: string value, int num); // To add the single linked list node
   void displayChain(int num); // Display the results

   int ascii(std :: string key); 

};
#endif