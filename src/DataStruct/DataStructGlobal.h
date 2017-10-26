/************************************************************
** Moudle: DataStruct
** Author: YiChao Yang
** Date: 2017-10-16
************************************************************/

#ifndef DATA_STRUCT_GLOBAL_H
#define DATA_STRUCT_GLOBAL_H

#ifdef _WIN32
#   define DECL_EXPORT     __declspec(dllexport)
#   define DECL_IMPORT     __declspec(dllimport)
#   ifdef DATA_STRUCT_LIBRARY
#       define DATA_STRUCT_EXPORT DECL_EXPORT
#   else
#       define DATA_STRUCT_EXPORT DECL_IMPORT
#   endif
#else
#    define DATA_STRUCT_EXPORT
#endif

#endif /* DATA_STRUCT_GLOBAL_H */
