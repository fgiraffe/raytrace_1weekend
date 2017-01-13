
CXX=clang
CXXFLAGS=-I -std=c++14 -stdlib=libc++ -lstdc++
INCLUDES=vec3.h sphere.h hitable.h hitable_list.h camera.h

.PHONY: clean all

ch7 : chap07
	@osascript -e 'quit app "ToyViewer"'
	@./chap07 > chap7.ppm
	@open -a ToyViewer chap7.ppm

vec3tests : vec3_tests.cpp $(INCLUDES)
	$(CXX) vec3_tests.cpp $(CXXFLAGS) -o vec3_tests

chap06 : chap06.cpp $(INCLUDES)
	$(CXX) chap06.cpp $(CXXFLAGS) -o chap06

chap05 : chap05.cpp $(INCLUDES)
	$(CXX) chap05.cpp $(CXXFLAGS) -o chap05

chap05plus : chap05plus.cpp $(INCLUDES)
	$(CXX) chap05plus.cpp $(CXXFLAGS) -o chap05plus

chap04 : chap04.cpp $(INCLUDES)
	$(CXX) chap04.cpp $(CXXFLAGS) -o chap04

chap02 : chap02.cpp $(INCLUDES)
	$(CXX) chap02.cpp $(CXXFLAGS) -o chap02

chap01 : chap01.cpp $(INCLUDES)
	$(CXX) chap01.cpp $(CXXFLAGS) -o chap01

ch1 : chap01
	@./chap01 > chap1.ppm
	@open -a ToyViewer chap1.ppm

ch2 : chap02
	@osascript -e 'quit app "ToyViewer"'
	@./chap02 > chap2.ppm
	@open -a ToyViewer chap2.ppm

ch4 : chap04
	@osascript -e 'quit app "ToyViewer"'
	@./chap04 > chap4.ppm
	@open -a ToyViewer chap4.ppm

ch5 : chap05
	@osascript -e 'quit app "ToyViewer"'
	@./chap05 > chap5.ppm
	@open -a ToyViewer chap5.ppm

ch5plus : chap05plus
	@osascript -e 'quit app "ToyViewer"'
	@./chap05plus > chap5plus.ppm
	@open -a ToyViewer chap5plus.ppm

ch6 : chap06
	@osascript -e 'quit app "ToyViewer"'
	@./chap06 > chap6.ppm
	@open -a ToyViewer chap6.ppm

all : ch1 ch2 ch4 ch5 ch5plus ch6 ch7
	@osascript -e 'quit app "ToyViewer"'
	open -a ToyViewer chap7.ppm chap6.ppm chap5plus.ppm chap5.ppm chap4.ppm chap2.ppm chap1.ppm

clean :
	@osascript -e 'quit app "ToyViewer"'
	@rm -f vec3_tests
	@rm -f chap07
	@rm -f chap06
	@rm -f chap05plus
	@rm -f chap05
	@rm -f chap04
	@rm -f chap02
	@rm -f chap01
	@rm -f *.out
	@rm -rf *.dSYM
