all: KinectVideoHandler

CFLAGS=-fPIC -g -Wall `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`
INCLUDE = -I/usr/local/include/libfreenect -I/Applications/matlab/MATLAB_Compiler_Runtime/v80/extern/include
FREE_LIBS = -L/usr/local/lib -lfreenect -L/Applications/matlab/MATLAB_Compiler_Runtime/v80/runtime/maci64 -L/Users/giu/Documents/GRobot/Code/video/lib -lmwmclmcrrt -lmwmclmcrrt.8.0 -lsegmentImage
CXX = c++

KinectVideoHandler:  KinectVideoHandler.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) $? -o $@  $(LIBS) $(FREE_LIBS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o test
