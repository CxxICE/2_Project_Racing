#pragma once

#ifdef RACINGDLL_EXPORTS
#define CL_DLL_API __declspec(dllexport)
#else
#define CL_DLL_API __declspec(dllimport)
#endif