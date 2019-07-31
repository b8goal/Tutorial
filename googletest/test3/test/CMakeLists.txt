set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

file(GLOB MY_TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(MY_TEST_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(MY_BINARY_NAME "UnitTestExecutor")

add_executable(${MY_BINARY_NAME}
	${MY_TEST_SRCS}
	${MY_SRCS_MINUS_MAIN}
)

target_include_directories(${MY_BINARY_NAME} PUBLIC
	${GTEST_INCLUDE_PATH}
	${CMAKE_SOURCE_DIR}/include
	${MY_TEST_INCLUDE_PATH}
)

target_link_libraries(${MY_BINARY_NAME}
	GTest::GTest
)

add_dependencies(${MY_BINARY_NAME}
	googletest
)
