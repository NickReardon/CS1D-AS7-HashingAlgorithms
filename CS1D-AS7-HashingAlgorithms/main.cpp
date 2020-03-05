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

	DoubleHashMap<int, std::string > doubleHash(29);

	doubleHash.insert(make_struct(18, std::string("San Clamente")));
	doubleHash.insert(make_struct(41, std::string("Mission Viejo")));
	doubleHash.insert(make_struct(22, std::string("Laguna Niguel")));
	doubleHash.insert(make_struct(44, std::string("Irvine")));

	//DELETE KEY 18
	doubleHash.remove(18);

	doubleHash.insert(make_struct(58, std::string("Lake Forest")));
	doubleHash.insert(make_struct(32, std::string("San Diego")));
	doubleHash.insert(make_struct(49, std::string("Anaheim")));

	//DELETE KEY 58
	doubleHash.remove(58);

	doubleHash.insert(make_struct(31, std::string("Los Angeles")));
	doubleHash.insert(make_struct(17, std::string("Orange")));
	doubleHash.insert(make_struct(72, std::string("Palms Springs")));
	doubleHash.insert(make_struct(41, std::string("Riverside")));

	//DELETE KEY 49
	doubleHash.remove(49);

	doubleHash.insert(make_struct(19, std::string("Brea")));
	doubleHash.insert(make_struct(60, std::string("Santa Ana")));
	doubleHash.insert(make_struct(35, std::string("Tustin")));
	doubleHash.insert(make_struct(103, std::string("Oceanside")));
	doubleHash.insert(make_struct(11, std::string("La Jolla")));
	doubleHash.insert(make_struct(18, std::string("Del Mar")));
	doubleHash.insert(make_struct(22, std::string("Aliso Viejo")));
	doubleHash.insert(make_struct(49, std::string("Laguna Beach")));

	//DELETE KEY 41
	doubleHash.remove(41);

	doubleHash.insert(make_struct(42, std::string("Vista")));
	doubleHash.insert(make_struct(49, std::string("San Diego")));
	doubleHash.insert(make_struct(99, std::string("San Juan")));
	doubleHash.insert(make_struct(29, std::string("Dana Point")));
	doubleHash.insert(make_struct(88, std::string("El Segundo")));
	doubleHash.insert(make_struct(41, std::string("San Clemente")));
	doubleHash.insert(make_struct(62, std::string("Laguna Hills")));
	
	doubleHash.printAll(cout);

	QuadraticHashMap<int, std::string > quadHash(29);

	quadHash.insert(make_struct(18, std::string("San Clamente")));
	quadHash.insert(make_struct(41, std::string("Mission Viejo")));
	quadHash.insert(make_struct(22, std::string("Laguna Niguel")));
	quadHash.insert(make_struct(44, std::string("Irvine")));

	//DELETE KEY 18
	quadHash.remove(18);

	quadHash.insert(make_struct(58, std::string("Lake Forest")));
	quadHash.insert(make_struct(32, std::string("San Diego")));
	quadHash.insert(make_struct(49, std::string("Anaheim")));

	//DELETE KEY 58
	quadHash.remove(58);

	quadHash.insert(make_struct(31, std::string("Los Angeles")));
	quadHash.insert(make_struct(17, std::string("Orange")));
	quadHash.insert(make_struct(72, std::string("Palms Springs")));
	quadHash.insert(make_struct(41, std::string("Riverside")));

	//DELETE KEY 49
	quadHash.remove(49);

	quadHash.insert(make_struct(19, std::string("Brea")));
	quadHash.insert(make_struct(60, std::string("Santa Ana")));
	quadHash.insert(make_struct(35, std::string("Tustin")));
	quadHash.insert(make_struct(103, std::string("Oceanside")));
	quadHash.insert(make_struct(11, std::string("La Jolla")));
	quadHash.insert(make_struct(18, std::string("Del Mar")));
	quadHash.insert(make_struct(22, std::string("Aliso Viejo")));
	quadHash.insert(make_struct(49, std::string("Laguna Beach")));

	//DELETE KEY 41
	quadHash.remove(41);

	quadHash.insert(make_struct(42, std::string("Vista")));
	quadHash.insert(make_struct(49, std::string("San Diego")));
	quadHash.insert(make_struct(99, std::string("San Juan")));
	quadHash.insert(make_struct(29, std::string("Dana Point")));
	quadHash.insert(make_struct(88, std::string("El Segundo")));
	quadHash.insert(make_struct(41, std::string("San Clemente")));
	quadHash.insert(make_struct(62, std::string("Laguna Hills")));

	quadHash.printAll(cout);

	system("pause");
	return 0;
}