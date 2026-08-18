#include "atomics.hpp"
#include <cassert>
#include <cstdio>

int main() {
    // Test 1: is_done() should return false before done() is called
    {
        completion_t c;
        assert(c.is_done() == false && "is_done should be false after init (semaphore=0)");
    }

    // Test 2: is_done() should return true after done() is called
    {
        completion_t c;
        c.done();
        assert(c.is_done() == true && "is_done should be true after done() (semaphore=1)");
    }

    // Test 3: is_done() should return false after reset()
    {
        completion_t c;
        c.done();
        assert(c.is_done() == true);
        c.reset();
        assert(c.is_done() == false && "is_done should be false after reset()");
    }

    printf("All completion_t::is_done() tests passed.\n");
    return 0;
}
