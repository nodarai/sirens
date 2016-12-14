#include "Sirens.h"

using namespace std;

vs Sirens::getSirens(void) {
    return sirens;
}
void Sirens::setSirens(vs s) {
    sirens = s;
}

void Sirens::addToSirens(string siren) {
    sirens.push_back(siren);
}

void Sirens::mapSirens(void) {
    
    for (size_t i = 0; i < sirens.size(); ++i) {
        pair<umSst::iterator, bool> ret;
        ret = mappedSirens.insert(umSst::value_type(sirens[i], 1));
        
        if(ret.second == false) {
            mappedSirens[sirens[i]] += 1;
        }
    }
}


size_t Sirens::countUnique(void) {
    size_t count = 0;
    for (umSst::iterator it = mappedSirens.begin(); it != mappedSirens.end(); ++it) {
        if (it->second == 1) {
            ++count;
        }
    }
    return count;
}

size_t Sirens::countNonUnique(void) {
    size_t count = 0;
    for (umSst::iterator it = mappedSirens.begin(); it != mappedSirens.end(); ++it) {
        if (it->second != 1) {
            ++count;
        }
    }
    return count;
}

void Sirens::readSirensFromFile(string fileName) {
    
    sirensFile.open(fileName);
    string siren;
    
    if (sirensFile.is_open()) {
        while (getline (sirensFile, siren)) {
            sirens.push_back(siren);
        }
        sirensFile.close();
    }
    else 
         cout << "Can not open file"; 
}
