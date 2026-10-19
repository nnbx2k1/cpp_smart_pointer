#include <iostream>
#include <string>

namespace smtptr {

    template <class T>
    class shptr{
        private:
         T* ptr{nullptr};
         int* ref_cnt{nullptr};
        public:
         shptr(T* p = nullptr) : ptr{p}{
            if(ptr){
               ref_cnt = new int(1);
            }else{
               ref_cnt = nullptr;
            }

         }

         ~shptr(){
            if(ref_cnt){
                *ref_cnt--;
                if(*ref_cnt == 0){
                    delete ptr;
                    delete ref_cnt;
                    ptr = nullptr;
                    ref_cnt = nullptr;
                }
            }
         }

         shptr(const shptr& other): ptr{other.ptr}, ref_cnt{other.ref_cnt}{
             if(ptr && ref_cnt){
                (*ref_cnt)++;
             }
         }

         shptr& operator=(const shptr& other){

            if (this != other){
                ptr = other.ptr;
                ref_cnt = other.ref_cnt;
                (*ref_cnt)++; 
            }

            return *this;
         }

         T& operator*() const{
            return *ptr;
         }

         T* operator->()const{
            return ptr;
         }

         };


};
    