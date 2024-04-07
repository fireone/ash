project( main )

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable( ash main.cpp )

target_link_libraries( ash LINK_PUBLIC builder )
target_link_libraries( ash LINK_PUBLIC -pthread )
