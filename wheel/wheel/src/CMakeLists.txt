
#目标二进制可执行文件的存放位置
#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set (LIBRARY_OUTPUT_PATH        ${PROJECT_SOURCE_DIR}/lib)
set (EXECUTABLE_OUTPUT_PATH ../bin)
set (LIBRARY_OUTPUT_PATH        ../lib)

#链接库路径
#link_directories(${LIBRARY_OUTPUT_PATH})

#编译选项
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

#头文件路径
include_directories ("../include")

#源文件路径
aux_source_directory(. SOURCES)

add_subdirectory(debug11)
add_subdirectory(data_structure)
add_subdirectory(utils)

#指定生成目标 
add_executable(wheels ${SOURCES})

# 添加链接库
target_link_libraries(wheels debug11 data_structure utils)
