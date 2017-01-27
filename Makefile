NAME_SRV = formulaconf-srv

CXXFLAGS = -DRELEASE='"N$Name:  $ "' 
LDFLAGS = -lboost_thread

include ./.makefiles/Make-9.2.2.in
