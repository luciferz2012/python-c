#include "module1.h"

#include <stdio.h>

int main() {
	int64_t id = openModel("house.ifc", "ifc2x3_tc1.exp");
	printf("%I64d\n", id);
	closeModel(id);
	return 0;
};