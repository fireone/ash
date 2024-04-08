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

add_subdirectory( builder )
add_subdirectory( utils )
add_subdirectory( context )
add_subdirectory( event )
add_subdirectory( command )
add_subdirectory( sensors )
add_subdirectory( services )
add_subdirectory( ash )
add_subdirectory( main )
