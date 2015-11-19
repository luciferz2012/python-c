#include "module1.h"

#include <ifcengine.h>

int64_t openModel(char* fileName, char* schemaName){
	return sdaiOpenModelBN(0, fileName, schemaName);
};

void closeModel(int64_t model){
	sdaiCloseModel(model);
};