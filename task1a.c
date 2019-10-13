#include "coursework.c"
#include "linkedlist.c"

// typedef struct linkedList{
//     struct element * head;  // head pointer of the linked list
//     struct element * tail;  // tail pointer of the linked list
// }LinkedList;

// generates a number jobs (struct process) stored in a linked list
void generateProLL(struct element ** head, struct element ** tail);

int main(){
    struct element * top = NULL;
    struct element * last = NULL;
    generateProLL(&top, &last);
    printf("Hello");
    printf("Hello again");  // change
    return 0;
}

void generateProLL(struct element ** head, struct element ** tail){
    for(int i = 0; i < NUMBER_OF_JOBS; i++){
        // 创建一个elemet的指针 data域放process
        struct process * temp = generateProcess();  // ***此处有内存产生

        addLast(temp, head, tail);

        printf("process id = %d\n", ((struct process *)((*tail)->pData))->iProcessId);
    }
}

