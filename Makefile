##############################################################################
# 	    Makefile for Vis Tech Library 
#
#          Han-Wei Shen - hwshen@nas.nasa.gov
#
#
##############################################################################

##############################################################################
# GLOBAL COMPILER FLAGS
##############################################################################

include Global.defs

##############################################################################
# LOCAL COMPILER FLAGS
##############################################################################
# NOTE: BLUTE: -ptv option screws up the make depend rule,
#            : it prepends "tv" before each filename. Grrr

LOCAL_FLAGS = -I. 

##############################################################################
# LIBRARY DEFINES
##############################################################################

LIB   = libisosurf.a

LIB_O = vtIsoSurf.o triangulator.o 

LIB_C = $(LIB_O:.o=.C) 
LIB_H = vtIsoSurf.h triangulator.h  

$(LIB): $(LIB_O) $(LIB_H)
	-@ $(CPLUSPLUS) $(GLBL_FLAGS) $(LOCAL_FLAGS) $(LIB_O)
	$(AR) $(ARFLAGS) $(LIB) $(LIB_O) 
	$(RANLIB) $(LIB)

##############################################################################

.C.o:
	g++ -c $<

isomain: $(LIB_O) isomain.o 
	g++ -o isomain isomain.o libisosurf.a

##############################################################################
# Standard rules: clean, co, install
##############################################################################

c: clean
clean: 
	touch ii_files $(APP) $(LIB) junk.o
	/bin/rm -fr ii_files $(LIB) *.o
	cd Sweep; $(MAKE) clean


