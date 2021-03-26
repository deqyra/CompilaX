# Generate script file to copy headers
file(WRITE ${CMAKE_BINARY_DIR}/cp_${CX_DREX_LIB_NAME}_headers.cmake
    "file(COPY ${CMAKE_CURRENT_SOURCE_DIR}
        DESTINATION ${EXPORT_LOCATION}/include/compilax
        FILES_MATCHING
        PATTERN \"*.hpp\"
   )\n"
)

# Build window lib
add_library(${CX_DREX_LIB_NAME} ${STATIC_OR_SHARED}
    ${CX_DREX_SOURCE_FILES}
)

add_dependencies(${CX_DREX_LIB_NAME}
    ${CPPTOOLS_LIB_NAME}_source
)

target_include_directories(${CX_DREX_LIB_NAME} PUBLIC ${EXPORT_LOCATION}/include)
target_link_directories(${CX_DREX_LIB_NAME} PUBLIC ${EXPORT_LOCATION}/lib)

target_link_libraries(${CX_DREX_LIB_NAME} PUBLIC ${CMAKE_DL_LIBS}
    ${CPPTOOLS_LIB_NAME}
)

# Custom target to export window lib
add_custom_target("export_${CX_DREX_LIB_NAME}_lib")
add_dependencies("export_${CX_DREX_LIB_NAME}_lib" ${CX_DREX_LIB_NAME})
add_custom_command(
    TARGET "export_${CX_DREX_LIB_NAME}_lib"
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${CX_DREX_LIB_NAME}> ${EXPORT_LOCATION}/lib
)

# Custom target to export window headers
add_custom_target("export_${CX_DREX_LIB_NAME}_headers")
add_custom_command(
    TARGET "export_${CX_DREX_LIB_NAME}_headers"
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cp_${CX_DREX_LIB_NAME}_headers.cmake
)
