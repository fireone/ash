project( context )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
   context.cpp
   context_registry.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC
                            ${CMAKE_CURRENT_SOURCE_DIR}/.. )

