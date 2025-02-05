#include <iostream>

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &copy);
		Array<T>		&operator=(const Array<T> &copy);
		~Array();

		T 				&operator[](unsigned int i);
		const T			&operator[](const unsigned int i) const;
		unsigned int	size() const;

	private:
		T				*_array;
		unsigned int	_size;
};

template <typename T>
Array<T>::Array() : _array(new T[0]()), _size(0) {
	std::cout << "Default constructor has been called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
	std::cout << "Array constructor has been called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]()), _size(other._size) {
	std::cout << "Copy constructor has been called" << std::endl;
	if (other._size == 0)
		return;
	for (unsigned int i = 0; i < other._size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Copy assignment operator overload used" << std::endl;
	if (this != &other && other._size > 0)
	{
		delete[] _array;
		_array = new T[other._size]();
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor has been called" << std::endl;
	delete [] _array;
}
