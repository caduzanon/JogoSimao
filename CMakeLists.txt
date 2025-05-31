cmake_minimum_required(VERSION 3.15)

project(JogoSimao VERSION 1.0)

set(cpp_source_files  src/graphics.cpp src/main.cpp)

set(JogoSimao ${PROJECT_SOURCE_DIR})

add_executable(JogoSimao ${cpp_source_files})

include_directories("${PROJECT_SOURCE_DIR}/SFML/include/SFML" "${PROJECT_SOURCE_DIR}/SFML/include/" 
"${PROJECT_SOURCE_DIR}/include")

#"${PROJECT_SOURCE_DIR}/include/Entities" "${PROJECT_SOURCE_DIR}/include/Entities/Characters"
#"${PROJECT_SOURCE_DIR}/include/Entities/Obstacles" "${PROJECT_SOURCE_DIR}/include/Entities/Projectiles" 
#"${PROJECT_SOURCE_DIR}/include/Entities/Characters/Enemies" "${PROJECT_SOURCE_DIR}/include/Math"
#"${PROJECT_SOURCE_DIR}/include/Managers" "${PROJECT_SOURCE_DIR}/include/States" "${PROJECT_SOURCE_DIR}/include/Levels" 
#"${PROJECT_SOURCE_DIR}/include/Menus" "${PROJECT_SOURCE_DIR}/include/Observers" "${PROJECT_SOURCE_DIR}/include/Defines"

#configure_file(${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h.in ${PROJECT_SOURCE_DIR}/include/Defines/SOURCEDIR.h)

target_link_libraries(JogoSimao PUBLIC ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-graphics-d.a)
target_link_libraries(JogoSimao PUBLIC ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-window-d.a)
target_link_libraries(JogoSimao PUBLIC ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-system-d.a)

install(TARGETS JogoSimao DESTINATION ${PROJECT_SOURCE_DIR}/JogoSimao_Build/bin)
install(FILES "${PROJECT_BINARY_DIR}/include/Defines/SOURCEDIR.h" DESTINATION ${PROJECT_SOURCE_DIR}/JogoSimao_Build/include)