#include <iostream>
#include <string>
#include <vector>
//using namespace std;
using std::vector;

int main_00(){
	vector<double> vec;
	vec.push_back(30.5);
	vec.push_back(40.5);
	vec.push_back(50.5);
	vec.push_back(60.5);
	vec[2] = 55.5;

	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << "\n";
	std::cout << "\n";

	vector<char> vec2;
	vec2.push_back('A');
	vec2.push_back('B');
	vec2.push_back('C');

	for (int i = 0; i < vec2.size(); i++)
		std::cout << vec2[i] << "\n";
	std::cout << "\n";
	
	return 0;
}

#include <fstream>
using std::ifstream;
using std::ofstream;

int main(){
/*	ofstream outFile("data.txt");
	if (!outFile) return 1;
	outFile << 3 << " " << 4 <<"\n";
	outFile << 'A' << " " << 'B' << "\n";
	*/
	ifstream inFile("data.txt");
	int a, b;
	char c, d;
	inFile >> a >> b >> c >> d;
	std::cout << a << " " << b << " " << c << " " << d << "\n";
	return 0;

}