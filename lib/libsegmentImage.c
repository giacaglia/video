/*
 * MATLAB Compiler: 4.18.1 (R2013a)
 * Date: Fri Apr 26 13:47:47 2013
 * Arguments: "-B" "macro_default" "-B" "csharedlib:libsegmentImage" "-W"
 * "lib:libsegmentImage" "-T" "link:lib" "segmentImage.m" 
 */

#include <stdio.h>
#define EXPORTING_libsegmentImage 1
#include "libsegmentImage.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libsegmentImage_C_API
#define LIB_libsegmentImage_C_API /* No special import/export declaration */
#endif

LIB_libsegmentImage_C_API 
bool MW_CALL_CONV libsegmentImageInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(libsegmentImageInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_libsegmentImage_C_API 
bool MW_CALL_CONV libsegmentImageInitialize(void)
{
  return libsegmentImageInitializeWithHandlers(mclDefaultErrorHandler, 
                                               mclDefaultPrintHandler);
}

LIB_libsegmentImage_C_API 
void MW_CALL_CONV libsegmentImageTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_libsegmentImage_C_API 
void MW_CALL_CONV libsegmentImagePrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libsegmentImage_C_API 
bool MW_CALL_CONV mlxSegmentImage(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "segmentImage", nlhs, plhs, nrhs, prhs);
}

LIB_libsegmentImage_C_API 
bool MW_CALL_CONV mlfSegmentImage(mxArray* name_of_file)
{
  return mclMlfFeval(_mcr_inst, "segmentImage", 0, 0, 1, name_of_file);
}

