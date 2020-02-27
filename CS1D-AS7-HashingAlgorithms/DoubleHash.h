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


namespace errorType
{
    enum errors
    {
        DEFUALT,
        ERROR,
        FULL

    };

    std::string errorString[]
    {
        "Error - An error occured",
        "Error - Map is empty",
        "Error - Map is full"
    };
}

template <typename T_value, typename T_key>
struct T_struct
{    
    T_key key;
    T_value value;

    T_struct(const T_key& key, const T_value& value)
    {
        this->key = key;
        this->value = value;
    }


};

enum indexLabels
{
    EMPTY,
    FULL,
    AVAILABLE
};

template <typename T_value, typename T_key>
class DoubleHashMap
{
private:
    T_struct* map;

    int currentSize;
    int capacity;

protected:
    int DoubleHash(const T_struct& toInsert, int collisionCount)
    {
        int hashKey;

        int j = collisionCount;
        int k = toInsert.key;
        int N = 29;

        haskKey = ((k % 29) + (j * (13 - (k % 13))) % N);

        return hashKey;
    }

public:
    DoubleHashMap

};


#endif //!_DOUBLEHASH_H_