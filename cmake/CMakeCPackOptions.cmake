message("=> cpack configuration ...")

set (CPACK_MONOLITHIC_INSTALL 1)
set (CPACK_PACKAGE_NAME ${PROJECT_NAME})
set (CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set (CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set (CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set (CPACK_PACKAGE_VENDOR ${PROJECT_VENDOR})
set (CPACK_PACKAGE_CONTACT ${PROJECT_CONTACT})
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_SUMMARY_DESCRIPTION})
set (CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/README.md")
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set (CPACK_PACKAGE_EXECUTABLES ${PROJECT_NAME})
set (CPACK_CREATE_DESKTOP_LINKS nixview ${PROJECT_NAME})
set (CPACK_PACKAGE_ICON "${PROJECT_SOURCE_DIR}/images/nixview.icns")
set (CPACK_STRIP_FILES TRUE)

if (APPLE)
  set (CPACK_GENERATOR "DragNDrop")
endif (APPLE)

if (UNIX AND NOT APPLE)
  set (CPACK_GENERATOR "RPM")
  set (CPACK_RPM_PACKAGE_SUMMARY ${CPACK_PACKAGE_DESCRIPTION_SUMMARY})
  set (CPACK_RPM_PACKAGE_NAME ${CPACK_PACKAGE_NAME})
  set (CPACK_RPM_PACKAGE_VERSION ${PACK_PACKAGE_VERSION})
  set (CPACK_RPM_PACKAGE_RELEASE 1)
  set (CPACK_RPM_PACKAGE_LICENSE "BSD v.3")
  set (CPACK_RPM_PACKAGE_GROUP "Applications/File")
  set (CPACK_RPM_PACKAGE_VENDOR ${CPACK_PACKAGE_VENDOR}) 
  set (CPACK_RPM_PACKAGE_DESCRIPTION ${CPACK_PACKAGE_DESCRIPTION_SUMMARY})
endif (UNIX AND NOT APPLE)
