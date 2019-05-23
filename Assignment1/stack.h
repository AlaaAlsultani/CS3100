typedef enum {false, true} bool;

typedef char valueT;

typedef struct _nodeT {
    valueT value;
    struct _nodeT *next;
} nodeT;

typedef struct {
  nodeT *head;
} stackT;

// You will need to create a file named stack.c
// and write the following functions in it.
stackT *NewStack(void);
void Push(stackT *stack, valueT value);
valueT Pop(stackT *stack);
void EmptyStack(stackT *stack);
void FreeStack(stackT *stack);
bool IsEmpty(stackT *stack);
