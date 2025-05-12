CXX ?= g++

CXX += -std=c++23


CXXFLAGS := -Wall -Wextra -Werror -Og


.PHONY: all clean


all: example


clean:
	$(RM) *.o
	$(RM) example


example: example.o example_foo_lib.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LIBS)



.PHONY: company
company: compile_flags.txt

compile_flags.txt: Makefile
	printf "%s" "$(CPPFLAGS)" | xargs -n1 | sort -u > compile_flags.txt
	$(CPP) -xc++ /dev/null -E -Wp,-v 2>&1 | sed -n 's,^ ,-I,p' >> compile_flags.txt
