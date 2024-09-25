set(SRC
  main.cpp
  mkcaltester.cpp)

set(HEADER
  mkcaltester.h)

add_executable(test-mkcal ${SRC} ${HEADER})

#target_include_directories(test-mkcal PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(test-mkcal
	KF5::CalendarCore
	PkgConfig::MKCAL)


install(TARGETS test-mkcal
	DESTINATION ${CMAKE_INSTALL_BINDIR})

