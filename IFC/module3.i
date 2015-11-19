%module module3
%{
#include "module1.h"
%}

#if defined(SWIGWORDSIZE64)
typedef long int		int64_t;
#else
typedef long long int	int64_t;
#endif

#if defined(WIN64)
typedef int64_t			intptr_t;
#else
typedef int				intptr_t;
#endif

%include "module1.h"