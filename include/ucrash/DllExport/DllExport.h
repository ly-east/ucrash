#ifndef UCRASH_DLLEXPORT_H
#define UCRASH_DLLEXPORT_H

#ifdef _WIN32
#ifdef DllExport
#undef DllExport
#endif
#if UCRASH_DLL
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllimport)
#endif // UCRASH_DLL
#else
#ifdef DllExport
#undef DllExport
#endif
#define DllExport
#endif // _WIN32

#endif // UCRASH_DLLEXPORT_H
