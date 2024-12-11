#ifndef CONDMUTEX_H
#define CONDMUTEX_H
#include <SDL2/SDL.h>

class CondMutex {
public:
    CondMutex();
    ~CondMutex();

    void lock();
    void unlock();
    void signal();
    void broadcast();
    void wait();

private:
    SDL_mutex *mMutex = nullptr;
    SDL_cond *mCond = nullptr;
};

#endif  // CONDMUTEX_H
