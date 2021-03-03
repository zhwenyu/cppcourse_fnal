.DEFAULT_GOAL := all

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrime                 \
    IsPrimeT                \
    Variables               \
    Arguments               \
    Returns                 \
    IncrT                   \
    Exceptions              \
    StrCmp                  \
    StrCmpT                 \
    Operators               \
    Types                   \
    Consts                  \
    Arrays1                 \
    Equal                   \
    EqualT                  \
    Copy                    \
    CopyT                   \
    Fill                    \
    FillT                   \
    Iterators               \
    Iteration               \
    LocalVariables          \
    Classes                 \
    InstanceVariables       \
    ClassVariables          \
    InstanceMethods         \
    ConstMethods            \
    ClassMethods            \
    OperatorOverloading     \
    Conversions             \
    Complex                 \
    ComplexT                \
    Initializations         \
    RangeIteratorT          \
    RangeT                  \
    Functions               \
    Transform               \
    TransformT              \
    Accumulate              \
    AccumulateT             \
    Arrays2                 \
    FunctionOverloading     \
    UniquePtr               \
    UniquePtrs              \
    Shapes1T                \
    MethodOverriding1       \
    Shapes2T                \
    MethodOverriding2       \
    Shapes3T

%: %.c++
	-cppcheck $< --
	g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++17 -Wall -Weffc++ -Wextra $< -o $@ -lgtest -lgtest_main -pthread

%.c++x: %
	-valgrind ./$<
	gcov -b $<.c++ | grep -A 5 "File '$<.c++'"

all: $(FILES)

clean:
	rm -f *.bin
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

docker:
	docker run -it -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

run: $(FILES:=.c++x)

versions:
	which         astyle
	astyle        --version
	@echo
	dpkg -s       libboost-dev | grep 'Version'
	@echo
	ls -al        /usr/lib/*.a
	@echo
	which         checktestdata
	checktestdata --version
	@echo
	which         cmake
	cmake         --version
	@echo
	which         cppcheck
	cppcheck      --version
	@echo
	which         doxygen
	doxygen       --version
	@echo
	which         g++
	g++           --version
	@echo
	which         gcov
	gcov          --version
	@echo
	which         git
	git           --version
	@echo
	which         make
	make          --version
	@echo
	which         valgrind
	valgrind      --version
	@echo
	which         vim
	vim           --version
