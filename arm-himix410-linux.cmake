set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译器路径（若已加入环境变量可以直接写名称，未加入写绝对路径）
set(CMAKE_C_COMPILER arm-himix410-linux-gcc)
set(CMAKE_CXX_COMPILER arm-himix410-linux-g++)

# 指定目标系统的查找路径模式
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

