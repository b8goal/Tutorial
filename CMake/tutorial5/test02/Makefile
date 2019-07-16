CXX = g++
LIB = test02.a
OBJS = test02.o
CXXFLAGS = -Wall

$(LIB): $(OBJS)
		$(AR) rv $@ $(OBJS)

%.o: %.c
		$(CC) -c $(CXXFLAGS) -I./ $< -o $@

clean:
		rm -f $(OBJS) $(LIB)
