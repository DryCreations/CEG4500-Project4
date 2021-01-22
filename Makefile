
OBJECTS=salon-mutfak.o \
	trackball.o \
	main.o

#DEFINES=-DEMULATE_STEREO
DEFINES=
CXX=g++
CXXFLAGS=-g -Wno-deprecated $(DEFINES) -I/usr/X11R6/include -I/usr/local/include -I./src

LIBS=-L/usr/X11R6/lib64 -lglui -lglut -lGLU -lGL -lstdc++ -lXmu -lXi

all: salonmutfak

clean:
	rm $(OBJECTS)
	rm salonmutfak

salonmutfak: $(OBJECTS)
	g++ -g -o salonmutfak $(OBJECTS) $(LIBS)

.SUFFIXES: .cpp

%.o : %.cpp
	g++ -c $(CXXFLAGS) -o $@ $<
