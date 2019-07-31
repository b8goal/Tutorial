add_executable(${PROJECT_NAME}
	${MY_SRCS}
)
target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)
