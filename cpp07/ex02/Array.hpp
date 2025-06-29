#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <iostream>

template <typename T>
class Array {
private:
	T*		_data;
	size_t	_size;
public:
	Array() : _data(new T[0]), _size(0) {};
	Array(const Array& other) : _data(NULL), _size(0) {
		*this = other;
	}
	Array& operator=(const Array& copy) {
		if (this != &copy) {
			delete[] _data;
			_size = copy._size;
			_data = new T[_size];
			for (size_t i = 0; i < _size; ++i)
				_data[i] = copy._data[i];
		}
		return *this;
	}
	~Array() {
		if (_data == NULL)
			return;
		delete[] _data;
	}

	Array(size_t size) : _data(new T[size]), _size(size) {};

	T& operator[](size_t index) {
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _data[index];
	}
	const T& operator[](size_t index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _data[index];
	}

	size_t size() const {
		return _size;
	}
};

#endif