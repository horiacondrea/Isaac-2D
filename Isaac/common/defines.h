#pragma once
#include <memory>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#ifdef _WIN32
    // Windows specific
    #define EXPORT_API __declspec(dllexport)
#else
    #define EXPORT_API
#endif

