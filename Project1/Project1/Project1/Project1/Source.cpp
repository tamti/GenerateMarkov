#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include<conio.h>

using namespace std;
#define ORDER 3
string textExample = "A carat is a method of measuring the purity of gold. It is the ratio between the principal alloy (Gold) and any added alloys or impurities. Carat is worked out using the following calculation: Carat = 24 times the pure mass divided by the total mass.For example a Krugerrand";


string markovEquetion();

int main() {
	string output;

	//firstly,  "markov" Text generates without any click
	output = markovEquetion();
	cout << output << endl;
	char c;

	//if you want to generate another method click "g"
	while (1) {

		//listen any button to click, "g" means next generate, another character means exit it
		cin >> c;
		if (c == 'g') {
			output = markovEquetion();
			cout << output << endl;
		}else {
			break;
		}
	}
	return 0;
}



string markovEquetion() {
	map  <string, vector<string>> res;
	vector <string> beginVector;
	//for random()
	srand((unsigned)time(0));

	string begin = textExample.substr(0, ORDER);

	//this for means full out map to generate random string
	for (int i = 0; i <= textExample.length() - ORDER - 1; i++) {
		string example = textExample.substr(i, ORDER);
		string exampleNext = textExample.substr(i + ORDER, ORDER);
		res[example].push_back(exampleNext);

		//if we want to generate random begining sentence
		//beginVector.push_back(example);
	}

	//if we want generate random begining sentence
	//int randomSize = beginVector.size();
	//int randomInt = (rand() % randomSize);
	//string current = beginVector[randomInt];

	//for random in c++, (from , to)
	int randomSize;
	int randomInt;

	string current = begin;
	string output = current;

	//it randomize map and append each other, and we receive resultText
	for (int i = 0; i < 100; i++) {
		if (res[current].size() > 0) {
			randomSize = res[current].size();
			randomInt = (rand() % randomSize);
			string continues = res[current].at(randomInt);
			output = output + continues;
			current = output.substr(output.size() - ORDER, ORDER);
		}
	}

	return output;
}