# Multi Module Programming

> Often we include files such as stdio.h  or fnctl.h to utilize functions such as printf or open. This adds a layer of absctraction to our programs.
They act as an API between our programmer and the functionality.


```
                modules
(file api)(parse api)(networking api)
[               main                ]
    ^                            |
    |                            v
stdin                         stdout

```
> so these modules give abstraction to the programme by acting as api interfaces,however it is easy to write something called "spaghetti" code when using these.

```
                modules
(file api)--->(parse api)(networking api)
    |           |
    v           V
[               main                      ]
    ^                            |
    |                            v
stdin                         stdout

```
> In such code every module may depend on their sibling modules that makes it hard to follow the code logically as it is unorganized.Instead if two modules have dependencies on each other , pack them into a single module. 
!["blob"](./module.png)

