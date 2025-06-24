project( utils )

add_library( ${PROJECT_NAME} STATIC
   geo_pos.h geo_pos.cpp
   i_map.h
   map.h map.cpp
   point_2d.h
   polygon.h polygon.cpp
   uuid.h uuid.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

