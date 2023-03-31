#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {

protected:
    std::string _type;
    AAnimal();

public:
    AAnimal(const AAnimal &other);
    virtual ~AAnimal();
    AAnimal &operator=(const AAnimal &other);

    std::string getType() const;

    virtual void makeSound() const = 0;
};

#endif