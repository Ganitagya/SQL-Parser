#include<iostream>
#include<fstream>
//#include<string.h>
using namespace std;

ofstream myfile;
ifstream yourfile ("inputSQL.txt");

void checkQuery(string);
string genCondition();
void insert_to_select(string);
