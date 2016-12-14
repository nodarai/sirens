#include "Sirens.h"

int main(int argc, char *argv[]) {
	std::string fileName = "../sirens_fxt.txt";

	if (argc > 2) {
		std::cout << "Please, provide only one argument." << std::endl;
		return 0;
	}

	if (argc == 2) {
		fileName = argv[1];
	}
    
    Sirens sirens;
    if (sirens.readSirensFromFile(fileName)) {
    	std::cout << "Can not open file " << fileName << std::endl;
    	return 1;
    }

    sirens.mapSirens();
    
    std::cout << "Unique SIRENs are " << sirens.countUnique() << std::endl;
    std::cout << "Non Unique SIRENs are " << sirens.countNonUnique() << std::endl;
    
    return 0;
}
