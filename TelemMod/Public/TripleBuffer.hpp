#pragma once

#include <atomic>
#include <tuple>

class TripleBufferBase
{
protected:
    constexpr static const char8_t dirty[12]        = {0, 0, 0, 0,  0,  0, 1, 1, 1, 1,  1,  1};
    constexpr static const char8_t reader_index[12] = {0, 0, 1, 1,  2,  2, 0, 0, 1, 1,  2,  2};
    constexpr static const char8_t writer_index[12] = {1, 2, 2, 0,  0,  1, 1, 2, 2, 0,  0,  1};
    constexpr static const char8_t next_reader[12]  = {0, 1, 2, 3,  4,  5, 5, 2, 1, 4,  3,  0};
    constexpr static const char8_t next_writer[12]  = {7, 6, 9, 8, 11, 10, 7, 6, 9, 8, 11, 10};
};

template<typename T>
class TripleBuffer : private TripleBufferBase
{
    T buffers[3] = {};
    std::atomic_char8_t state;
public:
    std::tuple<bool, T&> read() {
        bool flipped = false;
        if (dirty[state.load()]) {
            char8_t curr = state.load();
            char8_t next = next_reader[curr];
            while (!state.compare_exchange_strong(curr, next))
                next = next_reader[curr];
            flipped = true;
        }
        return {flipped, buffers[reader_index[state.load()]]};
    }

    T& write() {
        return buffers[writer_index[state.load()]];
    }

    void flip() {
        char8_t curr = state.load();
        char8_t next = next_writer[curr];
        while (!state.compare_exchange_strong(curr, next))
            next = next_writer[curr];
    }
};