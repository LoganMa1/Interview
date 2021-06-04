### Some questions about smart poninter in class!(2021/5/31)
<p>0x1:if a struct or class has poiners in data member, then, I assign the struct or class to a smart pointer, need I write a destructor for the struct or the class? <p>
<p>0x2:what if I has a class with smart pointer in data member, need I write a destructor for it? <p>





### Ideas about it
<p>0x1:in the smart pointer's destructor, it delete the member poiner. It means that it would call the destructor of the member class. So, we just should manage the member class's memory<p>
<p>0x: absolutly need't<p>