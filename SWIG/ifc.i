%module ifc

%{
/* Includes the header in the wrapper code */
#include "ifcengine.h"
%}
/* Parse the header file to generate wrappers */
/* %include "ifcengine.h" */
%include "stdint.i"
int64_t sdaiOpenModelBN(int64_t repository, char* fileName, char* schemaName);
void sdaiCloseModel(int64_t model);