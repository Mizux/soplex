#ifndef __SPXCONFIG_H__
#define __SPXCONFIG_H__

/* If we're building a static lib, a user may define SOPLEX_NO_EXPORT, SOPLEX_EXPORT
   and/or SOPLEX_EXPORT_TEMPLATE beforehand. */
/* #undef SOPLEX_STATIC_LIB */

#if defined(_MSC_VER)
   #ifndef SOPLEX_NO_EXPORT
      #define SOPLEX_NO_EXPORT
   #endif
   #if defined(SOPLEX_STATIC_LIB)
      #ifndef SOPLEX_EXPORT
         #define SOPLEX_EXPORT
      #endif
      #ifndef SOPLEX_EXPORT_TEMPLATE
         #define SOPLEX_EXPORT_TEMPLATE
      #endif
   #elif defined(SOPLEX_BUILD_SHARED_LIB)
      #define SOPLEX_EXPORT __declspec(dllexport)
      #define SOPLEX_EXPORT_TEMPLATE __declspec(dllexport)
   #else
      #define SOPLEX_EXPORT __declspec(dllimport)
      #define SOPLEX_EXPORT_TEMPLATE __declspec(dllimport)
   #endif
#else
   #if defined(SOPLEX_STATIC_LIB) || !defined(SOPLEX_BUILD_SHARED_LIB)
      #ifndef SOPLEX_NO_EXPORT
         #define SOPLEX_NO_EXPORT
      #endif
      #ifndef SOPLEX_EXPORT
         #define SOPLEX_EXPORT
      #endif
      #ifndef SOPLEX_EXPORT_TEMPLATE
         #define SOPLEX_EXPORT_TEMPLATE
      #endif
   #else
      #define SOPLEX_NO_EXPORT __attribute__((visibility("hidden")))
      #define SOPLEX_EXPORT __attribute__((visibility("default")))
      #define SOPLEX_EXPORT_TEMPLATE
   #endif
#endif

#define SOPLEX_HAS_SYSTEM_FMT 0
#define SOPLEX_HAS_BOOST 1
#define SOPLEX_HAS_CPPRAT 0
#define SOPLEX_HAS_CPPMPF 1
#define SOPLEX_HAS_GMP 0
#define SOPLEX_HAS_QUADMATH 0
#define SOPLEX_HAS_MPFR 0
#define SOPLEX_HAS_PAPILO 0
#define SOPLEX_HAS_ZLIB 1

/* Deprecated: */
#if SOPLEX_HAS_GMP
   #define SOPLEX_WITH_GMP
#endif /* SOPLEX_HAS_GMP */

#if SOPLEX_HAS_QUADMATH
   #define SOPLEX_WITH_FLOAT128
#endif /* SOPLEX_HAS_QUADMATH */

#if SOPLEX_HAS_ZLIB
   #define SOPLEX_WITH_ZLIB 
#endif /* SOPLEX_HAS_ZLIB */

#if SOPLEX_HAS_MPFR
   #define SOPLEX_WITH_MPFR
#endif /* SOPLEX_HAS_MPFR */

#if SOPLEX_HAS_PAPILO
   #define SOPLEX_WITH_PAPILO
#endif /* SOPLEX_HAS_PAPILO */

#if SOPLEX_HAS_BOOST
   #define SOPLEX_WITH_BOOST
#endif /* SOPLEX_HAS_BOOST */

#if SOPLEX_HAS_BOOST && SOPLEX_HAS_CPPMPF
   #define SOPLEX_WITH_CPPMPF
#endif /* SOPLEX_HAS_BOOST_CPPMPF */

#define SOPLEX_BUILD_TYPE "Release"
#define SOPLEX_VERSION_MAJOR 9
#define SOPLEX_VERSION_MINOR 0
#define SOPLEX_VERSION_PATCH 0

#endif
