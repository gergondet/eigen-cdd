#
# Copyright 2021 CNRS-UM LIRMM, CNRS-AIST JRL
#

set(CDD eigen-cdd::CDD)
if(NOT TARGET ${CDD})
  find_path(CDD_INCLUDE_DIR
    NAMES cdd/cdd.h
    HINTS ${CDD_PREFIX}
  )
  find_library(CDD_LIBRARY
    NAMES cdd
    PATHS ${CDD_PREFIX}
  )
  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(CDD DEFAULT_MSG CDD_LIBRARY CDD_INCLUDE_DIR)
  mark_as_advanced(CDD_INCLUDE_DIR CDD_LIBRARY)
  if(CDD_FOUND)
    add_library(${CDD} INTERFACE IMPORTED GLOBAL)
    set_target_properties(${CDD} PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES ${CDD_INCLUDE_DIR}
      INTERFACE_LINK_LIBRARIES ${CDD_LIBRARY}
    )
  else()
    message(FATAL_ERROR "Could not find CDD on your system, maybe it's missing or you should provide the CDD_PREFIX variable")
  endif()
endif()
