# CPU / Memory 퍼포먼스 튜닝

## CPU는 어디서 많이 쓸까?

-   async-profiler
-   perf
-   eBPF
    -   runqslower
    -   perf sched
-   사례
    -   context switching
    -   jemalloc pairing heap
    -   hypervisor CPU steal

## 메모리는 어디서 많이 쓸까?

-   heap dump
-   GC
-   container request memory
    -   RSS
    -   inode
-   mmap
-   clear cache

## 절약해보자

-   gzip, zstd
    -   threshold
-   Avro
-   Protobuf
-   schema를 어떻게 잘 운영할지 고려
