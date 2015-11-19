%module ifc

%{
/* Includes the header in the wrapper code */
#include "ifcengine.h"
%}
/* Parse the header file to generate wrappers */
/* %include "ifcengine.h" */
int sdaiOpenModelBN(int repository, char* fileName, char* schemaName);
void sdaiCloseModel(int model);
