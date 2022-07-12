# CMakeList.txt: cpp_sort_dev 的 CMake 專案，在此包含來源及定義
# 專案專屬邏輯。
#
cmake_minimum_required (VERSION 3.19)

set(Python_FIND_VIRTUALENV FIRST) 

find_package(Python 3 REQUIRED 
COMPONENTS Interpreter Development.Module NumPy) # New in cmake 3.19

include_directories(${Python_INCLUDE_DIRS})
link_directories(${Python_LIBRARY_DIRS})
message(STATUS "Python Location: ${Python_INCLUDE_DIRS}")

include_directories(${Python_NumPy_INCLUDE_DIRS})
message(STATUS "NumPy Location: ${Python_NumPy_INCLUDE_DIRS}")

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    # If the package has been found, several variables will
    # be set, you can find the full list with descriptions
    # in the OpenCVConfig.cmake file.
    # Print some message showing some of them
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_libraries(${OpenCV_LIBRARIES})
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else ()
    message(FATAL_ERROR "Could not locate OpenCV")
endif()

find_package(Eigen3 REQUIRED)
if(Eigen3_FOUND)
    get_target_property(EIGEN3_INCLUDE_DIR Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
    #include( ${EIGEN3_USE_FILE} ) #This line not work on windows
    include_directories( ${EIGEN3_INCLUDE_DIR})
    message(STATUS "Eigen3 library status:")
    message(STATUS "    version: ${Eigen3_VERSION}")
    message(STATUS "    include path: ${EIGEN3_INCLUDE_DIR}")
else ()
    message(FATAL_ERROR "Could not locate Eigen3")
endif()

# 將來源新增到此專案的可執行檔。
add_executable (cpp_sort_dev "cpp_sort_dev.cpp" "cpp_sort_dev.h" "tracker.cpp" "track.cpp" "munkres.cpp" "kalman_filter.cpp" "tracker.h" "track.h" "munkres.h" "kalman_filter.h" "utils.h" )

# TODO: 新增測試，並視需要安裝目標。
install(TARGETS cpp_sort_dev DESTINATION "cpp_sort_dev/bin")
