#ifndef olokas_HPP
#define olokas_HPP

#include <iostream>
#include <cstdlib>

class olokas {
    protected:
        std::string type_;
    public:
        olokas();
        olokas(const olokas &copy);
        olokas& operator=(const olokas &copy);
        virtual ~olokas();

        virtual void makeSound() const;

        void        setType(std::string &type);
        std::string getType() const ;
};

#endif
