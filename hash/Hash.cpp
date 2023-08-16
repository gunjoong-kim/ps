#include "Hash.hpp"
#include <iostream>

int Hash::hash_function(int key) {
	return key % this->table_size;
}

int Hash::check_duplicate(int key) {
	int index = this->hash_function(key);
	item *tmp = this->hash_table[index];
	while (tmp != nullptr) {
		if (tmp->key == key) {
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

Hash::Hash() : table_size(DEFAULT_TABLE_SIZE) {
	this->hash_table = new item*[this->table_size];
}

Hash::~Hash() {
	for (int i = 0; i < this->table_size; i++) {
		// if there is a linked list at this index
		if (this->hash_table[i] != nullptr) {
			item *tmp = this->hash_table[i];
			while (tmp->next != nullptr) {
				item *tmp2 = tmp->next;
				delete tmp;
				tmp = tmp2;
			}
			delete tmp;
		}
	}
	delete[] this->hash_table;
}

void Hash::insert(int key, std::string value) {
	// check if key is duplicated
	if (this->check_duplicate(key)) {
		std::cout << "Duplicate key: " << key << std::endl;
		return;
	}

	int index = this->hash_function(key);
	item *new_item = new item;
	new_item->key = key;
	new_item->value = value;

	// if there is no linked list at this index
	if (this->hash_table[index] == nullptr) {
		new_item->next = nullptr;
		this->hash_table[index] = new_item;
	} else {
		new_item->next = this->hash_table[index];
		this->hash_table[index] = new_item;
	}
}

void Hash::remove(int key) {
	int index = this->hash_function(key);
	item *target = this->hash_table[index];
	item *prev = target;

	if (target == nullptr) {
		std::cout << "Key not found: " << key << std::endl;
		return;
	}

	// if the target is the first item in the linked list	
	if (target->key == key) {
		this->hash_table[index] = target->next;
		delete target;
		return;
	} else {
		target = target->next;
		while (target != nullptr) {
			if (target->key == key) {
				prev->next = target->next;
				delete target;
				return;
			}
			prev = target;
			target = target->next;
		}
	}
	std::cout << "Key not found: " << key << std::endl;
}

std::string Hash::search(int key) {
	int index = this->hash_function(key);

	if (hash_table[index] == nullptr) {
		std::cout << "Key not found: " << key << std::endl;
		return "";
	}

	item *target = this->hash_table[index];
	while (target != nullptr) {
		if (target->key == key)
			return target->value;
		target = target->next;
	}
	std::cout << "Key not found: " << key << std::endl;
	return "";
}

void Hash::print_table() {
	for (int i = 0; i < this->table_size; i++) {
		if (this->hash_table[i] == nullptr) {
			continue;
		} else {
			std::cout << i << ": ";
			item *tmp = this->hash_table[i];
			while (tmp != nullptr) {
				std::cout << tmp->key << " " << tmp->value << " -> ";
				tmp = tmp->next;
			}
			std::cout << "NULL" << std::endl;
		}
	}
}



