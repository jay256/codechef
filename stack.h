typedef struct{
  int *elements;
  int elemSize;
  int logLength;
  int allocLength;
}stack;

int newStack(stack *s,int elemSize);
void disposeStack(stack *s);
bool isEmpty(const stack *s);
int push(stack *s, int *elemAddr);
int pop(stack *s,int *elemAddr);
