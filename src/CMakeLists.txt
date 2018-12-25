cmake_minimum_required (VERSION 2.6)

add_custom_command (
  OUTPUT
    ${PROJECT_SOURCE_DIR}/emc_nml.cc
  COMMAND java
    ARGS -jar ${PROJECT_SOURCE_DIR}/CodeGenCmdLine.jar
    update_with_name=true
    select_from_all_files=true
    ${PROJECT_SOURCE_DIR}/emcpos.h
    ${PROJECT_SOURCE_DIR}/emctool.h
    ${PROJECT_SOURCE_DIR}/emc_nml.hh
    -o ${PROJECT_SOURCE_DIR}/emc_nml.cc
  DEPENDS emcpos.h emctool.h emc.hh emc_nml.hh
  VERBATIM
  )

add_custom_target (
  generate-msg-cc
  DEPENDS ${PROJECT_SOURCE_DIR}/emc_nml.cc
  )

add_library(mkmsg SHARED depend_struct.cc modal_state.cc shcom.cc emc.cc)
add_dependencies (mkmsg generate-msg-cc)
