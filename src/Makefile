#S2LIB=-L ../../google-s2-geometry/build -l google-util-geometry-s2 -l google-base -lgoogle-strings -lgoogle-util-coding -lgoogle-util-math -lgoogle-util-geometry-s2cellid
S2LIB_SRC=../../google-s2-geometry/geometry
S2LIB_BUILD=../../google-s2-geometry/build
#S2LIB_SRC=../../../hg/s2-geometry-library/geometry
#S2LIB_BUILD=../../../hg/s2-geometry-library/geometry
S2LIB= \
${S2LIB_BUILD}/libgoogle-util-geometry-s2.a \
${S2LIB_BUILD}/libgoogle-util-geometry-s2cellid.a \
${S2LIB_BUILD}/libgoogle-util-geometry-s2testing.a \
${S2LIB_BUILD}/libgoogle-util-coding.a \
${S2LIB_BUILD}/libgoogle-util-math.a \
${S2LIB_BUILD}/libgoogle-strings.a \
${S2LIB_BUILD}/libgoogle-base.a \
-l crypto -l ssl 
# -lgflags
#S2LIB= ${S2LIB_BUILD}/libs2.a \

S2INCLUDE=-I ${S2LIB_SRC}


CXXINCLUDE=-I../third_party -I../third_party/boost-numeric-bindings -I/usr/include/atlas $(S2INCLUDE)
CXXOPT=-O3 -g3
CXXFLAGS=-std=c++1y -DBOOST_LOG_DYN_LINK -pthread -Wall -Wextra -Wl,--no-as-needed -pedantic $(CXXINCLUDE) $(CXXOPT)
CXX=g++-4.8
LDFLAGS=-pthread -Wl,--no-as-needed  -lboost_log -lboost_program_options -lboost_system -lboost_thread -llapack -llapack_atlas -lboost_filesystem -lboost_serialization

all: myriaworld 
pch: myriaworld.h.gch
objs: myriaworld.o geo.o read_shapefile_data.o SPHEmesh.o cutting.o country2tria_s2.o

myriaworld: pch objs
	g++ $(LDFLAGS) -o myriaworld geo.o read_shapefile_data.o SPHEmesh.o country2tria_s2.o cutting.o myriaworld.o $(S2LIB)

myriaworld.h.gch: myriaworld.h
	$(CXX) -x c++-header $< $(CXXFLAGS) -c -o $@

geo.o: geo.cpp geo.hpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c geo.cpp -o $@

SPHEmesh.o: SPHEmesh.cpp SPHEmesh.hpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c SPHEmesh.cpp -o $@

read_shapefile_data.o: read_shapefile_data.cpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c read_shapefile_data.cpp -o $@

country2tria.o: country2tria.cpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c country2tria.cpp -o $@

country2tria_s2.o: country2tria_s2.cpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c country2tria_s2.cpp -o $@

cutting.o: cutting.cpp myriaworld.h.gch
	$(CXX) $(CXXFLAGS) -c cutting.cpp -o $@

myriaworld.o: myriaworld.cpp myriaworld.h.gch hash_functions.hpp
	$(CXX) $(CXXFLAGS) -c myriaworld.cpp -o $@

SPHEmesh: SPHEmesh_main.cpp SPHEmesh.cpp SPHEmesh.hpp
	$(CXX) $(CXXFLAGS) SPHEmesh_main.cpp SPHEmesh.cpp -o $@

clean:
	rm -f *.o
	rm -f myriaworld.h.gch
	rm -f myriaworld.hpp.gch
