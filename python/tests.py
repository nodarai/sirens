#!/usr/bin/env python2.7

import unittest
from sirens import Sirens

class TestSirens(unittest.TestCase):
    def testOpenFile(self):
        sirens = Sirens()
        self.assertEqual(sirens.readSirensFromFile("nonexisting.txt"), 1, "Should return 1 if file does not exist")
        self.assertEqual(sirens.readSirensFromFile("../tests/exists.txt"), 0, "Should return 0 if file exists")
        
    def testOne(self):
        fileName = "../tests/firstTest.txt"
        sirens = Sirens()
        self.assertEqual(sirens.readSirensFromFile(fileName), 0, "Can not open file" + fileName)
        sirens.mapSirens()
        self.assertEqual(sirens.countUnique(), 1, "For one SIREN should return 1")
        self.assertEqual(sirens.countNonUnique(), 0, "For one SIREN should return 0")
        
    def testTwo(self):
        fileName = "../tests/secondTest.txt"
        sirens = Sirens()
        self.assertEqual(sirens.readSirensFromFile(fileName), 0, "Can not open file" + fileName)
        sirens.mapSirens()
        self.assertEqual(sirens.countUnique(), 2)
        self.assertEqual(sirens.countNonUnique(), 0)
        
    def testTwoDuplicate(self):
        fileName = "../tests/secondTestDuplicate.txt"
        sirens = Sirens()
        self.assertEqual(sirens.readSirensFromFile(fileName), 0, "Can not open file" + fileName)
        sirens.mapSirens()
        self.assertEqual(sirens.countUnique(), 0)
        self.assertEqual(sirens.countNonUnique(), 1)
        
    def testThree(self):
        fileName = "../tests/thirdTest.txt"
        sirens = Sirens()
        self.assertEqual(sirens.readSirensFromFile(fileName), 0, "Can not open file" + fileName)
        sirens.mapSirens()
        self.assertEqual(sirens.countUnique(), 1)
        self.assertEqual(sirens.countNonUnique(), 1)
        

unittest.main()
    