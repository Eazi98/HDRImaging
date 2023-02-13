LOCAL_PATH := ..
include $(CLEAR_VARS)
OPENCV_INSTALL_MODULES:=on
include C:\ProgramData\MATLAB\SupportPackages\R2022b\3P.instrset\androidopencv.instrset\opencv-android-sdk\sdk\native\jni\OpenCV.mk
LOCAL_MODULE := testSimulink
LOCAL_CFLAGS += -DMODEL=testSimulink -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := ert_main.c testSimulink.c androidinitialize.c driver_android_videodisplay.cpp driver_android_fromapp.c driver_android_toapp.c 
LOCAL_C_INCLUDES += D:/GitRepos/HDRImaging/MATLABImplementationOfImageTMO C:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/android/include D:/GitRepos/HDRImaging/MATLABImplementationOfImageTMO/testSimulink_ert_rtw C:/PROGRA~1/MATLAB/R2022b/extern/include C:/PROGRA~1/MATLAB/R2022b/simulink/include C:/PROGRA~1/MATLAB/R2022b/rtw/c/src C:/PROGRA~1/MATLAB/R2022b/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2022b/rtw/c/ert 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
