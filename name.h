#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name {
private:
    std::string last;
    std::string first;
public:
    Name();
    ~Name();
    Name(const Name&);
    Name(const std::string& last,const std::string& first);

    void setLast(std::string& last);
    void setFirst(std::string& first);

    std::string toString() const;
    std::string toUpper() const;
    std::string getLast();
    std::string getFirst();

    Name& operator = (const Name&);

    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator > (const Name&)  const;
    bool operator >= (const Name&) const;
    bool operator < (const Name&)  const;
    bool operator <= (const Name&) const;

    friend std::istream& operator >> (std::istream&,Name&);
    friend std::ostream& operator << (std::ostream&,const Name&);
};

#endif // NAME_H_INCLUDED
