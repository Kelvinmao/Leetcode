typedef struct {
    int *arr;
    int top;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->arr=(int *)malloc(maxSize*sizeof(int));
    queue->top=-1;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    int i=0;
    queue->top++;
    for(i=queue->top-1;i>=0;i--)
        queue->arr[i+1]=queue->arr[i];
    queue->arr[0]=element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    queue->top--;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return queue->arr[queue->top];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if(queue->top==-1)
        return true;
    else
        return false;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    queue->top=-1;
}
