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

Buffer::Buffer(){
	location1 = location2 = 0;
	file.open("C:\\Users\\Lea\\Documents\\Studium\\4. Semester\\Systemnahes Programmieren\\Scanner-and-Parser-buffer\\Scanner-and-Parser-buffer\\Buffer_Test.txt", ios::in); //durch das "in" wird Datei gelesen, durch out wird in Datei geschrieben
	file.read(buffer1, BUFFER_SIZE);
	currentBuffer = 1;
	//int line, column;
}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

void Buffer::read() {

    cout << buffer1 <<endl;

    file << "Test Text geht in die Datei" << endl;
    file << "Welcome to Bufferland" << endl;

    file.close();
    cout << "close" << endl;
}


char Buffer::getChar(){
	//Scanner frägt char von Buffer an. Liefert char-weise.
	if(location2 >= BUFFER_SIZE && location1 >= BUFFER_SIZE){
		if(currentBuffer == 2){
			file.read(buffer1, BUFFER_SIZE);
			location1 = location2 = 0;
			currentBuffer = 1;
		}
//		if(currentBuffer == 1){
//			file.read(buffer2, BUFFER_SIZE);
//			location2 = 0;
//			currentBuffer = 2;
//		}
	}
	if (location1 >= BUFFER_SIZE){ 	//zweiter Buffer (wird befüllt sobald B1 voll ist)
			if (location2 == 0){
				file.read(buffer2, BUFFER_SIZE);
			}
			currentBuffer = 2;
			return buffer2[location2++];
		}
//	if(location2 <= BUFFER_SIZE && location1 >= BUFFER_SIZE){
//		currentBuffer = 2;
//		return buffer2[location2++]
//	}

	//Fall: 1024 mal unget char aufruf
	return buffer1[location1++]; //holt Wert aus Array an erster Stelle raus und Zeiger zeigt danach eins rechts weiter

}



