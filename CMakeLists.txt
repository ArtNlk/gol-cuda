cmake_minimum_required(VERSION 3.20)

project(GOL-cuda)

find_package(CUDA REQUIRED)
find_package(OpenGL REQUIRED)

include(FetchContent)

#GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG 7482de6071d21db77a7236155da44c172a7f6c9e
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

#imgui
FetchContent_Populate(imgui
  URL https://github.com/ocornut/imgui/archive/refs/tags/v1.89.9.zip
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui
)

add_library(imgui STATIC
  imgui/imgui.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_demo.cpp
  imgui/imgui_tables.cpp
  imgui/imgui_widgets.cpp

  imgui/backends/imgui_impl_glfw.cpp
  imgui/backends/imgui_impl_opengl3.cpp
)

target_link_libraries(imgui PUBLIC glfw ${OPENGL_LIBRARIES})

target_include_directories(imgui
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/imgui
  ${CMAKE_CURRENT_LIST_DIR}/imgui/backends
)

add_subdirectory(glad)
add_subdirectory(GOLApp)
add_subdirectory(GOLlib)

target_include_directories(GOLApp PRIVATE ./GOLlib)

target_link_libraries(GOLApp ${OPENGL_LIBRARIES} -static-libgcc -static-libstdc++)
target_link_libraries(GOLApp glad)
target_link_libraries(GOLApp imgui)
target_link_libraries(GOLApp CuGOL)
