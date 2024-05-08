#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "address_book.hpp"

TEST_CASE("entries can be added and removed") {
	address_book ab;

	//Check if name is not present
	CHECK_FALSE(ab.has_entry("Jane Doe"));

	ab.add_entry("Jane Doe");
	//Check if name is present
	CHECK(ab.has_entry("Jane Doe"));

	ab.remove_entry("Jane Doe");
	//Check if name is removed
	CHECK_FALSE(ab.has_entry("Jane Doe"));
}

TEST_CASE("check for name exceptions") {
	address_book ab;
    //Check when non-existent name is removed
	ab.remove_entry("Jane Doe");
	CHECK_FALSE(ab.has_entry("Jane Doe"));
    
	//Check for Error when 0 character entry is added
	CHECK_THROWS(ab.add_entry(""));

	//Check for Error when over 100 character entry is added
	CHECK_THROWS(ab.add_entry(std::string(101,'A')));

	ab.add_entry("Jane Doe");
	REQUIRE(ab.has_entry("Jane Doe"));
    
	//Check if same name is added
    ab.add_entry("Jane Doe");
	CHECK(ab.has_entry("Jane Doe"));
}

TEST_CASE("check ") {
	address_book ab;
    //Check when non-existent name is removed
	
}