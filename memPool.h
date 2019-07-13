#pragma once

using namespace std;

namespace mempool {
    
    // block 
    // bidirectional // not circle
    class memBlock {
    public:
        memBlock();
        ~memBlock(); 

    public:
        memBlock* pPrev;
        memBlock* pNext;
        void* pData;
    };

    // list
    // unidirectional
    class memList {
    public:
        memList();
        ~memList();

    public:
        memBlock* freeB;
        memBlock* usedB;
        int size;
        memList* next;
    };
    
    // pool
    class memPool {
    public:
        memPool();
        ~memPool();

        void memPoolCreate();

        void* memPoolMalloc();
        void memPoolFree();

    private:
        memList* pList;
    };







}