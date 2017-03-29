/*
 * Buffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"
#include <iostream>
#include <fstream> //wird schon im header file bestimmt, ist nun quasi doppelt

using namespace std;

Buffer::Buffer() {
	location1, location2 = 0;
	file.open("Buffer_test.txt", ios::in); //durch das "in" wird Datei gelesen, durch out wird in Datei geschrieben
	int line, column;
}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

void Buffer::read() {

    file.read(buffer1, BUFFER_SIZE);

    cout << buffer1 <<endl;

    file << "Test Text geht in die Datei" << endl;
    file << "Welcome to Bufferland" << endl;

    file.close();
    cout << "close" << endl;
}

char Buffer::getChar(){
	//Scanner frägt char von Buffer an. Liefert char-weise.
	if (location1 >= BUFFER_SIZE){ 	//zweiter Buffer (wird befüllt sobald B1 voll ist)
		file.read(buffer2, BUFFER_SIZE);
		return buffer2[location2++];
	}

	//TODO



	return buffer1[location1++]; //holt Wert aus Array an erster Stelle raus und Zeiger zeigt danach eins rechts weiter


}

