project( main )

set( CMAKE_VERBOSE_MAKEFILE ON )

add_executable( ash main.cpp )

target_link_libraries( ash LINK_PUBLIC builder )
target_link_libraries( ash LINK_PUBLIC -pthread )

if( BUILD_FOR_DESKTOP )
    add_definitions( -DDESKTOP_RUNTIME )
    find_package( Qt6 REQUIRED COMPONENTS Widgets )
    target_link_libraries( ash PRIVATE Qt6::Widgets )
endif()
