.DEFAULT_GOAL := all

all:

clean:
	cd examples/c++; make clean

config:
	git config -l

init:
	touch README
	git init
	git remote add origin git@gitlab.com:gpdowning/oopl-fnal.git
	git add README
	git commit -m 'first commit'
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	git add examples
	git add makefile
	git add notes
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete            \
    --include "Hello.c++"                  \
    --include "Assertions.c++"             \
    --include "UnitTests1.c++"             \
    --include "UnitTests2.c++"             \
    --include "UnitTests3.c++"             \
    --include "Coverage1.c++"              \
    --include "Coverage2.c++"              \
    --include "Coverage3.c++"              \
    --include "IsPrime.c++"                \
    --include "IsPrimeT.c++"               \
    --include "Variables.c++"              \
    --include "Arguments.c++"              \
    --include "Returns.c++"                \
    --include "Incr.c++"                   \
    --include "IncrT.c++"                  \
    --include "Exceptions.c++"             \
    --include "StrCmp.c++"                 \
    --include "StrCmpT.c++"                \
    --include "Operators.c++"              \
    --include "Types.c++"                  \
    --include "Consts.c++"                 \
    --include "Arrays1.c++"                \
    --include "Equal.c++"                  \
    --include "EqualT.c++"                 \
    --include "Copy.c++"                   \
    --include "CopyT.c++"                  \
    --include "Fill.c++"                   \
    --include "FillT.c++"                  \
    --include "Iterators.c++"              \
    --include "Iteration.c++"              \
    --include "LocalVariables.c++"         \
    --include "Classes.c++"                \
    --include "InstanceVariables.c++"      \
    --include "ClassVariables.c++"         \
    --include "InstanceMethods.c++"        \
    --include "ConstMethods.c++"           \
    --include "ClassMethods.c++"           \
    --include "OperatorOverloading.c++"    \
    --include "Conversions.c++"            \
    --include "Complex.c++"                \
    --include "ComplexT.c++"               \
    --include "Initializations.c++"        \
    --include "RangeIterator.c++"          \
    --include "RangeIteratorT.c++"         \
    --include "Range.c++"                  \
    --include "RangeT.c++"                 \
    --include "Functions.c++"              \
    --include "Transform.c++"              \
    --include "TransformT.c++"             \
    --include "Accumulate.c++"             \
    --include "AccumulateT.c++"            \
    --include "Factorial.c++"              \
    --include "Arrays2.c++"                \
    --include "FunctionOverloading.c++"    \
    --include "UniquePtr.c++"              \
    --include "UniquePtrs.c++"             \
    --include "Shapes1.c++"                \
    --include "Shapes1T.c++"               \
    --include "MethodOverriding1.c++"      \
    --include "Shapes2.c++"                \
    --include "Shapes2T.c++"               \
    --include "MethodOverriding2.c++"      \
    --include "Shapes3.c++"                \
    --include "Shapes3T.c++"               \
    --exclude "*"                          \
    ../../examples/c++/ examples/c++/
	@rsync -r -t -u -v --delete            \
    --include "Shapes1.uml"                \
    --include "Shapes1.svg"                \
    --include "Shapes2.uml"                \
    --include "Shapes2.svg"                \
    --include "Shapes3.uml"                \
    --include "Shapes3.svg"                \
    --exclude "*"                          \
    ../../examples/uml/ examples/uml/
