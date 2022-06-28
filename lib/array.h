#pragma once

namespace lib {
template <typename T, size_t _size>
class array
{
public:
	array()
	{
		this->the_array = new T[_size];
		for (size_t i = 0; i < _size; ++i) 
			this->the_array[i] = 0;
	}

	array(const array& other)
	{
		if (this != &other)
		{
			this->the_array = new T[other.size()];
			for (size_t i = 0; i < other.size(); ++i)
				(*this)[i] = other[i];
		}
	}

	array(array&& other)
	{
		this->the_array = other.the_array;
		other.the_array = nullptr;
	}

	~array()
	{
		if (this->the_array != nullptr) 
			delete[] this->the_array;
	}

	const T& operator[](size_t idx) const 
	{
		return this->the_array[idx];
	}

	T& operator[](size_t idx) 
	{
		return this->the_array[idx];
	}

	array& operator=(const array& other) 
	{
		if (this != &other)
			delete[] this->the_array;
		for (size_t i = 0; i < other.size(); ++i)
			(*this)[i] = other[i];
		return *this;
	}

	array& operator=(array&& other)
	{
		if (this != &other) 
		{
			delete[] this->the_array;
			this->the_array = other.the_array;
			other.the_array = nullptr;
		}
		return *this;
	}

	size_t size() const 
	{
		return _size;
	}
private:
	T* the_array = nullptr;
};
} // end namespace lib
