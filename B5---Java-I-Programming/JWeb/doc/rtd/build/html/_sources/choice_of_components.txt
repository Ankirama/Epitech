Choice of Components
====================

During this project we chose somes components to create our project:

* :ref:`store-data`
* :ref:`render-template`
* :ref:`serve-content`

.. _store-data:

How to store our data
---------------------

We chose to use `SQLite <https://www.sqlite.org>`_ to store our data in a database and JavaBean(like) to get them.

We don't need to install any application to use *SQLite* so it was the easiest choice.

To create our tables we used a *Python script*.

We have some tables to execute store our data:

* User (store user's info like username, email, ...)
* Address (store user's addresses info)
* Payment (store user's payments info)
* Category (store category name like account, ...)
* Product (store product info like name, price, ...)
* Opinion (store user's review for every products)
* Newsletter (store emails to know subscribers)
* News (store news with content, illustration and title)

.. _render-template:

How to render our templates
---------------------------

We had some possibilities to render our templates and we could use some features with Java like:

* JSP
* JSF
* JSTL
* ...

We used JSP to render and create JSP and we used JSTL to allow us powerful attributes.

JSP is like the html file.

To create a good design we used *CSS*, *HTML* and *Javascript*.

.. _serve-content:

How to serve our pages
----------------------

To serve our pages we used simple *servlets* in Java.

Each servlet can have a get request handler and a post request handler.


