#ifndef CXXDASH__DEFINES_HXX__INCLUDED
#define CXXDASH__DEFINES_HXX__INCLUDED

#if defined(_WIN32)
#define EXPORT_SYMBOL __declspec(dllexport)
#else
#define EXPORT_SYMBOL
#endif

#endif // CXXDASH__DEFINES_HXX__INCLUDED
