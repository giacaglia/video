/*
 * MATLAB Compiler: 4.18.1 (R2013a)
 * Date: Fri Apr 26 13:47:47 2013
 * Arguments: "-B" "macro_default" "-B" "csharedlib:libsegmentImage" "-W"
 * "lib:libsegmentImage" "-T" "link:lib" "segmentImage.m" 
 */

#ifndef __libsegmentImage_h
#define __libsegmentImage_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libsegmentImage
#define PUBLIC_libsegmentImage_C_API __global
#else
#define PUBLIC_libsegmentImage_C_API /* No import statement needed. */
#endif

#define LIB_libsegmentImage_C_API PUBLIC_libsegmentImage_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libsegmentImage
#define PUBLIC_libsegmentImage_C_API __declspec(dllexport)
#else
#define PUBLIC_libsegmentImage_C_API __declspec(dllimport)
#endif

#define LIB_libsegmentImage_C_API PUBLIC_libsegmentImage_C_API


#else

#define LIB_libsegmentImage_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libsegmentImage_C_API 
#define LIB_libsegmentImage_C_API /* No special import/export declaration */
#endif

extern LIB_libsegmentImage_C_API 
bool MW_CALL_CONV libsegmentImageInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libsegmentImage_C_API 
bool MW_CALL_CONV libsegmentImageInitialize(void);

extern LIB_libsegmentImage_C_API 
void MW_CALL_CONV libsegmentImageTerminate(void);



extern LIB_libsegmentImage_C_API 
void MW_CALL_CONV libsegmentImagePrintStackTrace(void);

extern LIB_libsegmentImage_C_API 
bool MW_CALL_CONV mlxSegmentImage(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_libsegmentImage_C_API bool MW_CALL_CONV mlfSegmentImage(mxArray* name_of_file);

#ifdef __cplusplus
}
#endif
#endif
