## Converting-Infix-to-Postfix-Evaluating-Postfix-Expression.


**precedence**
1.  ( )
2.  *, /, %
3.  + -

**Converting Infix to Postfix :** 

 **Examples**

- Infix : ((A * B) + (C / D))  -> Postfix : A B * C D / + 
- Infix : ((A * (B + C)) / D)  -> Postfix : A B C + * D /
- Infix : (A * (B + (C / D)))  -> Postfix : A B C D / + *
- Infix : A * B + C / D        -> Postfix : A B * C D /+ 
- Infix : A * (B + C) / D      -> Postfix : A B C + * D / 
- Infix : A * (B + C / D)      -> Postfix : A B C D / + *



**Sample input :** 
7 - (7 - 8 / 2 / 2) * ((7 - 2) * 3 – 6)
**output :** 
7 8 2 / 2 / - 7 2 - 3 * 6 - * 
