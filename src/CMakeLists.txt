cmake_minimum_required (VERSION 2.6)

add_custom_command (
  OUTPUT
    ${PROJECT_SOURCE_DIR}/emc_nml_raw.cc
  COMMAND java
    ARGS -jar ${PROJECT_SOURCE_DIR}/CodeGenCmdLine.jar
    update_with_name=true
    select_from_all_files=true
    ${PROJECT_SOURCE_DIR}/emcpos.h
    ${PROJECT_SOURCE_DIR}/emctool.h
    ${PROJECT_SOURCE_DIR}/emc_nml.hh
    -o ${PROJECT_SOURCE_DIR}/emc_nml_raw.cc
  DEPENDS emcpos.h emctool.h emc.hh emc_nml.hh
  VERBATIM
  )

add_custom_target (
  generate-msg-cc
  DEPENDS ${PROJECT_SOURCE_DIR}/emc_nml_raw.cc
  )

add_custom_command (
  OUTPUT
    ${PROJECT_SOURCE_DIR}/emc_nml.cc
  COMMAND python3
    ARGS ${PROJECT_SOURCE_DIR}/parent_msg_update.py
  DEPENDS generate-msg-cc emcpos.h emctool.h emc.hh emc_nml.hh
  VERBATIM
  )

add_library(mkmsg SHARED depend_struct.cc shcom.cc emc_nml.cc)

install (TARGETS mkmsg DESTINATION /usr/local/lib
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
              GROUP_READ GROUP_EXECUTE
              WORLD_READ WORLD_EXECUTE)

file (GLOB MK_HEADERS
  "*.h"
  "*.hh")

install (FILES ${MK_HEADERS} DESTINATION /usr/local/include/mk_intf)
