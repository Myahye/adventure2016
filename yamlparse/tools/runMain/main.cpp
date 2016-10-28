#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Model.h"


int main() {
	Model testModelParse;
	std::string path = "../yamlparse/data/shire.yml";
	// pracModel.yamlParseNPC(path);
	testModelParse.yamlParseAndBuild(path);
	testModelParse.printAll();
	return 0;
}
