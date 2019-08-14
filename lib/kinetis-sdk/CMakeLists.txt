# Subdirectory make files

# Subdirectory source files
list(APPEND kinets_firmware_SOURCES
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/components/serial_manager/serial_manager.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/components/serial_manager/serial_port_uart.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/components/uart/lpuart_adapter.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers/fsl_common.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers/fsl_clock.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers/fsl_gpio.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers/fsl_lpuart.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers/fsl_smc.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/system_MK82F25615.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/utilities/debug_console/fsl_debug_console.c"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/utilities/str/fsl_str.c"
)

# Subdirectory include paths
list(APPEND kinets_firmware_INCLUDES
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/CMSIS/Include"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/components/serial_manager"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/components/uart"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/drivers"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/utilities"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/utilities/debug_console"
"${CMAKE_CURRENT_LIST_DIR}/kinetis-sdk-mk8x/devices/MK82F25615/utilities/str"
)
