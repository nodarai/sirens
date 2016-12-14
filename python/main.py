#!/usr/bin/env python2.7

from sirens import Sirens
import sys

def main():
    fileName = "../sirens_fxt.txt"
    
    if len(sys.argv) > 2:
        print "Please, provide only one argument."
        
    if len(sys.argv) == 2:
        fileName = sys.argv[1]
        
    sirens = Sirens()
    if sirens.readSirensFromFile(fileName):
        print "Can not open file ", fileName
        return
    
    sirens.mapSirens()
    
    print "Unique SIRENs are %d" % sirens.countUnique()
    print "Non Unique SIRENs are %d" % sirens.countNonUnique()
        

if __name__ == '__main__': main()