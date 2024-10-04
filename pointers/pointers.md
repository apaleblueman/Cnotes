# Pointers in C

Pointers are a fundamental concept in C programming that enable you to directly access and manipulate memory. Understanding pointers is crucial for effective and efficient C programming.

## What is a Pointer?

A pointer is a value that represents a memory address. It points to a specific memory location, allowing you to access and modify the value stored at that location.

### Basic Example

```c
int some_var = 4;
int *pointer_to_some_var = &some_var;
```

> here **&some_var** is address of some_var;

| Symbol        | Function                                          | Example    |
| ------------- | ------------------------------------------------ | ---------- |
| some_variable | Holds the value in certain memory location       | int x = 3; |
| *             | Points to memory address of a certain variable   | int *pX;   |
| &             | Holds the value of address of following variable |  &x;       |


![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/z9qo1m9rg0ew78jqve1w.png)


# references and De-referencing

<table>
    <tr>
        <th>Symbols</th>
        <th>what it holds/means</th>
        <th>Example code</th>
    </tr>
    <tr>
        <td>Declared variable</td>
        <td>Value of the variable</td>
        <td>`int x = 10;`</td>
    </tr>
<tr>
    <td>A pointer</td>
    <td>pointer points to some address</td>
    <td>int *p = &x;</td>
</tr>
<tr>
    <td>Address of the variable(&)</td>
    <td>Memory location of variable(eg:0x7ffe2f14f97c )</td>
        <td>printf("Address of variable x is %p",(void*)&x);</td>
</tr>
<tr>
    <td>Pointers name itself with a preceding &(pointer variable)</td>
    <td>Memory address of pointer (eg:0x7ffe2f14f97c)</td>
<td>printf("Address of pointer p is %p",(void*)p);</td>
</tr>
<tr>
<td>pointer preceded by * (not to be confused with initialization of a pointer type)</td>
<td>Value pointed to by pointer(also called dereferencing)</td>
<td>printf("Value pointed by pointer p is %d",*p);</td>
</tr>
</table>

# Why use Pointers?

Pointers help manage scope issues, especially when using functions with structures. By using pointers, you can access out-of-scope variables in functions through their memory addresses.

We use pointers to access out of scope variables in functions by providing pointer pointing to memory address of such variable (or structure).

## Example
```
#include <stdio.h>
#include <stdbool.h>

struct employee_type
{
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee_type *e){
    e->id = 0;
    e->income=0;
    e->staff=true;
    
    return;
}
int main(){
    struct employee_type Ralph;    
    initialize_employee(&Ralph);

    printf("%d", Ralph.income);
}
```

## Common Pitfalls
* **Uninitialized Pointers**: Always initialize pointers. An uninitialized pointer points to a random memory location, leading to undefined behavior.

* **Dangling Pointers**: Do not use pointers to memory that has been freed or gone out of scope.

* **Pointer Arithmetic**: Be careful with pointer arithmetic to avoid accessing memory out of bounds.
