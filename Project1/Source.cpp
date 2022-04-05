/*
*	Author:	CS
*	Date:	2022_03_17	YYYY_MM_DD
*	
*	As in the question, a map is used to store words along with their count as inputted.
*	A copy of the map is made from a vector of pairs which is sorted using std::sort and an inline function, then outputted.
* 
*	I admit I tried making a second map with the int as key but values with the same count would be overwritten.
*	Associative containers define their own data structure, but vector may be sorted.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
void print_map(std::map<std::string, int>& words) {
	std::vector<std::pair<int, std::string>> vect;
	for (const auto& temp : words)
		vect.push_back({ temp.second, temp.first });

	std::sort(vect.begin(), vect.end(), [](std::pair<int, std::string> a, std::pair<int, std::string> b) { return a.first < b.first; });

	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i].first << ": " << vect[i].second << std::endl;
}

int main() {
	int max_words = 8;
	std::cout << "Enter a series of words, there must be "<< max_words <<" different:\n";
	std::map<std::string, int> words;
	for (std::string s; std::cin >> s && words.size() < max_words; )
		++words[s];

	print_map(words);

	return 0;
}