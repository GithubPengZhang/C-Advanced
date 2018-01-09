#if 0
#pragma once
#include <iostream>
using namespace std;

template<class T>
class Ring
{
private:
	int m_pos;
	int m_size;
	T *m_value;

public:
	class iterator;
	
	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(m_size, *this);
	}

public:
	Ring() : m_pos(0), m_size(0), m_value(NULL) {}
	Ring(int size) : m_pos(0), m_size(size), m_value(NULL) {
		m_value = new T[m_size];
	}
	~Ring() {
		delete[] m_value;
	}

	int size() { return m_size; }
	
	void add(T value) {
		m_value[m_pos++] = value;
		if (m_pos == m_size)
			m_pos = 0;
	}

	T &get(int pos) {
		return m_value[pos];
	}

};

template<class T>
class Ring<T>::iterator {
private:
	int m_pos;
	Ring &m_ring;

public:
	iterator() : m_pos(0), m_ring(NULL) {}
	iterator(iterator &other) : m_pos(other.m_pos), m_ring(other.m_ring) {}
	iterator(int pos, Ring &objring) : m_pos(pos), m_ring(objring) {}
	~iterator() {}

public:

	//prefix
	iterator &operator++ () {
		++m_pos;
		return *this;
	}

	//postfix
	iterator operator++(int) {
		iterator temp(*this);
		++(*this);
		return temp;
	}

	T &operator*() {
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator &other) const {
		return m_pos != other.m_pos;
	}


};
#endif