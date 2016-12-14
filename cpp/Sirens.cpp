#include "Sirens.h"

using namespace std;

/*
 * Getter for siren vector.
 */
vs Sirens::getSirens(void) {
    return sirens;
}

/*
 * Setter for siren vector.
 */
void Sirens::setSirens(vs s) {
    sirens = s;
}

/*
 * Adds an SIREN string to sirens vector.
 */
void Sirens::addToSirens(string siren) {
    sirens.push_back(siren);
}

/*
 * Walk through sirens vector and count the number of occurrence for each SIREN.
 * Each SIREN present in siren vector will be a key in the map and the value
 * will be the number of occurrences.
 */
void Sirens::mapSirens(void) {
    
    for (size_t i = 0; i < sirens.size(); ++i) {
        pair<umSst::iterator, bool> ret;
        ret = mappedSirens.insert(umSst::value_type(sirens[i], 1));
        
        if(ret.second == false) {
            mappedSirens[sirens[i]] += 1;
        }
    }
}

/*
 * Returns a number of SIRENs with the value 1.
 */
size_t Sirens::countUnique(void) {
    size_t count = 0;
    for (umSst::iterator it = mappedSirens.begin(); it != mappedSirens.end(); ++it) {
        if (it->second == 1) {
            ++count;
        }
    }
    return count;
}

/*
 * Returns a number of SIRENs with the value 2 or more.
 */
size_t Sirens::countNonUnique(void) {
    size_t count = 0;
    for (umSst::iterator it = mappedSirens.begin(); it != mappedSirens.end(); ++it) {
        if (it->second != 1) {
            ++count;
        }
    }
    return count;
}

/*
 * Reads at most *max* SIRENs from *fileName* and adds them to siren vector.
 * Returns 1 if *fileName* can not be opened and 0 if everything  went OK.
 */

int Sirens::readSirensFromFile(string fileName, size_t max) {
    
    sirensFile.open(fileName);
    string siren;
    size_t i = 0;
    
    if (sirensFile.is_open() && i < max) {
        while (getline (sirensFile, siren)) {
            sirens.push_back(siren);
            ++i;
        }
        sirensFile.close();
    } else
         return 1;
    return 0;
}
