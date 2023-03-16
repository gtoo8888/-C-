#include <atomic>

class SpinLock {
public:
    SpinLock() : flag(false) {}

    void lock() {
        while (flag.exchange(true, std::memory_order_acquire)) {
            // 自旋等待
        }
    }

    void unlock() {
        flag.store(false, std::memory_order_release);
    }

private:
    std::atomic<bool> flag;
};
