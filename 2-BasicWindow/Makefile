CXX = g++
CXXFLAGS = -std=c++17 -g -Wall


LIBS = -lOgreMain -lOgreBites -lOgreRTShaderSystem -lzzip 
LIB_PATH = -L/run/media/manfredo/机械2T/Github/ogre-1.12.6/build/Dependencies/lib
RPATH = -Wl,-rpath /run/media/manfredo/机械2T/Github/ogre-1.12.6/build/Dependencies/lib
INCLUDE = -I/usr/include/OGRE/ -I/usr/include/OGRE/Bites/ -I/usr/include/OGRE/RTShaderSystem/


TAR = BasicWindow
EXT = 


$(TAR)$(EXT): $(TAR).cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(RPATH) $(LIBS) $(LIB_PATH) $(INCLUDE) 
	
clean:
	-rm $(TAR)$(EXT)