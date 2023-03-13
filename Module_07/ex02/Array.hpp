#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array
{
	private:
		T *array;
		int Tsize;

	public:
		Array<T>()
		{
			this->array = NULL;
			this->Tsize = 0;
		}

		Array<T>(unsigned int _size)
		{
			this-> Tsize = _size;
			this-> array = new T[Tsize];
		}

		Array<T>(const Array<T> &copy)
		{
			*this = copy;
		}

		Array<T> &operator=(const Array<T> &source)
		{
			this->Tsize = source.Size();
			this->array = new T[this->Tsize];
			int i = 0;
			while( i < this->Tsize)
			{
				this->array[i]  = source.array[i];
				i++;
			}
			return *this;
		}

		T &operator[](const int i ) const
		{
			if (i >= this->Tsize || i < 0)
				throw std::overflow_error("index is out of bounds");
			return this->array[i];
		}

		~Array<T>()
		{
			if(this->Tsize > 0)
				delete [] this->array;
		}

		int Size() const
		{
			return (this->Tsize);
		}
};

#endif
