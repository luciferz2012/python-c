#include "module1.h"

#include <ifcengine.h>

intptr_t openModelBN(char* fileName, char* schemaName){
    return sdaiOpenModelBN(0, fileName, schemaName);
};

void closeModel(intptr_t model){
    sdaiCloseModel(model);
};

char* getSPFFHeaderItem(intptr_t model, intptr_t itemIndex, intptr_t itemSubIndex){
    char* value = 0;
    GetSPFFHeaderItem(model, itemIndex, itemSubIndex, sdaiSTRING, &value);
    return value;
};

intptr_t* getEntityExtentBN(intptr_t model, char* entityName){
    return sdaiGetEntityExtentBN(model, entityName);
};

intptr_t getMemberCount(intptr_t* aggregate){
    return sdaiGetMemberCount(aggregate);
};

intptr_t getAggrElement(intptr_t* aggregate, intptr_t elementIndex){
    intptr_t value = 0;
    engiGetAggrElement(aggregate, elementIndex, sdaiINSTANCE, &value);
    return value;
};

char* getAttrBN(intptr_t instance, char* attributeName){
    char* value = 0;
    sdaiGetAttrBN(instance, attributeName, sdaiSTRING, &value);
    return value;
};