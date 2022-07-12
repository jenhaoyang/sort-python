# CMakeList.txt: 最上層的 CMake 專案檔，執行全域設定
# 並在這裡包含子專案。
#
cmake_minimum_required (VERSION 3.19)

project ("cpp_sort_dev")

cmake_policy(SET CMP0074 NEW)

# 包含子專案。
add_subdirectory ("cpp_sort_dev")
