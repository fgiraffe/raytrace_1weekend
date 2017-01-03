
CXX=clang
CXXFLAGS=-I -std=c++14 -stdlib=libc++ -lstdc++
INCLUDES=vec3.h

vec3tests : vec3_tests.cpp $(INCLUDES)
	$(CXX) vec3_tests.cpp $(CXXFLAGS) -o vec3_tests

chap01 : chap01.cpp $(INCLUDES)
	$(CXX) chap01.cpp  $(CXXFLAGS) -o chap01

ch1 : chap01
	@./chap01 > chap1.ppm
	@open -a ToyViewer chap1.ppm

clean :
	@rm -f vec3_tests
	@rm -f chap01
	@rm -f ch2
	@rm -f *.out
	@rm -rf *.dSYM
