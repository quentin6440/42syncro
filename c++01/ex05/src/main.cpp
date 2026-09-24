#include "../include/Harl.h"

int main(void) 
{
    Harl myharl;
    
    myharl.complain("DEBUG");
    myharl.complain("INFO");
    myharl.complain("WARNING");
    myharl.complain("ERROR");
    myharl.complain("UNINTELLIGIBLE LAYUS");

    return 0;
}