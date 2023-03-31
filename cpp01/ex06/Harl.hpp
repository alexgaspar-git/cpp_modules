#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {

public:
    void complainFilter(std::string const &level);
    Harl();

private:
    void (Harl::*_functions[4])();
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    static std::string _levels[4];
    int get_level_index (std::string const &level);

};

#endif