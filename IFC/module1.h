#include <stdint.h>

intptr_t openModelBN(char* fileName, char* schemaName);
void closeModel(intptr_t model);
char* getSPFFHeaderItem(intptr_t model, intptr_t itemIndex, intptr_t itemSubIndex);
intptr_t* getEntityExtentBN(intptr_t model, char* entityName);
intptr_t getMemberCount(intptr_t* aggregate);
intptr_t getAggrElement(intptr_t* aggregate, intptr_t elementIndex);
char* getAttrBN(intptr_t instance, char* attributeName);