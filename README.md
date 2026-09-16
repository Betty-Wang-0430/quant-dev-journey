# quant-dev-journey
My learning journey towards quantitative development, including C++, algorithms, trading systems and quantitative programming.

## Week 1 — C++ Foundations & Performance

### Topics covered

- Pointers and references
- `const` and ownership
- RAII and `std::unique_ptr`
- STL containers:
  - `vector`
  - `array`
  - `map`
  - `unordered_map`
  - `set`
- Iterators and standard algorithms
- Lambdas and custom comparators
- Big-O complexity
- Stack vs heap memory
- Contiguous memory and CPU cache locality
- `vector::reserve()`
- `push_back()` vs `emplace_back()`
- Move semantics
- Basic C++ benchmarking

### Mini Project — Limit Order Book

Built a simplified C++ limit order book and matching engine using:

- `unordered_map` for order ID lookup
- `map` for price levels
- `vector` for maintaining time priority within each price level

Implemented:

- Adding buy and sell orders
- Removing orders
- Best bid / best ask
- Price-time priority
- Full order fills
- Partial order fills
- Trade execution
- Basic order-book display

### Performance Experiment

Benchmarked different data structures and memory access patterns.

Example results:

| Operation | Time |
|---|---:|
| `vector` lookup | ~233,711 μs |
| `map` lookup | ~31 μs |
| `unordered_map` lookup | ~6 μs |
| Sequential vector access | ~16,378 μs |
| Random vector access | ~289,170 μs |
| Vector without `reserve()` | ~61,053 μs |
| Vector with `reserve()` | ~33,763 μs |

The experiments demonstrated that performance depends not only on Big-O complexity, but also on memory layout, cache locality, and allocation behaviour.
