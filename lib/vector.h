#pragma once

namespace lib 
{

template <typename T>
class vector
{
public:
	vector()
	{
		this->growth_factor = 1.1;
		this->capacityptr = this->sizeptr = this->the_array = nullptr;
	}

	vector(const vector& other)
	{
		if (this != &other) 
		{
			this->the_array = nullptr;
			reserve(other.capacity());
			for (size_t i = 0; i < other.size(); ++i)
				push_back(other[i]);
			this->growth_factor = other.growth_factor;
		}
	}

	vector(vector&& other)
	{
		this->the_array = other.the_array;
		this->sizeptr = other.sizeptr;
		this->capacityptr = other.capacityptr;
		other.sizeptr = other.capacityptr = other.the_array = nullptr;
		this->growth_factor = other.growth_factor;
	}

	~vector()
	{
		delete[] this->the_array;
		this->the_array = nullptr;
		this->sizeptr = nullptr;
		this->capacityptr = nullptr;
	}

	size_t size() const
	{
		return this->sizeptr - this->the_array;
	}

	size_t capacity() const
	{
		return this->capacityptr - this->the_array;
	}

	void reserve(size_t new_capacity)
	{
		if (this->the_array != nullptr )
		{
			if (new_capacity > capacity())
				resize(new_capacity);
		}
		else
		{
			this->the_array = new T[new_capacity];
			this->capacityptr = this->the_array + new_capacity;
			this->sizeptr = this->the_array;
		}
	}

	const T& push_back(const T& element)
	{
		if (this->sizeptr < this->capacityptr && this->sizeptr != nullptr && this->capacityptr != nullptr)
		{
			*this->sizeptr = element;
			++this->sizeptr;
		}
		else 
		{
			resize(new_capacity());
			return push_back(element);
		}
		return element;
	}

	const T& operator[](size_t idx) const
	{
		return this->the_array[idx];
	}

	T& operator[](size_t idx)
	{
		return this->the_array[idx];
	}

	const vector& operator=(const vector& other)
	{
		if (this != &other) 
		{
			delete[] this->the_array;
			this->the_array = nullptr;
			reserve(other.capacity());
			for (size_t i = 0; i < other.size(); ++i)
				push_back(other[i]);
			this->growth_factor = other.growth_factor;
		}
		return *this;
	}

	const vector& operator=(vector&& other)
	{
		if (this != &other)
		{
			delete[] this->the_array;
			this->the_array = other.the_array;
			this->sizeptr = other.sizeptr;
			this->capacityptr = other.capacityptr;
			other.the_array = other.sizeptr = other.capacityptr = nullptr;
			this->growth_factor = other.growth_factor;
		}
		return *this;
	}

	void set_growth_factor(double growth_factor) 
	{
		if (growth_factor > 1)
			this->growth_factor = growth_factor;
	}

	double get_growth_factor() 
	{
		return growth_factor;
	}

private:
	void resize(size_t capacity) 
	{
		T* new_array = new T[capacity];
		this->capacityptr = new_array + capacity;
		for (size_t i = 0; i < this->size(); ++i)
			new_array[i] = this->the_array[i];
		this->sizeptr = new_array + this->size();
		delete[] this->the_array;
		this->the_array = new_array;
	}

	size_t new_capacity()
	{
		size_t s = capacity() * this->growth_factor;
		return s <= capacity() ? capacity() + 1 : s;
	}

	T* the_array;
	T* sizeptr;
	T* capacityptr;
	double growth_factor;
};

} // end namespace lib
