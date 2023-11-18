#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void printStack(Stack stack) {
    Node* current = stack.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sortStack(Stack* stack) {
    Stack tempStack;
    tempStack.top = NULL;

    while (stack->top != NULL) {
        int temp = pop(stack);
        while (tempStack.top != NULL && tempStack.top->data < temp) {
            push(stack, pop(&tempStack));
        }
        push(&tempStack, temp);
    }

    while (tempStack.top != NULL) {
        push(stack, pop(&tempStack));
    }
}

int main() {
    system ("cls");
    srand(time(0));

    Stack stack;
    stack.top = NULL;

    for (int i = 0; i < 10; i++) {
        int randomNum = rand() % 21 - 10; // генерация случайного числа от -10 до 10
        push(&stack, randomNum);
    }

    printf("First stack:\n");
    printStack(stack);

    sortStack(&stack);

    printf("Sorted stack:\n");
    printStack(stack);

    return 0;
}
