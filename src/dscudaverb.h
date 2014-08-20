#ifndef __DSCUDAVERB_H__
#define __DSCUDAVERB_H__
#define DSCUDAVERB_HISTMAX_GROWSIZE (10)

typedef struct verbAllocatedMem_t {
  void *dst;
  void *src;
  int size;
  struct verbAllocatedMem_t *next;
  struct verbAllocatedMem_t *prev;
} verbAllocatedMem;

typedef struct {
    int device;
} cudaSetDeviceArgs;

typedef struct {
    void *devPtr;
    size_t size;
} cudaMallocArgs;

typedef struct {
    void *dst;
    void *src;
    size_t count;
    enum cudaMemcpyKind kind;  
} cudaMemcpyArgs;

typedef struct {
    int *moduleid;
    char *symbol;
    void *src;
    size_t count;
    size_t offset;
    enum cudaMemcpyKind kind;
} cudaMemcpyToSymbolArgs;

typedef struct {
    void *devPtr;
} cudaFreeArgs;

typedef struct {
    char *name;
    char *strdata;
} cudaLoadModuleArgs;

typedef struct {
    int *moduleid;
    int kid;
    char *kname;
    RCdim3 gdim;
    RCdim3 bdim;
    RCsize smemsize;
    RCstream stream;
    RCargs args;
} cudaRpcLaunchKernelArgs;

typedef struct {
    int *moduleid;
    int kid;
    char *kname;
    int *gdim;
    int *bdim;
    RCsize smemsize;
    RCstream stream;
    int narg;
    IbvArg *arg;
} cudaIbvLaunchKernelArgs;

typedef struct {
    int funcID;
    void *args;
} dscudaVerbHist;


extern void dscudaVerbInit(void);
extern void dscudaVerbAddHist(int, void *);
extern void dscudaVerbClearHist(void);
extern void dscudaVerbRecallHist(void);
extern void dscudaVerbRealloc(void);

#endif // __DSCUDAVERB_H__
