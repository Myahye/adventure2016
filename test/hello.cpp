#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Test.h"
using namespace std;

int main(int argc, char ** argv)
{
        puts("<<<Start>>>");
        vector<Test> v;



        v.push_back(test)

        Test test (3,4);
        cout << "rect area: " << rect.area() << endl;
        string line;
        ifstream myfile ("./example.txt");
        if (myfile.is_open())
        {
                while ( getline (myfile,line) )
                {
                        cout << line << '\n';
                }
                myfile.close();
        }

        else cout << "Unable to open file";

        return 0;
}
