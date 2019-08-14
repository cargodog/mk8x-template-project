# Subdirectory make files

# Subdirectory source files
list(APPEND kinets_firmware_SOURCES
"${CMAKE_CURRENT_LIST_DIR}/board.c"
"${CMAKE_CURRENT_LIST_DIR}/pinmux.c"
"${CMAKE_CURRENT_LIST_DIR}/clock_config.c"
)

# Subdirectory include paths
list(APPEND kinets_firmware_INCLUDES
"${CMAKE_CURRENT_LIST_DIR}"
)