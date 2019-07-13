#include "memPool.h"

#include <stdio.h>
#include <stdlib.h>

namespace mempool {
    // block
    void memBlock::memBlock(void* pData) :
        pPrev(NULL), pNext(NULL), pData(pData){ }


    // list
    void memList::memList(int size) :
        freeB(NULL), usedB(NULL), size(size), next(NULL) { }
    


    // pool
    void memPool::memPoolCreate() {
        printf("memPool Create");
    }
    void* memPool::memPoolMalloc(size_t size) {
        printf("memPool Malloc")
        
        // return value
        void* pRet = nullptr;

        // 如果memPool中没有List
        if (pList == NULL) {
            pList = new memList((int)size);
        }

        memList* pListTmp = pList;
        while(pListTmp->next) {
            if (pList->size <= size) 
                break;
            pListTmp = pListTmp->next;
        }
        if (pListTmp->size > size) {
            memList* pTmp = new memList((int)size);
            pListTmp->next = pTmp;
            pListTmp = pListTmp->next;
        }

        if (pListTmp->freeB == nullptr) {
            // 如果链表中的free为空，则申请内存
            void* pData = (void *)malloc(pListTmp->size);
            memBlock* bTmp = new memBlock(pData);
            
            if (pListTmp->usedB == NULL) {
                // 链表头
                pListTmp->usedB = bTmp;
            } 
            else {
                // 非链表头
                memBlock* pTmp = pListTmp->usedB;
                while(pTmp->pNext) {
                    pTmp = pTmp->pNext;
                }
                pTmp->pNext = bTmp;
                bTmp->pPrev = pTmp;
            }   

            pRet = pData;
        } else {
            // 如果链表中的free不为空
            memBlock* pTmp = pListTmp->freeB;
            while(pTmp->pNext) {
                pTmp = pTmp->pNext;
            }
            if (pTmp->pPrev == NULL) {
                pListTmp->freeB = NULL;
            } else {
                pTmp->pPrev->pNext = NULL;
                pTmp->pPrev = NULL;
            }

            if (pListTmp->usedB == NULL) {
                // 链表头
                pListTmp->usedB = bTmp;
            } 
            else {
                // 非链表头
                memBlock* pTemp = pListTmp->usedB;
                while(pTemp->pNext) {
                    pTemp = pTemp->pNext;
                }
                pTemp->pNext = pTmp;
                pTmp->pPrev = pTemp;
            } 

            pRet = pTmp->pData;
        }

        return pRet;
    }












}