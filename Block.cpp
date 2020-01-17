#include "Block.h"

Block::Block():data(" "),       //string variables initialized as " ", so there will be no garbage value!
               timeStamp(" "),
               prevHash(" "),
               hash(" ")
{
    // std :: cout << "Constructor Called!";
}

Block::~Block()
{
    // std :: cout << "Program Terminated!";
}

std :: string Block::getTimeStamp() // A function that will note the time when the hashing is done.
{
    time_t now = time(0);
    char *dt = ctime(&now);
    return dt;
}

int Block::ascii(std :: string key) 
{
    int asciiValue = 0;
    for(int i = 0; i < key.size(); ++i)
    {
        asciiValue += key[i];        
    }
        return asciiValue;
}

std :: string Block::calculateHash(std :: string data ,std :: string timeStamp, std::string prevHash,int index) // Hash Calculations
{
    int d = ascii(data.c_str());
    int t = ascii(timeStamp.c_str());
    int p = ascii(prevHash.c_str());

    int h = (d + t + p + index);

    std :: stringstream x;
    x << h;

    std :: string s;
    x >> s;

    return sha256(s);
}


void Block::addBlock(Block block[], std :: string value, int num) // the function which will add the block into the function
{
    if(num == 0)
    {
        timeStamp = getTimeStamp();
        prevHash = "0";
        hash = calculateHash(data,timeStamp,prevHash,num);
        data = value;
    }
    else
    {
        timeStamp = getTimeStamp();
        prevHash = block[num - 1].hash;
        hash = calculateHash(data,timeStamp,prevHash,num);
        data = value;
    }
}


void Block::displayChain(int num) //Display Function
{
    std :: cout << "------------------------------"                          <<  std :: endl;
    std :: cout << "House Number: "                 << data << " Stored!"    <<  std :: endl;
    std :: cout << "Encryption Key: "              << hash                   <<  std :: endl;
    std :: cout << "Time: "                        << timeStamp              <<  std :: endl;
    std :: cout << "Previous Encryption Key: "     << prevHash               <<  std :: endl;
    std :: cout << "------------------------------"                          <<  std :: endl;
}


