# Static memory Allocation

* One might be tempted to use global variables to track certain count/sum of funtion work done after each call of function in a loop or after iterating over a segment or array.
* But it is not generally recommended to use global variables as it is hard to track them and function that is accessing them.
* We can use something called "Static variable/keyword" instead of global variable.
  
## Static Variable

syntax: `static int pseudoGlobalVar`

This initializes the variable in global scope however only the real scope of that variable can access it all while the variable itself retains value just like a global variable would even after function returns its value.

what that means is that it only gets initialized once on first function call while retaining it's local access scope and behaving like a global scope inside a function.
![[./static.png]]
