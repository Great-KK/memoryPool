#include <vector>
using namespace std;

namespace mempool {
    // chunk
    typedef struct memUnit {
        int nNext;
        void* pData;
    };

    // block
    typedef struct memBlock {
        int nSize;
        int nFree;
        int nFirst;
        void* pNext;
    };

    // pool
    typedef struct memPool {
        void* pBlock;
        int nUnitSize;
        int nInitSize;
        int nGrowSize;
    };


    



}