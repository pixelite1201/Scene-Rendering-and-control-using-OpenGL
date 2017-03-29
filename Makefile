CC = g++
CFLAGS = -Wall
PROG = music_box

SRCS = main.cpp imageloader.cpp 

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut -lGL
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS) -lGLU

clean:
	rm -f $(PROG)
