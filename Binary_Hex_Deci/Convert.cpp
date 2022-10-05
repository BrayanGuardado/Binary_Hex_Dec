#include "Convert.h"
#include<iostream>
#include<string.h>
using namespace std;

void convertBinaryToDecimal(int inputBinary);
void convertBinaryToHexadecimal(int inputBinary);

void convertHexadecimalToDecimal(string inputHex);
void convertHexadecimalToBinary(string inputHex);

void convertDecimalToBinary(int inputDecimal);
void convertDecimalToHexadecimal(int inputDecimal);

void Convert::run() {

	Convert o;

	while (exit != 2) {

		system("cls");
		cout << "Select the conversion: " << endl;
		cout << "1) Binary" << endl;
		cout << "2) Hexadecimal" << endl;
		cout << "3) Decimal" << endl;
		cout << "Option: ";
		cin >> opc;

		switch (opc) {

		case 1:
			o.binaryConvert();
			break;

		case 2:
			o.hexConvert();
			break;

		case 3:
			o.decimalConvert();
			break;

		default:
			cout << "Select a correct option" << endl;
			break;
		}

		cout << "\n\nDo you want to do another oparation? " << endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		cout << "Option: ";
		cin >> exit;

	}

}

void Convert::binaryConvert() {
	int inputBinary = 0; 
	system("cls");
	cout << "Type the binary number: ";
	cin >> inputBinary;

	//Convert to Decimal
	convertBinaryToDecimal(inputBinary);

	//Convert to Hexadecimal
	convertBinaryToHexadecimal(inputBinary);
}

void convertBinaryToDecimal(int inputBinary) {

	int residue = 0, getDecimal = 0;
	int separateBinary[8] = {};

	for (int i = 0; i < 8; i++) {
		separateBinary[i] = inputBinary % 10;
		inputBinary /= 10;
	}

	for (int i = 7; i >= 0; i--) {
		getDecimal = (residue * 2) + separateBinary[i];
		residue = getDecimal;
	}

	cout << "\nThe Decimal number is: " << getDecimal << endl;

}

void convertBinaryToHexadecimal(int inputBinary) {

	int getHex[500] = {};
	int i = 1, j = 0, obtained, decrement = 0;

	while (inputBinary > 0) {
		obtained = inputBinary % 2;
		decrement = decrement + obtained * i;
		i = i * 2;
		inputBinary = inputBinary / 10;
	}
	i = 0;
	while (decrement != 0) {
		getHex[i] = decrement % 16;
		decrement = decrement / 16;
		i++;
	}

	cout << "The hexadecimal number is: ";
	for (j = i - 1; j >= 0; j--) {
		if (getHex[j] > 9) {
			cout << (char)(getHex[j] + 55) << endl;
		}
		else {
			cout << getHex[j];
		}
	}

}

void Convert::hexConvert() {

	system("cls");
	string inputHex = "";
	cout << "Type the hexadecimal number: ";
	cin >> inputHex;

	//Convert to Decimal
	convertHexadecimalToDecimal(inputHex);

	//Convert to Binary
	convertHexadecimalToBinary(inputHex);
}

void convertHexadecimalToDecimal(string inputHex) {
	
	int lenghtHexadecimal = inputHex.size();
	int obtainDecimal = 0;
	for (int i = 0; i < lenghtHexadecimal; i++) {
		char digit = inputHex[lenghtHexadecimal - 1 - i];

		if (digit >= '0' && digit <= '9') {
			obtainDecimal += (digit - '0') * pow(16, i);
		}
		else {
			obtainDecimal += (digit - 'A' + 10) * pow(16, i);
		}
	}

	cout << "\nThe decimal number is: " << obtainDecimal;

}

void convertHexadecimalToBinary(string inputHex) {

	int i = 0;
	int lenght = inputHex.size();
	char* obtainBinary = new char[lenght + 1];
	std::copy(inputHex.begin(), inputHex.end(), obtainBinary);
	obtainBinary[lenght] = '\0';
	cout << "\n\nThe binary number is: ";
	while (obtainBinary[i]) {
		switch (obtainBinary[i]) {
		case '0': cout << "0000"; break;
		case '1': cout << "0001"; break;
		case '2': cout << "0010"; break;
		case '3': cout << "0011"; break;
		case '4': cout << "0100"; break;
		case '5': cout << "0101"; break;
		case '6': cout << "0110"; break;
		case '7': cout << "0111"; break;
		case '8': cout << "1000"; break;
		case '9': cout << "1001"; break;
		case 'A': cout << "1010"; break;
		case 'B': cout << "1011"; break;
		case 'C': cout << "1100"; break;
		case 'D': cout << "1101"; break;
		case 'E': cout << "1110"; break;
		case 'F': cout << "1111"; break;
		default: cout << "The hexagon number is not correct " << obtainBinary[i];
		}
		i++;
	}

}

void Convert::decimalConvert() {

	int inputDecimal = 0;
	system("cls");
	cout << "Type the decimal number: ";
	cin >> inputDecimal;

	//Convert to Binary
	convertDecimalToBinary(inputDecimal);

	//Convert to Hexadecimal
	convertDecimalToHexadecimal(inputDecimal);

}

void convertDecimalToBinary(int inputDecimal) {
	int convertToBinary[10] = {}, i = 0;

	for (i = 0; i < 9; i++) {
		convertToBinary[i] = inputDecimal % 2;
		inputDecimal /= 2;
	}
	cout << "\nThe binary number is: ";
	for (i = 8; i >= 0; i--) {
		cout << convertToBinary[i];
	}

}

void convertDecimalToHexadecimal(int inputDecimal) {
	int residue = 0, result = 0, getHex[20], i = 0;
	do {

		residue = inputDecimal % 16;
		result = inputDecimal / 16;
		getHex[i] = residue;
		inputDecimal = result;
		i++;

	} while (result > 15);

	getHex[i] = result;

	cout << "\nThe hexdecimal number is: ";

	for (int j = i; j >= 0; j--) {
		if (getHex[j] == 10) {
			cout << "A";
		}
		else if (getHex[j] == 11) {
			cout << "B";
		}
		else if (getHex[j] == 12) {
			cout << "C";
		}
		else if (getHex[j] == 13) {
			cout << "D";
		}
		else if (getHex[j] == 14) {
			cout << "E";
		}
		else if (getHex[j] == 15) {
			cout << "F";
		}
		else {
			cout << getHex[j];
		}
	}

}