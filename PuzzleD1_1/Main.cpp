/*
 * Main.cpp
 *
 *  Created on: Dec 4, 2023
 *      Author: Krzysztof Lukasik
 */

#include <iostream>
#include <fstream> // allows us to work with files


bool isDigit(char c){
	// 0 = 48, 1 = 49 , .. 9 = 57
	return (c <= 57 && c >= 48);
}

int toInt(char c){
	return c - 48;
}

int getLastDigit(std::string s){
	for (int i = s.length()-1; i >= 0; i--) {
		if (isDigit(s[i])){
			return toInt(s[i]);
		}
	}

	return -1;
}

int getFirstDigit(std::string s) {
	for (int i = 0; i < s.length(); i++){
		if (isDigit(s[i])) {
			return toInt(s[i]);
		}
	}

	return -1;
}

int main() {

	// opens a file
	std::ifstream inpFile("input");

	std::string line;

	int sum = 0;

	// getline returns a string of a stream
	while (std::getline(inpFile, line)) {
		sum += 10*getFirstDigit(line) + getLastDigit(line);
	}

	std::cout << sum << std::endl;

	inpFile.close();
}

