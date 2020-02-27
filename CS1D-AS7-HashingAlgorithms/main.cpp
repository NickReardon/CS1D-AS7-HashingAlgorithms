/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #7	: Hashing Algorithms
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 03 / 04 / 20
 *****************************************************************************/
#include "main.h"
using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	DoubleHashMap<int, std::string > hashMap(29);

	hashMap.insert(make_struct(18, std::string("San Clamente")));
	hashMap.insert(make_struct(41, std::string("Mission Viejo")));
	hashMap.insert(make_struct(22, std::string("Laguna Niguel")));
	hashMap.insert(make_struct(44, std::string("Irvine")));

	//DELETE KEY 18
	hashMap.remove(18);

	hashMap.insert(make_struct(58, std::string("Lake Forest")));
	hashMap.insert(make_struct(32, std::string("San Diego")));
	hashMap.insert(make_struct(49, std::string("Anaheim")));
	hashMap.insert(make_struct(49, std::string("Anaheim")));

	//DELETE KEY 58
	hashMap.remove(58);

	hashMap.insert(make_struct(31, std::string("Los Angeles")));
	hashMap.insert(make_struct(17, std::string("Orange")));
	hashMap.insert(make_struct(72, std::string("Palms Springs")));
	hashMap.insert(make_struct(41, std::string("Riverside")));

	//DELETE KEY 49
	hashMap.remove(49);

	hashMap.insert(make_struct(19, std::string("Brea")));
	hashMap.insert(make_struct(60, std::string("Santa Ana")));
	hashMap.insert(make_struct(35, std::string("Tustin")));
	hashMap.insert(make_struct(103, std::string("Oceanside")));
	hashMap.insert(make_struct(11, std::string("La Jolla")));
	hashMap.insert(make_struct(18, std::string("Del Mar")));
	hashMap.insert(make_struct(22, std::string("Aliso Viejo")));
	hashMap.insert(make_struct(49, std::string("Laguna Beach")));

	//DELETE KEY 41
	hashMap.remove(41);

	hashMap.insert(make_struct(42, std::string("Vista")));
	hashMap.insert(make_struct(49, std::string("San Diego")));
	hashMap.insert(make_struct(99, std::string("San Juan")));
	hashMap.insert(make_struct(29, std::string("Dana Point")));
	hashMap.insert(make_struct(88, std::string("El Segundo")));
	hashMap.insert(make_struct(41, std::string("San Clemente")));
	hashMap.insert(make_struct(62, std::string("Laguna Hills")));

	hashMap.printAll(cout);

	system("pause");
	return 0;
}