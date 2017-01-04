
CXX=clang
CXXFLAGS=-I -std=c++14 -stdlib=libc++ -lstdc++
INCLUDES=vec3.h

vec3tests : vec3_tests.cpp $(INCLUDES)
	$(CXX) vec3_tests.cpp $(CXXFLAGS) -o vec3_tests

chap05 : chap05.cpp $(INCLUDES)
	$(CXX) chap05.cpp $(CXXFLAGS) -o chap05

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


clean :
	@osascript -e 'quit app "ToyViewer"'
	@rm -f vec3_tests
	@rm -f chap04
	@rm -f chap02
	@rm -f chap01
	@rm -f *.out
	@rm -rf *.dSYM
