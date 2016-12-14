#!/usr/bin/env python2.7

import collections

class Sirens:
    _sirens = []
    _mappedSirens = []

    def __init__(self):
        self._sirens = []
        self._mappedSirens = []

    def setSirens(self, sirens):
        self._sirens = sirens

    def getSirens(self):
        return self._sirens

    def setMappedSirens(self, mappedSirens):
        _mappedSirens = mappedSirens

    def getMappedSirens(self):
        return self._mappedSirens

    def readSirensFromFile(self, fileName):
        try:
            with open(fileName) as f:
                for line in f:
                    self._sirens.append(line.strip('\n'))
        except IOError:
            return 1
        else:
            return 0

    def mapSirens(self):
        self._mappedSirens = collections.Counter(self._sirens)

    def countUnique(self):
        return sum(value == 1 for key, value in self._mappedSirens.iteritems())

    def countNonUnique(self):
        return sum(value > 1 for key, value in self._mappedSirens.iteritems())
