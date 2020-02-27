/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #7	: Hashing Algorithms
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 03 / 04 / 20
 *****************************************************************************/
#ifndef _DOUBLEHASH_H_
#define _DOUBLEHASH_H_
#include <string>
#include <iostream>
#include <iomanip>

namespace errorType
{
	enum errors
	{
		DEFUALT,
		EMPTY,
		FULL

	};

	std::string errorString[]
	{
		"Error - An error occured",
		"Error - Map is empty",
		"Error - Map is full"
	};
}

enum indexLabel
{
	EMPTY,
	FULL,
	AVAILABLE
};

template <class T_key, class T_value>
struct T_struct
{
	T_key key;
	T_value value;

	enum indexLabel label = EMPTY;

	T_struct<T_key, T_value>()
	{
		key = -1;
		label = EMPTY;
	}

	T_struct<T_key, T_value>(const T_key& key, const T_value& value)
	{
		this->key = key;
		this->value = value;

		label = EMPTY;
	}

	T_struct<T_key, T_value>(const T_struct<T_key, T_value>& rhs)
	{
		this->key = rhs.key;
		this->value = rhs.value;

		this->label = rhs.label;
	}

	T_struct<T_key, T_value>& operator=(const T_struct<T_key, T_value>& rhs)
	{
		this->key = rhs.key;
		this->value = rhs.value;

		this->label = rhs.label;

		return *this;
	}
};

template <class T_key, class T_value>
T_struct<T_key, T_value> make_struct(T_key newKey, T_value newValue)
{
	return T_struct<T_key, T_value>(newKey, newValue);
}



template <class T_key, class T_value>
class DoubleHashMap
{
private:

	T_struct<T_key, T_value>* map;

	int currentSize;
	int capacity;

	// ostream member? Assign it in constructor or method???
	// set to NULL?

protected:

	int DoubleHash(const int givenKey, const int collisionCount) const
	{
		int hashKey;

		int j = collisionCount;
		int k = givenKey;
		int N = capacity;

		/*
		int hk;
		int hk2;

		hk = (k % N);
		hk2 = (k % 13);
		hk2 = 13 - hk2;
		hk2 = j * hk2;

		hashKey = hk + hk2;

		hashKey = hashKey % N;
		*/

		hashKey = ((( k % N ) + (j * (13 - (k % 13))) ) % N);

		return hashKey;
	}

	int DoubleHash(const T_struct<T_key, T_value>& toInsert, const int collisionCount) const
	{
		DoubleHash(toInsert.key, collisionCount);
	}

public:

	DoubleHashMap(const int newCapacity)
	{
		map = new  T_struct<T_key, T_value>[newCapacity];

		currentSize = 0;

		capacity = newCapacity;
	}

	~DoubleHashMap()
	{
		delete[] map;
	}

	void insert(const T_struct<T_key, T_value>& toInsert)
	{
		if (full())
		{
			throw(errorType::FULL, errorType::errorString[FULL], 5);
		}

		int hashKey;

		int collisionCount = 0;
		bool success = false;
		while (success == false)
		{
			hashKey = DoubleHash(toInsert.key, collisionCount);

			if (map[hashKey].label == EMPTY ||
				map[hashKey].label == AVAILABLE)
			{
				success = true;
			}
			else
			{
				collisionCount++;
			}
			
		}

		

		map[hashKey] = toInsert;
		map[hashKey].label = FULL;

		currentSize++;

		printAll(std::cout);

	}

	void remove(const T_key key)
	{
		if (empty())
		{
			throw(errorType::FULL, errorType::errorString[FULL], 5);
		}

		int hashKey;

		int collisionCount = 0;
		bool success = false;
		while (success == false)
		{
			hashKey = DoubleHash(key, collisionCount);

			if (map[hashKey].label == FULL && map[hashKey].label == AVAILABLE)
			{
				if (map[hashKey].key == key)
				{
					success = true;
				}
				else
				{
					collisionCount++;
				}
			}

			if (map[hashKey].label == FULL)
			{
				
			}
		}

		map[hashKey] = T_struct<T_key, T_value>();
		map[hashKey].label = AVAILABLE;

		currentSize--;

		printAll(std::cout);

	}

	bool full()
	{
		return currentSize >= capacity;
	}

	bool empty()
	{
		return currentSize == 0;
	}

	int size()
	{
		return currentSize;
	}

	void printAll(std::ostream& output)
	{
		if (empty())
		{
			throw(errorType::EMPTY, errorType::errorString[EMPTY], 5);
		}

		output << "  Index  |  Key  |  Value" << '\n'
			<< "_________|_______|___________________________________"
			<< '\n';

		for (int i = 0; i < capacity; i++)
		{
			output << std::right
				<< " [" << std::setw(5) << i << "] | "
				<< ' ' << std::setw(4) << map[i].key << " |"
				<< std::left
				<< ' ' << map[i].value
				<< '\n';
		}
		output << "\n\n";
	}
};


#endif //!_DOUBLEHASH_H_