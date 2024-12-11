#include "CondMutex.h"

CondMutex::CondMutex() {
    mMutex = SDL_CreateMutex();
    mCond = SDL_CreateCond();
}

CondMutex::~CondMutex() {
    SDL_DestroyMutex(mMutex);
    SDL_DestroyCond(mCond);
}

void CondMutex::lock() {
    SDL_LockMutex(mMutex);
}

void CondMutex::unlock() {
    SDL_UnlockMutex(mMutex);
}

void CondMutex::signal() {
    SDL_CondSignal(mCond);
}

void CondMutex::broadcast() {
    SDL_CondBroadcast(mCond);
}

void CondMutex::wait() {
    SDL_CondWait(mCond, mMutex);
}
