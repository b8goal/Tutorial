CXX = g++
LIB = test01.a
OBJS = test01.o
CXXFLAGS = -Wall

$(LIB): $(OBJS)
		$(AR) rv $@ $(OBJS)

%.o: %.c
		$(CXX) -c++ $(CXXFLAGS) -I./ $< -o $@

clean:
		rm -f $(OBJS) $(LIB)
