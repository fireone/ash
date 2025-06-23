cmake_minimum_required(VERSION 3.27)

project( ash_app )

set( CMAKE_CXX_STANDARD 20 )

################
# Fetch PugiXML

include( FetchContent )

FetchContent_Declare(
    PugiXML
    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG v1.14
)

FetchContent_MakeAvailable( PugiXML ) 

################


#if(BUILD_FOR_DESKTOP)
#    target_compile_definitions(main PRIVATE DESKTOP_RUNTIME)
#elseif(BUILD_FOR_NATIVE)
#    target_compile_definitions(main PRIVATE NATIVE_RUNTIME)
#endif()



add_subdirectory( builder )
add_subdirectory( utils )
add_subdirectory( context )
add_subdirectory( event )
add_subdirectory( command )
add_subdirectory( sensors )
add_subdirectory( services )
add_subdirectory( ash )
if(BUILD_FOR_DESKTOP)
    add_subdirectory( simulator )
endif()
add_subdirectory( main )

