#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sirens.h"
#include <string>

TEST_CASE("Testing if files are opening correctly.") {
	Sirens sirens;
    SECTION("Open non existing file") {
		WHEN("the file nonexisting.txt does not exist") {
			THEN("readSirensFromFile should return 1") {
				REQUIRE(sirens.readSirensFromFile("nonexisting.txt") == 1);
			}
		}
    }
    SECTION("Open non file") {
		WHEN("the file exists.txt exists") {
			THEN("readSirensFromFile should return 0") {
				REQUIRE(sirens.readSirensFromFile("../tests/exists.txt") == 0);
			}
		}
    }
}

TEST_CASE("Testing number of (non)unique SIRENs.") {
    Sirens sirens;

    SECTION("One") {
    	REQUIRE(sirens.readSirensFromFile("../tests/firstTest.txt") == 0);
		sirens.mapSirens();
		WHEN("we have only one SIREN") {
			THEN("unique SIRENs are 1") {
				REQUIRE(sirens.countUnique() == 1);
			}
			THEN("non unique SIRENs are 0") {
				REQUIRE(sirens.countNonUnique() == 0);
			}
		}
    }
    SECTION("Two") {
    	REQUIRE(sirens.readSirensFromFile("../tests/secondTest.txt") == 0);
		sirens.mapSirens();
		WHEN("we have two distinct SIRENs") {
			THEN("unique SIRENs are 2") {
				REQUIRE(sirens.countUnique() == 2);
			}
			THEN("non unique SIRENs are 0") {
				REQUIRE(sirens.countNonUnique() == 0);
			}
		}
    }
    SECTION("Two Duplicate") {
    	REQUIRE(sirens.readSirensFromFile("../tests/secondTestDuplicate.txt") == 0);
		sirens.mapSirens();
		WHEN("we have two equal SIRENs") {
			THEN("unique SIRENs are 0") {
				REQUIRE(sirens.countUnique() == 0);
			}
			THEN("non unique SIRENs are 1") {
				REQUIRE(sirens.countNonUnique() == 1);
			}
		}
    }
    SECTION("Three") {
    	REQUIRE(sirens.readSirensFromFile("../tests/thirdTest.txt") == 0);
		sirens.mapSirens();
		WHEN("we have two distinct SIRENs") {
			THEN("unique SIRENs are 1") {
				REQUIRE(sirens.countUnique() == 1);
			}
			THEN("non unique SIRENs are 1") {
				REQUIRE(sirens.countNonUnique() == 1);
			}
		}
    }
}
