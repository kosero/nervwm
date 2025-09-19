cmake_minimum_required(VERSION 3.15)
project(kiranwm C)

find_package(PkgConfig REQUIRED)

pkg_check_modules(WLROOTS REQUIRED wlroots-0.19 wayland-server)

add_executable(kiranwm src/kiranwm.c)

target_include_directories(kiranwm PRIVATE
    ${WLROOTS_INCLUDE_DIRS}
    inc
)

target_compile_options(kiranwm PRIVATE -g -Werror -DWLR_USE_UNSTABLE)

target_link_libraries(kiranwm PRIVATE ${WLROOTS_LIBRARIES})
target_link_directories(kiranwm PRIVATE ${WLROOTS_LIBRARY_DIRS})

add_definitions(${WLROOTS_CFLAGS_OTHER})
