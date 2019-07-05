PROJECT(hello)
SET(SRCS
	hello.cpp
	name.cpp
)
ADD_EXECUTABLE(hello ${SRCS})
ADD_EXECUTABLE(foo foo.cpp)
