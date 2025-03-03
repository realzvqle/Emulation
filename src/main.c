#include "vm.h"
#include <stdio.h>


#define V0 0
#define V1 1
#define V2 2
#define V3 3
#define V4 4
#define V5 5
#define V6 6
#define V7 7
#define V8 8
#define V9 9
#define V10 10

uint8_t test[] = {
    LOAD, V1, 10,
    ADD, V1, 10,
    PRINT, V1,
    LOAD, V2, 1,
    ADD, V2, 10,
    PRINT, V2
};

typedef struct _REGISTER {
    int regs[10];
} REGISTER;



int main(){
    REGISTER reg;
    int cmdsize = sizeof(test)/sizeof(test[0]);
    for(int i = 0; i < cmdsize; i++){
        if(i % 3 == 0 && i != 1){
            switch(test[i]){
                case LOAD:
                    reg.regs[test[i + 1]] = test[i + 2];
                    break;
                case ADD:
                    reg.regs[test[i + 1]] += test[i + 2];
                    break;
                case SUB:
                    reg.regs[test[i + 1]] -= test[i + 2];
                    break;
                case PRINT:
                    printf("%d\n", reg.regs[test[i + 1]]);
                    break;
                default:
                    printf("INVALID INSTRUCTION %d\n", test[i]);
                    break;
            }
        }
    }
    return 0;
}