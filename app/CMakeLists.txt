cmake_minimum_required(VERSION 3.4.1)

# 以下3行追加
include_directories(./opencv320/sdk/native/jni/include) #置いた場所で変わる
add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

add_library( native-lib SHARED src/main/cpp/native-lib.cpp )

find_library( log-lib log )

# lib_opencv追加
target_link_libraries( native-lib lib_opencv ${log-lib} )