#pragma once

template <typename T>
class Table {
	vector<string> keys;
	size_t size;
	T* data;
public:
	Table() : keys(nullptr), size(0), data(nullptr) {}
	~Table(){}
	void sortTable() {}
	bool addNote() {}
	bool delNoteByKey(string key) {}
	T& findByKey(string key) {}
};