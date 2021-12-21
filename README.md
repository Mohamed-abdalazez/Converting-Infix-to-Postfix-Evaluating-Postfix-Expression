## Converting Infix to Postfix and Evaluating Postfix Expression.


**precedence**
1.  ( )
2.  *, /, %
3.  +, -

**Converting Infix to Postfix :** 

 **Examples**

- Infix : ((A * B) + (C / D))  -> Postfix : A B * C D / + 
- Infix : ((A * (B + C)) / D)  -> Postfix : A B C + * D /
- Infix : (A * (B + (C / D)))  -> Postfix : A B C D / + *
- Infix : A * B + C / D        -> Postfix : A B * C D /+ 
- Infix : A * (B + C) / D      -> Postfix : A B C + * D / 
- Infix : A * (B + C / D)      -> Postfix : A B C D / + *



**Sample input :** 
(7 - 8 / 2 / 2) * (( 7 - 2) * 3 - 6)

**output :** 
7 8 2 / 2 / - 7 2 - 3 * 6 - * 

Its value is : 45


**Run Program**

**Type an infix expression and press Enter**

(7 - 8 / 2 / 2) * (( 7 - 2) * 3 - 6 )

**The Postfix form is**

7 8 2 / 2 / - 7 2 - 3 * 6 - *  

**Its value is :** 45


### More Explanation

[![0001.jpg](https://i.postimg.cc/W49gVgzJ/0001.jpg)](https://postimg.cc/2qZVFq4z)

[![0002.jpg](https://i.postimg.cc/9F3TcWm1/0002.jpg)](https://postimg.cc/XX8X86yy)

[![0003.jpg](https://i.postimg.cc/RCt6sj7t/0003.jpg)](https://postimg.cc/fkwRkqgW)

