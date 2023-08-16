#pragma once
#ifndef HASH_HPP
#define HASH_HPP

#include <string>

// Hash Class implemented with chaining

#define DEFAULT_TABLE_SIZE 1000

class Hash {
private:
	int table_size;

	struct item {
		int key;
		std::string value;
		item *next;
	};

	item **hash_table;

	int hash_function(int key);
	int check_duplicate(int key);

public:
	Hash();
	~Hash();

	void insert(int key, std::string value);
	void remove(int key);
	std::string search(int key);
	void print_table();
	//void rehash(); // make table 2x bigger
};

#endif