typedef struct {
    int *arr;
    int front;
    int rear;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->arr=(int *)malloc(maxSize*sizeof(Stack));
    stack->front=-1;
    stack->rear=0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    stack->front++;
    stack->rear++;
    stack->arr[stack->front]=element;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    stack->front--;
    stack->rear--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return stack->arr[stack->front];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return !stack->rear;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    stack->front=-1;
    stack->rear=0;
}
