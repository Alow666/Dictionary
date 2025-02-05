#include <iostream>
#include <conio.h>

#include "PerfTrie.h"

int main() {
	PerfTrie* dictionary = new PerfTrie();
	std::string txt;
	char ch1, ch2 = ' ';

	dictionary->insert("cat");
	dictionary->insert("cast");
	dictionary->insert("catch");
	dictionary->insert("rust");
	dictionary->insert("cat");
	dictionary->insert("russia");
	dictionary->insert("really");
	dictionary->insert("recently");


	while (true){
		std::cout << "Choose the action:\n1)Add the word.\n2)Write a word.\n3)Check if there is such a word in the dictionary.\nClick for exit (Tab)." << std::endl;
		std::cout << "\n";

		ch1 = _getch();

		if (ch1  == '1') {
			system("cls");
			std::cout << "Enter the word: ";
			std::cin >> txt;
			dictionary->insert(txt);
			txt = "";
			std::cout << "The word is added!" << std::endl;
			std::cout << "\n";
			continue;
		}
		if (ch1 == '2')
		{
			system("cls");
			std::cout << "Enter the word: "<< std::endl;
			std::string xxx;
			while (true) {
				ch2 = _getch();
				system("cls");
				if (ch2 == '\r')break;
				if(ch2 >= 'a' && ch2 <= 'z') {
					txt += ch2;
					std::cout <<"Enter the word: "<< txt << std::endl;
					xxx = dictionary->searchWordpPefix(txt);
					if (xxx != "-") {
						std::cout << "You want to write: " << dictionary->searchWordpPefix(txt) << std::endl;
					}
				}
			}
			txt = "";
			std::cout << "\n";
			continue;
		}
		if (ch1 == '3') {
			system("cls");
			std::cout << "Enter the word: ";
			std::cin >> txt;
			if (dictionary->search(txt)) {
				std::cout << "The word exists." << std::endl;
			}
			else {
				std::cout << "The word does not exist." << std::endl;
			}
			std::cout << "\n";
			continue;
		}
		if (ch1 == '\t') {
			system("cls");
			break;
		}
	}

	delete dictionary;
	dictionary = nullptr;
	return 0;
}