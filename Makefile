EXE = main
SRCS =  main.cpp
LIBS = 
CC = g++
CPP = g++
FLAGS = -Wall -O2 -std=gnu++11
CFLAGS = $(FLAGS)
CXXFLAGS = $(FLAGS)
OBJS = $(SRCS:.cpp=.o)
.PHONY = clean

$(EXE): $(OBJS)
	g++ $(LDFLAGS) -o $(EXE) $(OBJS) $(LIBS)

-include $(subst .c,.d,$(SOURCES))
%.d : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -MM -MF $@ -MP $<

clean:
	- rm -f  *~  $(EXE) $(OBJS) *.d

run:
	./$(EXE)
