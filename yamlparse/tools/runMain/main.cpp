#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "model.h"


int main() {
	model testModelParseNpcs;
	std::string path = "../yamlparse/data/shire.yml";
	// pracModel.yamlParseNPC(path);
	testModelParseNpcs.yamlParseAndBuild(path);
	testModelParseNpcs.printAll();
	return 0;
}
