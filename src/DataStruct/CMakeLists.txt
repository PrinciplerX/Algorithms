set (DATA_STRUCT_SRC_FILES
    DataStructGlobal.h
    List.h
    List.c
    Stack.h
    Queue.h)

add_definitions(-DDATA_STRUCT_LIBRARY)

add_library (DataStruct SHARED ${DATA_STRUCT_SRC_FILES})


