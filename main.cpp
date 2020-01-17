#include "Block.h"
#include "sha256.h"
#include <iomanip>

int main()
{
    std :: string value{" "};

    int i{0};
    int num{0};
    
    std :: cout << "      -------------------------------------------------------"     << std ::  endl;
    std :: cout << std::setw(40) << "FUTURE INTELLIGENCE"                              << std ::  endl;
    std :: cout << std::setw(56) << "THE FINEST DHA LAND RECORD SYSTEM EVER CREATED!"  << std ::  endl;
    std :: cout << "     -------------------------------------------------------"      << std ::  endl;



    std :: cout << "\nEnter the number of Blocks: ";
    std :: cin >> num;

    Block *block = new Block[num];

    for(int i = 0 ;i < num; ++i)
    {
        std :: cout << "Enter the House Number: ";
        std :: cin >> value;

        block[i].addBlock(block,value,i);
        block[i].displayChain(num);
    }
}