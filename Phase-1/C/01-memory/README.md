# memarena

A simple arena-based memory allocator written in C.

## Goal

Build a memory allocator that manages a region of memory and provides fast allocations with bulk reset/deallocation.

## Build

```bash
make
```

## Planned Features

* [ ] Create and destroy an arena
* [ ] Allocate memory from an arena
* [ ] Reset an arena
* [ ] Handle allocation failures
* [ ] Support alignment
* [ ] Track allocation statistics
* [ ] Support growing arenas
* [ ] Add convenience allocation functions
* [ ] Add debug mode
* [ ] Detect memory corruption
* [ ] Add tests
* [ ] Add stress tests
* [ ] Benchmark against malloc/free
* [ ] Debug with GDB, ASan and UBSan

## Status

In progress.


## ref
-  https://www.gingerbill.org/series/memory-allocation-strategies/