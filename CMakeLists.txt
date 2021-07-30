# Copyright 2021 BastouP
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.

cmake_minimum_required(VERSION 3.16)
project(SpigotPlusPlus VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)

add_library(SpigotPlusPlus SHARED)
target_link_options(SpigotPlusPlus PRIVATE -static-libgcc -static-libstdc++)

if(NOT (BUILD_WINDOWS OR BUILD_UNIX OR BUILD_MAC))
    set(BUILD_UNIX True)
endif()

if(BUILD_WINDOWS)
    target_include_directories(SpigotPlusPlus PRIVATE ${SpigotPlusPlus_SOURCE_DIR}/include/windows)
elseif(BUILD_UNIX)
    if(BUILD_x86)
        set_target_properties(SpigotPlusPlus PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
    elseif(BUILD_x86-64)
        set_target_properties(SpigotPlusPlus PROPERTIES COMPILE_FLAGS "-m64" LINK_FLAGS "-m64")
    endif()
    target_include_directories(SpigotPlusPlus PRIVATE ${SpigotPlusPlus_SOURCE_DIR}/include/linux)
elseif(BUILD_MAC)
    target_include_directories(SpigotPlusPlus PRIVATE ${SpigotPlusPlus_SOURCE_DIR}/include/mac)
endif()

add_subdirectory(src/cpp/src)
