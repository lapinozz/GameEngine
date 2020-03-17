#ifndef BUILD_CONFIG_HPP_INCLUDE
#define BUILD_CONFIG_HPP_INCLUDE

#ifdef NDEBUG
#    define ANTON_DEBUG 0
#else
#    define ANTON_DEBUG 1
#endif

#ifndef ANTON_COMPILER_CLANG
#    define ANTON_COMPILER_CLANG 0
#else
#    define ANTON_COMPILER_CLANG 1
#endif

#ifndef ANTON_COMPILER_GCC
#    define ANTON_COMPILER_GCC 0
#else
#    define ANTON_COMPILER_GCC 1
#endif

#ifndef ANTON_COMPILER_MSVC
#    define ANTON_COMPILER_MSVC 0
#else
#    define ANTON_COMPILER_MSVC 1
#endif

#ifndef ANTON_COMPILER_UNKNOWN
#    define ANTON_COMPILER_UNKNOWN 0
#else
#    define ANTON_COMPILER_UNKNOWN 1
#endif

#ifndef ANTON_WITH_EDITOR
#    define ANTON_WITH_EDITOR 0
#endif

#ifndef GE_BUILD_SHIPPING_DEBUG
#    define GE_BUILD_SHIPPING_DEBUG 0
#endif

#ifndef GE_BUILD_SHIPPING_RELEASE
#    define GE_BUILD_SHIPPING_RELEASE 0
#endif

#ifndef GE_BUILD_SHIPPING
#    define GE_BUILD_SHIPPING GE_BUILD_SHIPPING_DEBUG || GE_BUILD_SHIPPING_RELEASE
#endif

// atl library

#ifndef ANTON_STRING_VIEW_VERIFY_ENCODING
#    define ANTON_STRING_VIEW_VERIFY_ENCODING 1
#endif

#ifndef ANTON_STRING_VERIFY_ENCODING
#    define ANTON_STRING_VERIFY_ENCODING 1
#endif

#ifndef ANTON_ITERATOR_DEBUG
#    define ANTON_ITERATOR_DEBUG 1
#endif

#ifndef ANTON_BOUNDS_CHECKING
#    define ANTON_BOUNDS_CHECKING 0
#endif

// Unicode library

#ifndef ANTON_UNICODE_VALIDATE_ENCODING
#    define ANTON_UNICODE_VALIDATE_ENCODING 1
#endif

#define SERIALIZE_ON_QUIT 0
#define DESERIALIZE 0

#endif // !BUILD_CONFIG_HPP_INCLUDE
