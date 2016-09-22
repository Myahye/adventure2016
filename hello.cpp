#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
        puts("Hello, World!");

        string line;
        ifstream myfile ("../example.txt");
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
