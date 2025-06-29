
+ Because GradeTooHighException by itself is just a type, not an object.
 
+ That’s why we always need virtual destructors if deleting via a base class pointer.

# exceptions are meant to 
+ protect the program from crashing and separate error-handling logic from main code logic.

