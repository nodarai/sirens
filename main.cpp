#include "Sirens.h"

int main() {
    
    Sirens sirens;
    sirens.readSirensFromFile("sirens_fxt.txt");
    sirens.mapSirens();
    
   // sirens.countUnique()
    std::cout << "Unique SIRENs are " << sirens.countUnique() << std::endl;
    std::cout << "Non Unique SIRENs are " << sirens.countNonUnique() << std::endl;
    
    return 0;
}
