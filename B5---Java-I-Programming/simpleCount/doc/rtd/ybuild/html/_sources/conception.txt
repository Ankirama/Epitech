Conception
==========

We did some improvments and use some pattern to try to create a nice calculator.

To understand how each class works, we created a javadoc with each function and variable commented.

* :ref:`rpn`
* :ref:`pattern-mvc`
* :ref:`pattern-observer`
* :ref:`generic-listener`

.. _rpn:

Reverse Polish Notation
-----------------------

The windows Calculator can evaluate priority opertaor except bracket, so we started our project with the same vision:
If the user presses 4 + 3 * 5 then we will do ::

  4 + 3 = 7
  7 * 5 = 35
  result: 35

It was our first approach, very basic.
After some coffees we changed our mind: a ***RPN*** will carry this calculator !

To realise it we had to do *two* things:

* Convert infix notation to `Shunting Yard <https://en.wikipedia.org/wiki/Shunting-yard_algorithm>`_
* Calculate the result from Shunting Yard notation

The 'hardest' part of this RPN was to translate infix notation on the fly: every time the user presses a button, we will convert it in the Shunting yard notation.

After the creation of our array with all tokens we were ready to convert it !

We encountered a problem: exp(ln(x)) was not equal to x.
Indeed, our RPN calculate step by step and it was a mistake!

.. _pattern-mvc:

Model Pattern View Controller (MVC)
-----------------------------------

We created a first version of our simpleCount in one class; it was so disgusting that we decided to change it and we had to structure our code.
We used a ***MVC pattern***, an amazing pattern who splits each logical part in a category:

* GUI in the *View* part
* Data / calculs in the *Model* part
* Allow GUI and Data to communicate: the *Controller* part

.. _pattern-observer:

Observer / Observable Pattern
-----------------------------

We had a problem: how the view can know when it has to update some data from model? With asynchronous check like every XX miliseconds?
It was a bad idea, so we used an other pattern with MVC pattern: Observer pattern.

It allow 2 classes to communicate and notify the other one when there are some updates! It was very useful.

.. _generic-listener:

Generic Listener
----------------

As you know, each button can trigger an action when we press it. To do it, we have to set for each button an *ActionListener*, the class or a child class.

We created a generic child class that allow us to use it and create it with any kind of object and purpose.
To do it, one word : ***reflexivity***.
With the reflexivity we can invoke any method from an object only with its name and its arguments, it's amazing !

It could be a little bit tricky to understand how to use the reflexivity, but its power is incredible! For this project, we just use it a little bit, without any power.
