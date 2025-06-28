project( utils )

add_library( ${PROJECT_NAME} STATIC
   geo_pos.h geo_pos.cpp
   i_map.h
   map.h map.cpp
   point_2d.h
   polygon.h polygon.cpp
   uuid.h uuid.cpp
   grid/grid_cell.h
   grid/grid_map.h grid/grid_map.cpp
   grid/grid_map_builder.h grid/grid_map_builder.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

