###
# Seeker Libraries
#
# The 2D ADV Game Frameworks written in C++ and mruby.
#
# @author Aotokitsuruya
###

include(ExternalProject)

# ===> Project: mruby
ExternalProject_Add(
  libmruby
  GIT_SUBMODULES mruby
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/lib/mruby
  INSTALL_DIR ${PROJECT_SOURCE_DIR}/lib/mruby/build/host/lib
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ./minirake
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(libmruby SOURCE_DIR)

set_directory_properties(PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${SOURCE_DIR}/build)
