# Structs

> A structure is a block of memory that contains variables of different or same types that represents a logical representation of memory.

## Syntax
`struct name{ `
	`datatype variable;`
	`.
	.
	.
	datype variable;
	}; `

# Special Struct constructors

If we wanted to serialize this data and work on it between two different systems that might have different architectures, there's a chance that the structures may change between these systems. By adding special modifiers to the structures, we can ensure that the structure does not get modified in this way.
To fix this, we can add the **`packed`** attribute.
```
struct __attribute__((__packed__)) mystruct {

    int i;

    char c;

};
```