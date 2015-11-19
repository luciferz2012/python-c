#include "module1.h"

#include <stdio.h>

int main() {
	intptr_t id = openModelBN("house.ifc", "ifc2x3_tc1.exp");
	printf("%Id\n%s\n", id, getSPFFHeaderItem(id, 9, 0));
	closeModel(id);
	return 0;
};