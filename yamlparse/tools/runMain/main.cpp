#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "model.h"


int main() {
	model pracModel;
	pracModel.yamlParseNPC("../yamlparse/data/shire.yml");
	return 0;
}
