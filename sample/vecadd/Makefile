DSCUDACPP        = ../../bin/dscudacpp
CUDAPATH        ?= /usr/local/cuda/
CUDASDKPATH     ?= $(CUDAPATH)/NVIDIA_GPU_Computing_SDK
CUDAINCLUDES     = -I. -I$(CUDAPATH)/include -I$(CUDASDKPATH)/C/common/inc
NVCC            ?= $(CUDAPATH)/bin/nvcc -use_fast_math -O

TARGET = userapp

$(TARGET):	userapp.cu ../../lib/libdscuda.a
	$(DSCUDACPP) -o $@ -I. -i $< -ldscuda -libverbs -lrdmacm -lpthread

$(TARGET)_rpc:	userapp.cu ../../lib/libdscuda_rpc.a
	$(DSCUDACPP) -o $@ -I. -i $< -ldscuda_rpc

$(TARGET)_rpconly:	userapp.cu ../../lib/libdscuda_rpc.a
	$(DSCUDACPP) -DRPC_ONLY=1 -o $@ -I. -i $< -ldscuda_rpc

$(TARGET).o:	userapp.cu ../../lib/libdscuda.a
	$(DSCUDACPP) -c -o $@ -I. -i $< -ldscuda -libverbs -lrdmacm -lpthread

$(TARGET)_local: userapp.cu
	$(NVCC) -o $@ $(CUDAINCLUDES) $< -lcuda


clean:
	rm -rf *.o *.ptx $(TARGET) $(TARGET)_rpc *.linkinfo ./dscudatmp
