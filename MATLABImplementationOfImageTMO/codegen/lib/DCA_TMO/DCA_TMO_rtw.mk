###########################################################################
## Makefile generated for component 'DCA_TMO'. 
## 
## Makefile     : DCA_TMO_rtw.mk
## Generated on : Tue Jan 17 23:48:18 2023
## Final product: ./DCA_TMO.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = DCA_TMO
MAKEFILE                  = DCA_TMO_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/xuezh/ONEDRI~1/Desktop/Y3TRIM~1/Capstone/FILESF~1/MATLAB~1
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = DCA_TMO_rtw_comp.rsp
CMD_FILE                  = DCA_TMO_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = DCA_TMO.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./DCA_TMO.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=DCA_TMO

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/DCA_TMO/DCA_TMO_data.cpp $(START_DIR)/codegen/lib/DCA_TMO/rt_nonfinite.cpp $(START_DIR)/codegen/lib/DCA_TMO/rtGetNaN.cpp $(START_DIR)/codegen/lib/DCA_TMO/rtGetInf.cpp $(START_DIR)/codegen/lib/DCA_TMO/minOrMax.cpp $(START_DIR)/codegen/lib/DCA_TMO/combineVectorElements.cpp $(START_DIR)/codegen/lib/DCA_TMO/median.cpp $(START_DIR)/codegen/lib/DCA_TMO/quickselect.cpp $(START_DIR)/codegen/lib/DCA_TMO/tvi.cpp $(START_DIR)/codegen/lib/DCA_TMO/mean.cpp $(START_DIR)/codegen/lib/DCA_TMO/interp1.cpp $(START_DIR)/codegen/lib/DCA_TMO/svd.cpp $(START_DIR)/codegen/lib/DCA_TMO/svd1.cpp $(START_DIR)/codegen/lib/DCA_TMO/xnrm2.cpp $(START_DIR)/codegen/lib/DCA_TMO/xdotc.cpp $(START_DIR)/codegen/lib/DCA_TMO/imfilter.cpp $(START_DIR)/codegen/lib/DCA_TMO/ixfun.cpp $(START_DIR)/codegen/lib/DCA_TMO/sort.cpp $(START_DIR)/codegen/lib/DCA_TMO/sortIdx.cpp $(START_DIR)/codegen/lib/DCA_TMO/xaxpy.cpp $(START_DIR)/codegen/lib/DCA_TMO/xrotg.cpp $(START_DIR)/codegen/lib/DCA_TMO/xrot.cpp $(START_DIR)/codegen/lib/DCA_TMO/xswap.cpp $(START_DIR)/codegen/lib/DCA_TMO/ldrImg.cpp $(START_DIR)/codegen/lib/DCA_TMO/DCA_TMO_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = DCA_TMO_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj minOrMax.obj combineVectorElements.obj median.obj quickselect.obj tvi.obj mean.obj interp1.obj svd.obj svd1.obj xnrm2.obj xdotc.obj imfilter.obj ixfun.obj sort.obj sortIdx.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj ldrImg.obj DCA_TMO_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/lib/win64/mingw64/libmwippfilter.lib $(MATLAB_ROOT)/extern/lib/win64/mingw64/libmwimfilter.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/DCA_TMO/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/DCA_TMO/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


DCA_TMO_data.obj : $(START_DIR)/codegen/lib/DCA_TMO/DCA_TMO_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/DCA_TMO/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/DCA_TMO/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/DCA_TMO/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/DCA_TMO/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.obj : $(START_DIR)/codegen/lib/DCA_TMO/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


median.obj : $(START_DIR)/codegen/lib/DCA_TMO/median.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


quickselect.obj : $(START_DIR)/codegen/lib/DCA_TMO/quickselect.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


tvi.obj : $(START_DIR)/codegen/lib/DCA_TMO/tvi.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/DCA_TMO/mean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


interp1.obj : $(START_DIR)/codegen/lib/DCA_TMO/interp1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/DCA_TMO/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd1.obj : $(START_DIR)/codegen/lib/DCA_TMO/svd1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/DCA_TMO/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/DCA_TMO/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/DCA_TMO/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ixfun.obj : $(START_DIR)/codegen/lib/DCA_TMO/ixfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/DCA_TMO/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/DCA_TMO/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/DCA_TMO/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/DCA_TMO/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/DCA_TMO/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/DCA_TMO/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ldrImg.obj : $(START_DIR)/codegen/lib/DCA_TMO/ldrImg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


DCA_TMO_rtwutil.obj : $(START_DIR)/codegen/lib/DCA_TMO/DCA_TMO_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


