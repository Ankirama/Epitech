Design Choices
==============

The design was not our first goal, so we tried to do something simple.

We used a design like the `Google Calculator <https://support.google.com/websearch/answer/3284611>`_.

This design is clean but useful, we can use a lot of functions like ***sqrt*** or ***cos***.

Design components
-----------------

* :ref:`jframe`
* :ref:`jpanel`
* :ref:`jbutton`

.. _jframe:

JFrame
~~~~~~

We used a Jframe's child. This class was our main view element, we could use JPanel in this container.

.. _jpanel:

JPanel
~~~~~~

We had only one JPanel with all *JButton* and and *JTextArea* in this one.
This choice was not not first one, indeed, at the begining we started to create an abstract class to allow to create a lot of JPanel's Frame.

We created this abstract class to allow us some flexibility with these panels. We wanted to allow the user to switch between **basic** mode and **scientific** mode.
We stopped it because the google calculator was clean without option like *basic* / *scientific*.

In our Abstract class we used ***GridBagLayout***, this class allow us a lot of flexibility in the layout.
This choice could be good, but we didn't use it enought, it was an over rating.

.. _jbutton:

JButton
~~~~~~~

To create our buttons, we used ***JButton*** with ***GridBagConstraints*** to set its position.
To reproduce the Google Calculator we set each button with a specific background (light grey) and we set the equal button blue.
