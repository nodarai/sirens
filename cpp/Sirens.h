#ifndef SIRENS_H
#define SIRENS_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>


typedef std::vector<std::string> vs;
typedef std::unordered_map<std::string, std::size_t> umSst;

class Sirens {
    
private:
    vs sirens;
    umSst mappedSirens;
    std::ifstream sirensFile;
    
public:
    Sirens() {};
    ~Sirens() {};
    
    vs getSirens(void);
    void setSirens(vs);
    void addToSirens(std::string);
    int readSirensFromFile(std::string fileName, std::size_t = -1);
    void mapSirens(void);
    std::size_t countUnique(void);
    std::size_t countNonUnique(void);
    
};


#endif
