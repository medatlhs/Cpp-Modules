
+ Because GradeTooHighException by itself is just a type, not an object.
 
+ That’s why we always need virtual destructors if deleting via a base class pointer.

# exceptions are meant to 
+ protect the program from crashing and separate error-handling logic from main code logic.

# std::exception basically provides:

    The virtual what() method that returns an error message (a const char*), which you can override in derived classes.

    A common base type so all standard exceptions share the same interface and can be caught in a uniform way.

Because of this:

    You can catch exceptions by reference or pointer to std::exception (or any derived class), letting you handle many kinds of errors in one place.

    All standard exceptions carry an error message accessible via what().

    Custom exceptions can also inherit from std::exception to fit into this system smoothly.

So the main points are:

    Standardization: They all derive from std::exception for consistent handling.

    Polymorphism: You can catch them via base class reference or pointer.

    Message: what() provides the error details, which you can override in your own exceptions if you make them.
