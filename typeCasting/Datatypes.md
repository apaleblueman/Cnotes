# Datypes and their "signdness" 

---
Different varibales have different data types that we assign to them.

In C some basic datatypes are int, char, float, short, long etc.

<table>
    <tr>
        <td>Datatype</td>
        <td>size</td>
    </tr>
<tr>
    <td>Char</td>
    <td>1 byte(8 bits)</td>
</tr>
<tr>
    <td>Short</td>
    <td>2 bytes(16 bits)</td>
</tr>
<tr>
    <td>Int</td>
    <td>4 bytes(32 bits)</td>
</tr>
<tr>
    <td>long long int</td>
    <td>8 byte(64 bits)</td>
</tr>
</table>


## Signed and unsigned variables
---
> * Unsigned variables in case of int cannot represent negative numbers 
> * Signed variables, such as those used for integers (int), utilize the leftmost bit of a 32-bit representation to denote the sign (negative or positive), thereby enabling the representation of negative numbers as well. However, this approach introduces asymmetry in the range of representable values. While positive numbers range from 0 to 231−1231−1, the inclusion of the sign bit reduces the range of representable values by half. Consequently, the total number of integers we can represent is decreased due to the presence of one bit reserved for sign representation.

Here are the common types, their bit length, their signedness, and the associated size.

    C Data Type: char
        Signed/Unsigned: Signed
        Bit Length: 8 bits
        Minimum Value: -128
        Maximum Value: 127

    C Data Type: unsigned char
        Signed/Unsigned: Unsigned
        Bit Length: 8 bits
        Minimum Value: 0
        Maximum Value: 255

    C Data Type: short
        Signed/Unsigned: Signed
        Bit Length: 16 bits
        Minimum Value: -32,768
        Maximum Value: 32,767

    C Data Type: unsigned short
        Signed/Unsigned: Unsigned
        Bit Length: 16 bits
        Minimum Value: 0
        Maximum Value: 65,535

    C Data Type: int
        Signed/Unsigned: Signed
        Bit Length: 16 or 32 bits
        Minimum Value: -2,147,483,648 (32-bit)
        Maximum Value: 2,147,483,647 (32-bit)

    C Data Type: unsigned int
        Signed/Unsigned: Unsigned
        Bit Length: 16 or 32 bits
        Minimum Value: 0
        Maximum Value: 4,294,967,295 (32-bit)

    C Data Type: long
        Signed/Unsigned: Signed
        Bit Length: 32 bits
        Minimum Value: -2,147,483,648
        Maximum Value: 2,147,483,647

    C Data Type: unsigned long
        Signed/Unsigned: Unsigned
        Bit Length: 32 bits
        Minimum Value: 0
        Maximum Value: 4,294,967,295

    C Data Type: long long
        Signed/Unsigned: Signed
        Bit Length: 64 bits
        Minimum Value: -9,223,372,036,854,775,808
        Maximum Value: 9,223,372,036,854,775,807

    C Data Type: unsigned long long
        Signed/Unsigned: Unsigned
        Bit Length: 64 bits
        Minimum Value: 0
        Maximum Value: 18,446,744,073,709,551,615

    C Data Type: float
        Bit Length: 32 bits
        Minimum Value: ~ -3.4 x 10^38
        Maximum Value: ~ 3.4 x 10^38

    C Data Type: double
        Bit Length: 64 bits
        Minimum Value: ~ -1.7 x 10^308
        Maximum Value: ~ 1.7 x 10^308

> 💡 The use case for specifying the signedness of `char` can be important when you're dealing with character data that may include values outside the range of typical printable ASCII characters (which range from 0 to 127). 

> 1. **Extended Character Sets**: If you're working with character data that includes characters from extended character sets, such as ISO-8859-1 or UTF-8, you may encounter characters with values beyond 127. In such cases, if your `char` is signed and you're dealing with characters whose values are negative (in the range -128 to -1), you'll need to use signed `char`.

> 2. **Binary Data**: If you're working with binary data or raw byte data that may include values in the range -128 to 127, specifying signedness can be important for correctly interpreting the data. 

> 3. **Portability**: Specifying the signedness of `char` explicitly can also enhance the portability of your code across different platforms and compilers. By explicitly stating whether `char` is signed or unsigned, you ensure consistent behavior regardless of the default signedness of `char` on a particular platform.

In many cases, especially when dealing with typical text processing and ASCII characters, the default signedness of `char` may suffice. However, in scenarios involving extended character sets or binary data, explicit specification of signedness becomes crucial for accurate data handling.